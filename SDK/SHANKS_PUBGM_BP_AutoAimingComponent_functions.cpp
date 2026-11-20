// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 

bool UBP_AutoAimingComponent_C::CheckInAngle(class AActor** EnemeyActor, float* MaxAngle)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AutoAimingComponent.BP_AutoAimingComponent_C.CheckInAngle");

	UBP_AutoAimingComponent_C_CheckInAngle_Params params;
	params.EnemeyActor = EnemeyActor;
	params.MaxAngle = MaxAngle;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

bool UBP_AutoAimingComponent_C::CheckSmoke(class AActor** EnemeyActor, struct FVector* StartPoint, struct FVector* EndPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AutoAimingComponent.BP_AutoAimingComponent_C.CheckSmoke");

	UBP_AutoAimingComponent_C_CheckSmoke_Params params;
	params.EnemeyActor = EnemeyActor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (StartPoint != nullptr)
		*StartPoint = params.StartPoint;
	if (EndPoint != nullptr)
		*EndPoint = params.EndPoint;

	return params.ReturnValue;
}


 
 
 
 
 
 
 
 

bool UBP_AutoAimingComponent_C::CanEnemeyRaycastReach(class AActor** EnemeyActor, struct FVector* StartPoint, struct FVector* EndPoint, struct FName* OutHitBoneName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AutoAimingComponent.BP_AutoAimingComponent_C.CanEnemeyRaycastReach");

	UBP_AutoAimingComponent_C_CanEnemeyRaycastReach_Params params;
	params.EnemeyActor = EnemeyActor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (StartPoint != nullptr)
		*StartPoint = params.StartPoint;
	if (EndPoint != nullptr)
		*EndPoint = params.EndPoint;
	if (OutHitBoneName != nullptr)
		*OutHitBoneName = params.OutHitBoneName;

	return params.ReturnValue;
}


 
 
 
 

void UBP_AutoAimingComponent_C::BPDrawDebugInfo(TArray<float>* AutoAimParams)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AutoAimingComponent.BP_AutoAimingComponent_C.BPDrawDebugInfo");

	UBP_AutoAimingComponent_C_BPDrawDebugInfo_Params params;
	params.AutoAimParams = AutoAimParams;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_AutoAimingComponent_C::ExecuteUbergraph_BP_AutoAimingComponent(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AutoAimingComponent.BP_AutoAimingComponent_C.ExecuteUbergraph_BP_AutoAimingComponent");

	UBP_AutoAimingComponent_C_ExecuteUbergraph_BP_AutoAimingComponent_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

