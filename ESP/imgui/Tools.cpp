// HMOOD__TG@i_8_f

#include "Tools.h"
#include <cstdint>
#include <mach/mach.h>
#include <mach/vm_region.h>

bool Tools::IsPtrValid(void *addr) {
    if (!addr) {
        return false;
    }

    uintptr_t raw = reinterpret_cast<uintptr_t>(addr);
    if (raw < 0x100000000ULL || raw >= 0x2000000000ULL) {
        return false;
    }

    if ((raw & (sizeof(void *) - 1ULL)) != 0ULL) {
        return false;
    }

    vm_address_t regionAddr = static_cast<vm_address_t>(raw);
    vm_size_t regionSize = 0;
    vm_region_basic_info_data_64_t info;
    mach_msg_type_number_t infoCount = VM_REGION_BASIC_INFO_COUNT_64;
    mach_port_t objectName = MACH_PORT_NULL;

    kern_return_t kr = vm_region_64(
        mach_task_self(),
        &regionAddr,
        &regionSize,
        VM_REGION_BASIC_INFO_64,
        reinterpret_cast<vm_region_info_t>(&info),
        &infoCount,
        &objectName
    );

    if (objectName != MACH_PORT_NULL) {
        mach_port_deallocate(mach_task_self(), objectName);
    }

    if (kr != KERN_SUCCESS) {
        return false;
    }

    uintptr_t start = static_cast<uintptr_t>(regionAddr);
    uintptr_t end = start + static_cast<uintptr_t>(regionSize);
    if (raw < start || (raw + sizeof(void *)) > end) {
        return false;
    }

    return (info.protection & VM_PROT_READ) != 0;
}
