// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_VehicleShowFrameComp_C : public UShowActorFrameComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_VehicleShowFrameComp.BP_VehicleShowFrameComp_C");
		return pStaticClass;
	}

};


}

