// HMOOD__TG@i_8_f
 

#pragma once

#include "../SDK.hpp"
#include <vector>
#include <cstdint>

 
void Drawesp();
void DrawWorldEsp();
void CaptureWorldEsp(SDK::ASTExtraPlayerCharacter* player, SDK::ASTExtraPlayerController* controller);
const char* GetVehicleName(SDK::ASTExtraVehicleBase* vehicle);

 
SDK::UWorld* GetFullWorld();
SDK::FVector GetBoneLocationByName(SDK::ASTExtraPlayerCharacter* actor,const char* boneName);
SDK::ASTExtraPlayerCharacter* GetTargetByCrossDist();

using namespace SDK;

namespace EspSafeInternal {
    inline bool IsValidHeapOrObjPtr(const void* ptr) {
        uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
        if (addr < 0x10000ULL || addr > 0x0000FFFFFFFFFFFFULL)
            return false;
        if ((addr & (sizeof(void*) - 1ULL)) != 0ULL)
            return false;
        return true;
    }
}

template <class T>
inline void GetAllActors(std::vector<T*>& outActors) {
    outActors.clear();

    auto GWorld = GetFullWorld();
    if (!EspSafeInternal::IsValidHeapOrObjPtr(GWorld) ||
        !EspSafeInternal::IsValidHeapOrObjPtr(GWorld->PersistentLevel)) {
        return;
    }

    UClass* cls = T::StaticClass();
    UGameplayStatics* gGameplayStatics = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());
    if (!EspSafeInternal::IsValidHeapOrObjPtr(cls) ||
        !EspSafeInternal::IsValidHeapOrObjPtr(gGameplayStatics)) {
        return;
    }

    TArray<AActor*> found;
    gGameplayStatics->GetAllActorsOfClass(reinterpret_cast<UObject*>(GWorld), cls, &found);

    int32_t count = found.Num();
    if (count <= 0 || count > 65536 || !EspSafeInternal::IsValidHeapOrObjPtr(found.GetData())) {
        return;
    }

    outActors.reserve(static_cast<size_t>(count));
    for (int32_t i = 0; i < count; ++i) {
        AActor* a = found[i];
        if (!EspSafeInternal::IsValidHeapOrObjPtr(a)) continue;
        if (!EspSafeInternal::IsValidHeapOrObjPtr(a->RootComponent)) continue;
        outActors.push_back(reinterpret_cast<T*>(a));
    }
}
