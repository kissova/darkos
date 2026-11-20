// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UBP_VehicleShootDriverComponent_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleShootDriverComponent.BP_VehicleShootDriverComponent_C.ReceiveBeginPlay");

	UBP_VehicleShootDriverComponent_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleShootDriverComponent_C::ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleShootDriverComponent.BP_VehicleShootDriverComponent_C.ReceiveEndPlay");

	UBP_VehicleShootDriverComponent_C_ReceiveEndPlay_Params params;
	params.EndPlayReason = EndPlayReason;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleShootDriverComponent_C::ExecuteUbergraph_BP_VehicleShootDriverComponent(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleShootDriverComponent.BP_VehicleShootDriverComponent_C.ExecuteUbergraph_BP_VehicleShootDriverComponent");

	UBP_VehicleShootDriverComponent_C_ExecuteUbergraph_BP_VehicleShootDriverComponent_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

