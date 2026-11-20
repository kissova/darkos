// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_NewFakePlayerAIC_MainCity_C : public ABP_NewFakePlayerAIC_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_NewFakePlayerAIC_MainCity.BP_NewFakePlayerAIC_MainCity_C");
		return pStaticClass;
	}

};


}

