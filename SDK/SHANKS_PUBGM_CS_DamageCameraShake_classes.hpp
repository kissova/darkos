// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCS_DamageCameraShake_C : public USTDamageCameraShake
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CS_DamageCameraShake.CS_DamageCameraShake_C");
		return pStaticClass;
	}

};


}

