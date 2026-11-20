// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_VehicleAIUserComp_C : public UVehicleAIUserComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_VehicleAIUserComp.BP_VehicleAIUserComp_C");
		return pStaticClass;
	}

};


}

