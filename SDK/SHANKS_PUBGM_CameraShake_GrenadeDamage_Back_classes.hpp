// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCameraShake_GrenadeDamage_Back_C : public UCameraShake
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CameraShake_GrenadeDamage_Back.CameraShake_GrenadeDamage_Back_C");
		return pStaticClass;
	}

};


}

