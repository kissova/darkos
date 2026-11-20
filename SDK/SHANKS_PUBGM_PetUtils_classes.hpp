// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetUtils_C : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetUtils.PetUtils_C");
		return pStaticClass;
	}


	static void GetPetLevelCfg(const struct FGameModePlayerPetInfo& PetInfo, class UObject* __WorldContext, struct FBP_STRUCT_PetLevelTable_type* Out_Row);
};


}

