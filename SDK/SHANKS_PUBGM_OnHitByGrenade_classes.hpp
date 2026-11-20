// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UOnHitByGrenade_C : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass OnHitByGrenade.OnHitByGrenade_C");
		return pStaticClass;
	}


	void OnHitByCake();
};


}

