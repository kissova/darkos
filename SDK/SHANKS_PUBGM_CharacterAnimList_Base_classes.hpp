// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCharacterAnimList_Base_C : public UUAECharacterAnimListComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CharacterAnimList_Base.CharacterAnimList_Base_C");
		return pStaticClass;
	}

};


}

