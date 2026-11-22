// HMOOD__TG@i_8_f

#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __APPLE__
#import <Foundation/Foundation.h>
#endif

#if defined(_MSC_VER)
#define ALWAYS_INLINE __forceinline
#else
#define ALWAYS_INLINE __attribute__((always_inline))
#endif

void setup() __attribute__((noinline));
void startAuthentication() __attribute__((noinline));

#ifndef seed
constexpr int seedToInt(char c) { return (c >= '0' && c <= '9') ? (c - '0') : 0; }
static const int seed = seedToInt(__TIME__[7]) +
                        seedToInt(__TIME__[6]) * 10 +
                        seedToInt(__TIME__[4]) * 60 +
                        seedToInt(__TIME__[3]) * 600 +
                        seedToInt(__TIME__[1]) * 3600 +
                        seedToInt(__TIME__[0]) * 36000;
#endif

template <uintptr_t Const>
struct vxCplConstantify {
    enum { Value = Const };
};

constexpr uintptr_t vxCplRandomStep(uintptr_t prev) {
    return (1013904223ULL + 1664525ULL * prev) & 0xFFFFFFFFULL;
}

constexpr uintptr_t vxCplRandom(uintptr_t Id) {
    return (Id > 0) ? vxCplRandomStep(vxCplRandom(Id - 1)) : vxCplRandomStep((uintptr_t)seed);
}

#define vxRANDOM(Min, Max) ((Min) + (vxRAND() % (((Max) - (Min) + 1) > 0 ? ((Max) - (Min) + 1) : 1)))
#define vxRAND() (vxCplConstantify<vxCplRandom(__COUNTER__ + 1)>::Value)

constexpr char vxCplTolower(char Ch) { return (Ch >= 'A' && Ch <= 'Z') ? (Ch - 'A' + 'a') : (Ch); }
constexpr uintptr_t vxCplHashPart3(char Ch, uintptr_t Hash) { return ((Hash << 4) + (uintptr_t)vxCplTolower(Ch)); }
constexpr uintptr_t vxCplHashPart2(char Ch, uintptr_t Hash) { return (vxCplHashPart3(Ch, Hash) ^ ((vxCplHashPart3(Ch, Hash) & 0xF0000000ULL) >> 23)); }
constexpr uintptr_t vxCplHashPart1(char Ch, uintptr_t Hash) { return (vxCplHashPart2(Ch, Hash) & 0x0FFFFFFFULL); }
constexpr uintptr_t vxCplHash(const char* Str) { return (Str && *Str) ? (vxCplHashPart1(*Str, vxCplHash(Str + 1))) : (0); }

#define HASH(Str) (uintptr_t)(vxCplConstantify<vxCplHash(Str)>::Value ^ vxCplConstantify<vxCplRandom(1)>::Value)

template <uintptr_t...> struct vxCplIndexList {};
template <typename IndexList, uintptr_t Right> struct vxCplAppend;
template <uintptr_t... Left, uintptr_t Right> struct vxCplAppend<vxCplIndexList<Left...>, Right> {
    typedef vxCplIndexList<Left..., Right> Result;
};
template <uintptr_t N> struct vxCplIndexes {
    typedef typename vxCplAppend<typename vxCplIndexes<N - 1>::Result, N - 1>::Result Result;
};
template <> struct vxCplIndexes<0> {
    typedef vxCplIndexList<> Result;
};

static const char vxCplEncryptCharKey = (const char)vxRANDOM(0, 0xFF);
constexpr char ALWAYS_INLINE vxCplEncryptChar(const char Ch, uintptr_t Idx) {
    return (char)(Ch ^ (vxCplEncryptCharKey + (char)Idx));
}

template <typename IndexList> struct vxCplEncryptedString;
template <uintptr_t... Idx> struct vxCplEncryptedString<vxCplIndexList<Idx...>> {
    char Value[sizeof...(Idx) + 1];

    constexpr ALWAYS_INLINE vxCplEncryptedString(const char* const Str)
        : Value{ vxCplEncryptChar((Str ? Str[Idx] : '\0'), Idx)... } {}

    inline const char* decrypt() {
        for (uintptr_t t = 0; t < sizeof...(Idx); t++) {
            this->Value[t] = (char)(this->Value[t] ^ (vxCplEncryptCharKey + (char)t));
        }
        this->Value[sizeof...(Idx)] = '\0';
        return this->Value;
    }
};

#define ENCRYPT(Str) (vxCplEncryptedString<vxCplIndexes<sizeof(Str) - 1>::Result>(Str).decrypt())

#ifdef __APPLE__
static inline NSString* MahoaToNSString(const char* s) {
    return s ? [NSString stringWithUTF8String:s] : @"";
}
#define NSSENCRYPT(Str) MahoaToNSString(ENCRYPT(Str))
#endif

#define ENCRYPTOFFSET(Str) strtoull(ENCRYPT(Str), NULL, 0)
#define ENCRYPTHEX(Str) ENCRYPT(Str)
