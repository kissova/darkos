// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UCommon_Avatar_BP_C_SetAssetLoadingMethod_Params
{
	bool                                               Async;                                                     
};

 
struct UCommon_Avatar_BP_C_InitView_Params
{
	int                                                Style;                                                     
	struct FString                                     UID;                                                       
	struct FString                                     iconUrl;                                                   
	int                                                Gender;                                                    
	int                                                frameLevel;                                                
	int                                                PlayerLevel;                                               
	bool                                               ignoreFrame;                                               
	struct FString                                     RoleNation;                                                
};

 
struct UCommon_Avatar_BP_C_DownloadSuc__DelegateSignature_Params
{
};

 
struct UCommon_Avatar_BP_C_OnClickItemCallback__DelegateSignature_Params
{
	struct FString                                     UID;                                                       
};

}

