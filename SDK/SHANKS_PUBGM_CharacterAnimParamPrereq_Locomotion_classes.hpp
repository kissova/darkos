// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCharacterAnimParamPrereq_Locomotion_C : public UAnimParamPrerequisiteListAsset
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CharacterAnimParamPrereq_Locomotion.CharacterAnimParamPrereq_Locomotion_C");
		return pStaticClass;
	}

};


}

