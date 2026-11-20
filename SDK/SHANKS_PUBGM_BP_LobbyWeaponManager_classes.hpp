// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_LobbyWeaponManager_C : public ULobbyWeaponManagerComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_LobbyWeaponManager.BP_LobbyWeaponManager_C");
		return pStaticClass;
	}

};


}

