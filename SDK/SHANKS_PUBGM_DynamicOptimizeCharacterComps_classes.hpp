// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UDynamicOptimizeCharacterComps_C : public UDynamicOptimizeActorComponents
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass DynamicOptimizeCharacterComps.DynamicOptimizeCharacterComps_C");
		return pStaticClass;
	}

};


}

