// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_BattleRoyaleHUD_C_IsValidDamageNumber_Params
{
	class AActor**                                     DamageCauser;                                              
	int*                                               DamageTypeId;                                              
	bool                                               ReturnValue;                                               
};

 
struct ABP_BattleRoyaleHUD_C_GetPlayerNameColorByTeamID_Params
{
	int*                                               TeamID;                                                    
	struct FLinearColor                                ReturnValue;                                               
};

 
struct ABP_BattleRoyaleHUD_C_GetColorByTeamID_Params
{
	int*                                               TeamID;                                                    
	struct FLinearColor                                ReturnValue;                                               
};

 
struct ABP_BattleRoyaleHUD_C_UserConstructionScript_Params
{
};

 
struct ABP_BattleRoyaleHUD_C_ReceiveBeginPlay_Params
{
};

 
struct ABP_BattleRoyaleHUD_C_HitFeedBackChanged_Params
{
	bool                                               BoolValue;                                                 
};

 
struct ABP_BattleRoyaleHUD_C_OBSHitFeedbackChanged_Params
{
	bool                                               BoolValue;                                                 
};

 
struct ABP_BattleRoyaleHUD_C_ExecuteUbergraph_BP_BattleRoyaleHUD_Params
{
	int                                                EntryPoint;                                                
};

}

