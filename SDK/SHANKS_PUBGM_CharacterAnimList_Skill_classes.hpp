// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCharacterAnimList_Skill_C : public UUAECharacterAnimListComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CharacterAnimList_Skill.CharacterAnimList_Skill_C");
		return pStaticClass;
	}

};


}

