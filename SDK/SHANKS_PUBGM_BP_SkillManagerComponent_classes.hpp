// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_SkillManagerComponent_C : public UUAECharacterSkillManagerComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_SkillManagerComponent.BP_SkillManagerComponent_C");
		return pStaticClass;
	}

};


}

