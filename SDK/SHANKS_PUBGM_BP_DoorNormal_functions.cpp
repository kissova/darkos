// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void ABP_DoorNormal_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.UserConstructionScript");

	ABP_DoorNormal_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorNormal_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.ReceiveBeginPlay");

	ABP_DoorNormal_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void ABP_DoorNormal_C::ReceiveAnyDamage(float* Damage, class UDamageType** DamageType, class AController** InstigatedBy, class AActor** DamageCauser)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.ReceiveAnyDamage");

	ABP_DoorNormal_C_ReceiveAnyDamage_Params params;
	params.Damage = Damage;
	params.DamageType = DamageType;
	params.InstigatedBy = InstigatedBy;
	params.DamageCauser = DamageCauser;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorNormal_C::EventTimer()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.EventTimer");

	ABP_DoorNormal_C_EventTimer_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 
 

void ABP_DoorNormal_C::BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature");

	ABP_DoorNormal_C_BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params params;
	params.OverlappedComponent = OverlappedComponent;
	params.OtherActor = OtherActor;
	params.OtherComp = OtherComp;
	params.OtherBodyIndex = OtherBodyIndex;
	params.bFromSweep = bFromSweep;
	params.SweepResult = SweepResult;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void ABP_DoorNormal_C::BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature");

	ABP_DoorNormal_C_BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature_Params params;
	params.OverlappedComponent = OverlappedComponent;
	params.OtherActor = OtherActor;
	params.OtherComp = OtherComp;
	params.OtherBodyIndex = OtherBodyIndex;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_DoorNormal_C::ActionDoorOnClient(int* doorStateDst, bool* bExtraDoor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.ActionDoorOnClient");

	ABP_DoorNormal_C_ActionDoorOnClient_Params params;
	params.doorStateDst = doorStateDst;
	params.bExtraDoor = bExtraDoor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_DoorNormal_C::BP_DoorBroken(bool* isBeginPlay, bool* bExtraDoor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.BP_DoorBroken");

	ABP_DoorNormal_C_BP_DoorBroken_Params params;
	params.isBeginPlay = isBeginPlay;
	params.bExtraDoor = bExtraDoor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_DoorNormal_C::ActionDoorImmediatly(int* doorStateDst, bool* bExtraDoor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.ActionDoorImmediatly");

	ABP_DoorNormal_C_ActionDoorImmediatly_Params params;
	params.doorStateDst = doorStateDst;
	params.bExtraDoor = bExtraDoor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorNormal_C::OnBPRespawned()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.OnBPRespawned");

	ABP_DoorNormal_C_OnBPRespawned_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_DoorNormal_C::SetInnerBoxOverlap(bool* bGenerateOverlap)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.SetInnerBoxOverlap");

	ABP_DoorNormal_C_SetInnerBoxOverlap_Params params;
	params.bGenerateOverlap = bGenerateOverlap;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_DoorNormal_C::ExecuteUbergraph_BP_DoorNormal(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_DoorNormal.BP_DoorNormal_C.ExecuteUbergraph_BP_DoorNormal");

	ABP_DoorNormal_C_ExecuteUbergraph_BP_DoorNormal_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

