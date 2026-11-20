// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UDeadBoxAvatarComponent_BP_C_GetVehicleDiedPath_Params
{
	int                                                ItemId;                                                    
	struct FString                                     Path;                                                      
};

 
struct UDeadBoxAvatarComponent_BP_C_IsVehicleAvatarID_Params
{
	int                                                ItemId;                                                    
	bool                                               IsVehicleAvatarID;                                         
};

 
struct UDeadBoxAvatarComponent_BP_C_GetItemAvatarHandlePath_Params
{
	int*                                               ItemId;                                                    
	struct FString                                     ReturnValue;                                               
};

 
struct UDeadBoxAvatarComponent_BP_C_GetItemAvatarHandle_Params
{
	int*                                               ItemId;                                                    
	class UBackpackCommonAvatarHandle*                 ReturnValue;                                               
};

}

