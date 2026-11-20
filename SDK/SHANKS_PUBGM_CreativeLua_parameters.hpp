// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UCreativeBridgeLuaVM_UGCLuaError_Params
{
	int                                                ErrCode;                                                   
};

 
struct UCreativeBridgeLuaVM_SetUGCSuspendStateFix_Params
{
	bool                                               bEnable;                                                   
};

 
struct UCreativeBridgeLuaVM_RegisterSluaCallUgcluaEventHandler_Params
{
};

 
struct UCreativeBridgeLuaVM_PostInit_Params
{
};

 
struct UCreativeBridgeLuaVM_GetUGCSuspendStateFix_Params
{
	bool                                               ReturnValue;                                               
};

 
struct UCreativeEnvLuaVMFactory_CreateCreativeEnvLuaVM_Params
{
	struct FString                                     InLuaFilePath;                                             
	class UObject*                                     WorldContextObject;                                        
	class UCreativeEnvLuaVM*                           ReturnValue;                                               
};

}

