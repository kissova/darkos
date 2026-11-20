// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_VehicleShootDriverComponent_C : public UVehicleShootDriverComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_VehicleShootDriverComponent.BP_VehicleShootDriverComponent_C");
		return pStaticClass;
	}


	void ReceiveBeginPlay();
	void ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason);
	void ExecuteUbergraph_BP_VehicleShootDriverComponent(int EntryPoint);
};


}

