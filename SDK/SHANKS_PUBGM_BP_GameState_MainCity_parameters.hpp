// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_GameState_MainCity_C_MulticastRPC_SwitchDS_Params
{
	uint64_t                                           MulticastRPC_SwitchDS_param1;                              
};

 
struct ABP_GameState_MainCity_C_MultiCast_GenericRPC_Params
{
	int                                                MultiCast_GenericRPC_param1;                               
	class UObject*                                     MultiCast_GenericRPC_param2;                               
	TArray<unsigned char>                              MultiCast_GenericRPC_param3;                               
};

 
struct ABP_GameState_MainCity_C___FeatureRPC_ReviveState_MulticastRevivalTimeEnd___Params
{
};

 
struct ABP_GameState_MainCity_C___FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___Params
{
	struct FFatalDamageParameterCompress               __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param1; 
	TArray<unsigned char>                              __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param2; 
};

 
struct ABP_GameState_MainCity_C_UserConstructionScript_Params
{
};

}

