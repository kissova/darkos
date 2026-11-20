// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCameraShake_OverlapDamage_C : public UCameraShake
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CameraShake_OverlapDamage.CameraShake_OverlapDamage_C");
		return pStaticClass;
	}

};


}

