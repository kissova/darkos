// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_GameEventListener_C_SetDefaultNearClipPlane_Params
{
};

 
struct UBP_GameEventListener_C_IsIOSPlatform_Params
{
};

 
struct UBP_GameEventListener_C_SetDefaultRendering_Params
{
};

 
struct UBP_GameEventListener_C_EnableGrassLOD_Params
{
	int                                                Enable;                                                    
};

 
struct UBP_GameEventListener_C_ChangeStreamingLevel_Params
{
};

 
struct UBP_GameEventListener_C_InitIncaseReconnect_Params
{
};

 
struct UBP_GameEventListener_C_ReceiveBeginPlay_Params
{
};

 
struct UBP_GameEventListener_C_ReceiveEndPlay_Params
{
	TEnumAsByte<EEndPlayReason>*                       EndPlayReason;                                             
};

 
struct UBP_GameEventListener_C_UnloadTree_Params
{
};

 
struct UBP_GameEventListener_C_LoadTree_Params
{
};

 
struct UBP_GameEventListener_C_ExecuteUbergraph_BP_GameEventListener_Params
{
	int                                                EntryPoint;                                                
};

}

