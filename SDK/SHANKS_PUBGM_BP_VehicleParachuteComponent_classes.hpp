// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_VehicleParachuteComponent_C : public UVehicleParachuteComponent
{
public:
	float                                              CameraTargetArmLength;                                     
	struct FVector                                     CameraRelativeLocation;                                    

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_VehicleParachuteComponent.BP_VehicleParachuteComponent_C");
		return pStaticClass;
	}

};


}

