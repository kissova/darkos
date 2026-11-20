// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_CharacterSearchOtherComp_C : public USTCharacterSearchOtherComp
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_CharacterSearchOtherComp.BP_CharacterSearchOtherComp_C");
		return pStaticClass;
	}

};


}

