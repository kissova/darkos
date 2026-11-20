// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_DamageNumberHUD_C : public UDamageNumberWidget
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_DamageNumberHUD.BP_DamageNumberHUD_C");
		return pStaticClass;
	}

};


}

