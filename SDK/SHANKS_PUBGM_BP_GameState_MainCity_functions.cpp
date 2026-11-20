// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void ABP_GameState_MainCity_C::MulticastRPC_SwitchDS(uint64_t MulticastRPC_SwitchDS_param1)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameState_MainCity.BP_GameState_MainCity_C.MulticastRPC_SwitchDS");

	ABP_GameState_MainCity_C_MulticastRPC_SwitchDS_Params params;
	params.MulticastRPC_SwitchDS_param1 = MulticastRPC_SwitchDS_param1;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void ABP_GameState_MainCity_C::MultiCast_GenericRPC(int MultiCast_GenericRPC_param1, class UObject* MultiCast_GenericRPC_param2, TArray<unsigned char> MultiCast_GenericRPC_param3)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameState_MainCity.BP_GameState_MainCity_C.MultiCast_GenericRPC");

	ABP_GameState_MainCity_C_MultiCast_GenericRPC_Params params;
	params.MultiCast_GenericRPC_param1 = MultiCast_GenericRPC_param1;
	params.MultiCast_GenericRPC_param2 = MultiCast_GenericRPC_param2;
	params.MultiCast_GenericRPC_param3 = MultiCast_GenericRPC_param3;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_GameState_MainCity_C::__FeatureRPC_ReviveState_MulticastRevivalTimeEnd__()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameState_MainCity.BP_GameState_MainCity_C.#[FeatureRPC(ReviveState.MulticastRevivalTimeEnd)]");

	ABP_GameState_MainCity_C___FeatureRPC_ReviveState_MulticastRevivalTimeEnd___Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_GameState_MainCity_C::__FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua__(const struct FFatalDamageParameterCompress& __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param1, TArray<unsigned char> __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param2)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameState_MainCity.BP_GameState_MainCity_C.#[FeatureRPC(FatalDamageFeature.MulticastRPC_BroadcastFatalDamageToClientForLua)]");

	ABP_GameState_MainCity_C___FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___Params params;
	params.__FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param1 = __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param1;
	params.__FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param2 = __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param2;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_GameState_MainCity_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameState_MainCity.BP_GameState_MainCity_C.UserConstructionScript");

	ABP_GameState_MainCity_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

