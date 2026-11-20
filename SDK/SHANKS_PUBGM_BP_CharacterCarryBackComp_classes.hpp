// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_CharacterCarryBackComp_C : public USTCharacterCarryBackComp
{
public:
	TArray<struct FVector>                             PutDownLocationOffset;                                     

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_CharacterCarryBackComp.BP_CharacterCarryBackComp_C");
		return pStaticClass;
	}


	void FindFreedomLocationAndRotation(class ACharacter* Character, bool* bValid, struct FVector* Location, struct FRotator* Rotation);
};


}

