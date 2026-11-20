// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void ABP_DoorMetallic_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.UserConstructionScript");

	ABP_DoorMetallic_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorMetallic_C::Timeline_0__FinishedFunc()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.Timeline_0__FinishedFunc");

	ABP_DoorMetallic_C_Timeline_0__FinishedFunc_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorMetallic_C::Timeline_0__UpdateFunc()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.Timeline_0__UpdateFunc");

	ABP_DoorMetallic_C_Timeline_0__UpdateFunc_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_DoorMetallic_C::ActionDoorOnClient(int* doorStateDst, bool* bExtraDoor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.ActionDoorOnClient");

	ABP_DoorMetallic_C_ActionDoorOnClient_Params params;
	params.doorStateDst = doorStateDst;
	params.bExtraDoor = bExtraDoor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 
 

void ABP_DoorMetallic_C::BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature");

	ABP_DoorMetallic_C_BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params params;
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


 
 
 
 
 
 
 

void ABP_DoorMetallic_C::BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature");

	ABP_DoorMetallic_C_BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature_Params params;
	params.OverlappedComponent = OverlappedComponent;
	params.OtherActor = OtherActor;
	params.OtherComp = OtherComp;
	params.OtherBodyIndex = OtherBodyIndex;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_DoorMetallic_C::ActionDoorImmediatly(int* doorStateDst, bool* bExtraDoor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.ActionDoorImmediatly");

	ABP_DoorMetallic_C_ActionDoorImmediatly_Params params;
	params.doorStateDst = doorStateDst;
	params.bExtraDoor = bExtraDoor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorMetallic_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.ReceiveBeginPlay");

	ABP_DoorMetallic_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_DoorMetallic_C::OnBPRespawned()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.OnBPRespawned");

	ABP_DoorMetallic_C_OnBPRespawned_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_DoorMetallic_C::ExecuteUbergraph_BP_DoorMetallic(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Doormetallic.BP_DoorMetallic_C.ExecuteUbergraph_BP_DoorMetallic");

	ABP_DoorMetallic_C_ExecuteUbergraph_BP_DoorMetallic_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

