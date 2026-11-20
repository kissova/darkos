// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void ABP_STExtraWheeledVehicle_C::OnClientVehicleHealthStateChangedToDestory()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.OnClientVehicleHealthStateChangedToDestory");

	ABP_STExtraWheeledVehicle_C_OnClientVehicleHealthStateChangedToDestory_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::CreateDMI()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.CreateDMI");

	ABP_STExtraWheeledVehicle_C_CreateDMI_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void ABP_STExtraWheeledVehicle_C::SetDMIParam(class UMaterialInstanceDynamic* Dim, const struct FName& Name, float Value)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.SetDMIParam");

	ABP_STExtraWheeledVehicle_C_SetDMIParam_Params params;
	params.Dim = Dim;
	params.Name = Name;
	params.Value = Value;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_STExtraWheeledVehicle_C::UpdateExhaustFx(const struct FName& ExhaustName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.UpdateExhaustFx");

	ABP_STExtraWheeledVehicle_C_UpdateExhaustFx_Params params;
	params.ExhaustName = ExhaustName;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.UserConstructionScript");

	ABP_STExtraWheeledVehicle_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::OnEngineStart()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.OnEngineStart");

	ABP_STExtraWheeledVehicle_C_OnEngineStart_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::OnEngineStop()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.OnEngineStop");

	ABP_STExtraWheeledVehicle_C_OnEngineStop_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.ReceiveBeginPlay");

	ABP_STExtraWheeledVehicle_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_STExtraWheeledVehicle_C::OnSetTailLightValue(float* LightValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.OnSetTailLightValue");

	ABP_STExtraWheeledVehicle_C_OnSetTailLightValue_Params params;
	params.LightValue = LightValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::OnBoostingChanged()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.OnBoostingChanged");

	ABP_STExtraWheeledVehicle_C_OnBoostingChanged_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::VehicleMeshChanged()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.VehicleMeshChanged");

	ABP_STExtraWheeledVehicle_C_VehicleMeshChanged_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::BPPlayOverlapDamageCameraShake()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.BPPlayOverlapDamageCameraShake");

	ABP_STExtraWheeledVehicle_C_BPPlayOverlapDamageCameraShake_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_STExtraWheeledVehicle_C::ReceiveActorBeginOverlap(class AActor** OtherActor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.ReceiveActorBeginOverlap");

	ABP_STExtraWheeledVehicle_C_ReceiveActorBeginOverlap_Params params;
	params.OtherActor = OtherActor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_STExtraWheeledVehicle_C::AdvanceVehicleMeshChanged()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.AdvanceVehicleMeshChanged");

	ABP_STExtraWheeledVehicle_C_AdvanceVehicleMeshChanged_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_STExtraWheeledVehicle_C::ExecuteUbergraph_BP_STExtraWheeledVehicle(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C.ExecuteUbergraph_BP_STExtraWheeledVehicle");

	ABP_STExtraWheeledVehicle_C_ExecuteUbergraph_BP_STExtraWheeledVehicle_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

