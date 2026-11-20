// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_VehicleExplosionDamageType_C : public USTExtraDamageType
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_VehicleExplosionDamageType.BP_VehicleExplosionDamageType_C");
		return pStaticClass;
	}

};


}

