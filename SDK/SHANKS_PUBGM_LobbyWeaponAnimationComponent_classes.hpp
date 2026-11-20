// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobbyWeaponAnimationComponent_C : public UActorComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass LobbyWeaponAnimationComponent.LobbyWeaponAnimationComponent_C");
		return pStaticClass;
	}

};


}

