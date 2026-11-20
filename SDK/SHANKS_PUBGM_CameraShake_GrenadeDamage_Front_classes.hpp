// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCameraShake_GrenadeDamage_Front_C : public UCameraShake
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CameraShake_GrenadeDamage_Front.CameraShake_GrenadeDamage_Front_C");
		return pStaticClass;
	}

};


}

