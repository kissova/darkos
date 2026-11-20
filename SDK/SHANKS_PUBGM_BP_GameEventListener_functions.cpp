// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UBP_GameEventListener_C::SetDefaultNearClipPlane()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.SetDefaultNearClipPlane");

	UBP_GameEventListener_C_SetDefaultNearClipPlane_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::IsIOSPlatform()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.IsIOSPlatform");

	UBP_GameEventListener_C_IsIOSPlatform_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::SetDefaultRendering()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.SetDefaultRendering");

	UBP_GameEventListener_C_SetDefaultRendering_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_GameEventListener_C::EnableGrassLOD(int Enable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.EnableGrassLOD");

	UBP_GameEventListener_C_EnableGrassLOD_Params params;
	params.Enable = Enable;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::ChangeStreamingLevel()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.ChangeStreamingLevel");

	UBP_GameEventListener_C_ChangeStreamingLevel_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::InitIncaseReconnect()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.InitIncaseReconnect");

	UBP_GameEventListener_C_InitIncaseReconnect_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.ReceiveBeginPlay");

	UBP_GameEventListener_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_GameEventListener_C::ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.ReceiveEndPlay");

	UBP_GameEventListener_C_ReceiveEndPlay_Params params;
	params.EndPlayReason = EndPlayReason;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::UnloadTree()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.UnloadTree");

	UBP_GameEventListener_C_UnloadTree_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_GameEventListener_C::LoadTree()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.LoadTree");

	UBP_GameEventListener_C_LoadTree_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_GameEventListener_C::ExecuteUbergraph_BP_GameEventListener(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameEventListener.BP_GameEventListener_C.ExecuteUbergraph_BP_GameEventListener");

	UBP_GameEventListener_C_ExecuteUbergraph_BP_GameEventListener_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

