// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void APlayerDeadInventoryBox_C::LuaCheckCanPlayAudio(bool* bCanPlayAudio)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.LuaCheckCanPlayAudio");

	APlayerDeadInventoryBox_C_LuaCheckCanPlayAudio_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (bCanPlayAudio != nullptr)
		*bCanPlayAudio = params.bCanPlayAudio;
}


 
 
 
 

struct FVector APlayerDeadInventoryBox_C::GetGroundLocation()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.GetGroundLocation");

	APlayerDeadInventoryBox_C_GetGroundLocation_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

void APlayerDeadInventoryBox_C::GetVector4(const struct FVector& Dest, float Ratio)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.GetVector4");

	APlayerDeadInventoryBox_C_GetVector4_Params params;
	params.Dest = Dest;
	params.Ratio = Ratio;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void APlayerDeadInventoryBox_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.UserConstructionScript");

	APlayerDeadInventoryBox_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void APlayerDeadInventoryBox_C::HideDeadTombApparence()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.HideDeadTombApparence");

	APlayerDeadInventoryBox_C_HideDeadTombApparence_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void APlayerDeadInventoryBox_C::ReceiveTick(float* DeltaSeconds)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.ReceiveTick");

	APlayerDeadInventoryBox_C_ReceiveTick_Params params;
	params.DeltaSeconds = DeltaSeconds;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void APlayerDeadInventoryBox_C::SwitchToDeadTombBox()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.SwitchToDeadTombBox");

	APlayerDeadInventoryBox_C_SwitchToDeadTombBox_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void APlayerDeadInventoryBox_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.ReceiveBeginPlay");

	APlayerDeadInventoryBox_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void APlayerDeadInventoryBox_C::ShowNormal()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.ShowNormal");

	APlayerDeadInventoryBox_C_ShowNormal_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void APlayerDeadInventoryBox_C::ShowShine()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.ShowShine");

	APlayerDeadInventoryBox_C_ShowShine_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void APlayerDeadInventoryBox_C::OpenListenUIEvent(bool* bOpen)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.OpenListenUIEvent");

	APlayerDeadInventoryBox_C_OpenListenUIEvent_Params params;
	params.bOpen = bOpen;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void APlayerDeadInventoryBox_C::ExecuteUbergraph_PlayerDeadInventoryBox(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerDeadInventoryBox.PlayerDeadInventoryBox_C.ExecuteUbergraph_PlayerDeadInventoryBox");

	APlayerDeadInventoryBox_C_ExecuteUbergraph_PlayerDeadInventoryBox_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

