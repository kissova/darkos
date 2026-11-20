// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct APlayerDeadInventoryBox_C_LuaCheckCanPlayAudio_Params
{
	bool                                               bCanPlayAudio;                                             
};

 
struct APlayerDeadInventoryBox_C_GetGroundLocation_Params
{
	struct FVector                                     ReturnValue;                                               
};

 
struct APlayerDeadInventoryBox_C_GetVector4_Params
{
	struct FVector                                     Dest;                                                      
	float                                              Ratio;                                                     
};

 
struct APlayerDeadInventoryBox_C_UserConstructionScript_Params
{
};

 
struct APlayerDeadInventoryBox_C_HideDeadTombApparence_Params
{
};

 
struct APlayerDeadInventoryBox_C_ReceiveTick_Params
{
	float*                                             DeltaSeconds;                                              
};

 
struct APlayerDeadInventoryBox_C_SwitchToDeadTombBox_Params
{
};

 
struct APlayerDeadInventoryBox_C_ReceiveBeginPlay_Params
{
};

 
struct APlayerDeadInventoryBox_C_ShowNormal_Params
{
};

 
struct APlayerDeadInventoryBox_C_ShowShine_Params
{
};

 
struct APlayerDeadInventoryBox_C_OpenListenUIEvent_Params
{
	bool*                                              bOpen;                                                     
};

 
struct APlayerDeadInventoryBox_C_ExecuteUbergraph_PlayerDeadInventoryBox_Params
{
	int                                                EntryPoint;                                                
};

}

