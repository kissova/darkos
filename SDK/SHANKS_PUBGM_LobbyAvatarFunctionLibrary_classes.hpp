// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobbyAvatarFunctionLibrary_C : public UBlueprintFunctionOverride
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass LobbyAvatarFunctionLibrary.LobbyAvatarFunctionLibrary_C");
		return pStaticClass;
	}


	static void OnPlayerRotate(class UCharacterAvatarComp2_BP_C* AvatarComp, class UObject* __WorldContext);
};


}

