// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 

bool ABP_BattleRoyaleHUD_C::IsValidDamageNumber(class AActor** DamageCauser, int* DamageTypeId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.IsValidDamageNumber");

	ABP_BattleRoyaleHUD_C_IsValidDamageNumber_Params params;
	params.DamageCauser = DamageCauser;
	params.DamageTypeId = DamageTypeId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FLinearColor ABP_BattleRoyaleHUD_C::GetPlayerNameColorByTeamID(int* TeamID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.GetPlayerNameColorByTeamID");

	ABP_BattleRoyaleHUD_C_GetPlayerNameColorByTeamID_Params params;
	params.TeamID = TeamID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FLinearColor ABP_BattleRoyaleHUD_C::GetColorByTeamID(int* TeamID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.GetColorByTeamID");

	ABP_BattleRoyaleHUD_C_GetColorByTeamID_Params params;
	params.TeamID = TeamID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void ABP_BattleRoyaleHUD_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.UserConstructionScript");

	ABP_BattleRoyaleHUD_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_BattleRoyaleHUD_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.ReceiveBeginPlay");

	ABP_BattleRoyaleHUD_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_BattleRoyaleHUD_C::HitFeedBackChanged(bool BoolValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.HitFeedBackChanged");

	ABP_BattleRoyaleHUD_C_HitFeedBackChanged_Params params;
	params.BoolValue = BoolValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_BattleRoyaleHUD_C::OBSHitFeedbackChanged(bool BoolValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.OBSHitFeedbackChanged");

	ABP_BattleRoyaleHUD_C_OBSHitFeedbackChanged_Params params;
	params.BoolValue = BoolValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_BattleRoyaleHUD_C::ExecuteUbergraph_BP_BattleRoyaleHUD(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C.ExecuteUbergraph_BP_BattleRoyaleHUD");

	ABP_BattleRoyaleHUD_C_ExecuteUbergraph_BP_BattleRoyaleHUD_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

