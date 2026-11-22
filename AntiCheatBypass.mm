#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#include <mach-o/loader.h>
#include <string.h>
#include <atomic>
#include <substrate.h>

extern "C" int ptrace(int request, pid_t pid, caddr_t addr, int data);

namespace {
    constexpr const char* kHiddenDylibName = "darkos.dylib";
    constexpr const char* kDecoySystemPath = "/usr/lib/system/libsystem_kernel.dylib";

    std::atomic<bool> g_BypassInitialized{false};

    inline bool IsHiddenImagePath(const char* path) {
        return (path != nullptr &&
                kHiddenDylibName[0] != '\0' &&
                strstr(path, kHiddenDylibName) != nullptr);
    }

    template <typename FnPtr>
    inline void SafeHook(void* target, FnPtr replacement, FnPtr* original) {
        if (target != nullptr && replacement != nullptr && original != nullptr) {
            MSHookFunction(target,
                           reinterpret_cast<void*>(replacement),
                           reinterpret_cast<void**>(original));
        }
    }
}

// 1. PTRACE HOOK (PT_DENY_ATTACH = 31)
static int (*orig_ptrace)(int request, pid_t pid, caddr_t addr, int data) = nullptr;
static int my_ptrace(int request, pid_t pid, caddr_t addr, int data) {
    if (request == 31) {
        return 0;
    }
    return orig_ptrace ? orig_ptrace(request, pid, addr, data) : 0;
}

// 2. SYSCTL HOOK (P_TRACED bayrağını təmizləmə)
static int (*orig_sysctl)(int* name, u_int namelen, void* info, size_t* infosize, void* newinfo, size_t newinfosize) = nullptr;
static int my_sysctl(int* name, u_int namelen, void* info, size_t* infosize, void* newinfo, size_t newinfosize) {
    int ret = orig_sysctl ? orig_sysctl(name, namelen, info, infosize, newinfo, newinfosize) : -1;
    if (ret == 0 && name != nullptr && info != nullptr && namelen >= 3) {
        if (name[0] == CTL_KERN && name[1] == KERN_PROC) {
            if (!infosize || *infosize >= sizeof(struct kinfo_proc)) {
                struct kinfo_proc* kp = static_cast<struct kinfo_proc*>(info);
                kp->kp_proc.p_flag &= ~P_TRACED;
            }
        }
    }
    return ret;
}

// 3. _dyld_get_image_name HOOK
static const char* (*orig_dyld_get_image_name)(uint32_t image_index) = nullptr;
static const char* my_dyld_get_image_name(uint32_t image_index) {
    const char* name = orig_dyld_get_image_name ? orig_dyld_get_image_name(image_index) : nullptr;
    if (IsHiddenImagePath(name)) {
        return kDecoySystemPath;
    }
    return name;
}

// 4. _dyld_get_image_header HOOK
static const struct mach_header* (*orig_dyld_get_image_header)(uint32_t image_index) = nullptr;
static const struct mach_header* my_dyld_get_image_header(uint32_t image_index) {
    const struct mach_header* hdr = orig_dyld_get_image_header ? orig_dyld_get_image_header(image_index) : nullptr;
    if (hdr != nullptr && orig_dyld_get_image_name != nullptr && orig_dyld_get_image_header != nullptr) {
        const char* imgName = orig_dyld_get_image_name(image_index);
        if (IsHiddenImagePath(imgName)) {
            uint32_t count = _dyld_image_count();
            for (uint32_t i = 0; i < count; ++i) {
                const char* candName = orig_dyld_get_image_name(i);
                if (candName && strcmp(candName, kDecoySystemPath) == 0) {
                    const struct mach_header* decoyHdr = orig_dyld_get_image_header(i);
                    if (decoyHdr != nullptr) {
                        return decoyHdr;
                    }
                }
            }
        }
    }
    return hdr;
}

// 5. dladdr HOOK
static int (*orig_dladdr)(const void* addr, Dl_info* info) = nullptr;
static int my_dladdr(const void* addr, Dl_info* info) {
    int res = orig_dladdr ? orig_dladdr(addr, info) : 0;
    if (res != 0 && info != nullptr && IsHiddenImagePath(info->dli_fname)) {
        info->dli_fname = kDecoySystemPath;
    }
    return res;
}

// 6. isatty & getppid HOOK
static int (*orig_isatty)(int fd) = nullptr;
static int my_isatty(int fd) {
    (void)fd;
    return 0;
}

static pid_t (*orig_getppid)(void) = nullptr;
static pid_t my_getppid(void) {
    return 1;
}

__attribute__((constructor))
static void darkos_bypass_init() {
    if (g_BypassInitialized.exchange(true)) {
        return;
    }

    @autoreleasepool {
        SafeHook(reinterpret_cast<void*>(ptrace), my_ptrace, &orig_ptrace);
        SafeHook(reinterpret_cast<void*>(sysctl), my_sysctl, &orig_sysctl);
        SafeHook(reinterpret_cast<void*>(&_dyld_get_image_name), my_dyld_get_image_name, &orig_dyld_get_image_name);
        SafeHook(reinterpret_cast<void*>(&_dyld_get_image_header), my_dyld_get_image_header, &orig_dyld_get_image_header);
        SafeHook(reinterpret_cast<void*>(dladdr), my_dladdr, &orig_dladdr);
        SafeHook(reinterpret_cast<void*>(isatty), my_isatty, &orig_isatty);
        SafeHook(reinterpret_cast<void*>(getppid), my_getppid, &orig_getppid);
    }
}
