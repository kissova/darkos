// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABasePetController_BP_C_LoadBehaviorTree_Params
{
	int                                                Clothes;                                                   
};

 
struct ABasePetController_BP_C_CalcInAirAttackArea_Params
{
};

 
struct ABasePetController_BP_C_OnPlayerStopEmote_Params
{
	int                                                EmoteId;                                                   
	int                                                Reason;                                                    
};

 
struct ABasePetController_BP_C_OnPlayerPlayEmote_Params
{
	int                                                Emote;                                                     
};

 
struct ABasePetController_BP_C_UserConstructionScript_Params
{
};

 
struct ABasePetController_BP_C_ReceiveBeginPlay_Params
{
};

 
struct ABasePetController_BP_C_ReceiveEndPlay_Params
{
	TEnumAsByte<EEndPlayReason>*                       EndPlayReason;                                             
};

 
struct ABasePetController_BP_C_ExecuteUbergraph_BasePetController_BP_Params
{
	int                                                EntryPoint;                                                
};

}

