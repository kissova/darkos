// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCharacterFollowComponent_C : public USTCharacterFollowComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CharacterFollowComponent.CharacterFollowComponent_C");
		return pStaticClass;
	}

};


}

