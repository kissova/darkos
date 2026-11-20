// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_MapUIMarkManager_C : public UMapUIMarkManager
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_MapUIMarkManager.BP_MapUIMarkManager_C");
		return pStaticClass;
	}

};


}

