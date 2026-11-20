// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_InteractivePlayerStateFeature_RPC_Server_ExitInteractiveState___Params
{
	int                                                __FeatureRPC_InteractivePlayerStateFeature_RPC_Server_ExitInteractiveState___param1; 
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_InteractivePlayerStateFeature_RPC_Server_EnterInteractiveState___Params
{
	int                                                __FeatureRPC_InteractivePlayerStateFeature_RPC_Server_EnterInteractiveState___param1; 
	int                                                __FeatureRPC_InteractivePlayerStateFeature_RPC_Server_EnterInteractiveState___param2; 
};

 
struct ABP_PlayerState_MainCity_C_ClientRPCTeammateRealExit_Params
{
	int                                                ClientRPCTeammateRealExit_param1;                          
	uint32_t                                           ClientRPCTeammateRealExit_param2;                          
};

 
struct ABP_PlayerState_MainCity_C_ClientRPC_VersionTaskChanged_Params
{
	int                                                ClientRPC_VersionTaskChanged_param1;                       
	int                                                ClientRPC_VersionTaskChanged_param2;                       
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_TeammateTakeOverFeature_RPC_Client_RequestTeammateTakeOver___Params
{
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_StoreFeature_RPC_Client_BuyGoodsFinished___Params
{
	bool                                               __FeatureRPC_StoreFeature_RPC_Client_BuyGoodsFinished___param1; 
};

 
struct ABP_PlayerState_MainCity_C_ServerRPC_RecordOperationCount_Params
{
	TArray<int>                                        ServerRPC_RecordOperationCount_param1;                     
	bool                                               ServerRPC_RecordOperationCount_param2;                     
};

 
struct ABP_PlayerState_MainCity_C_ServerRPC_EnableVoiceChanger_Params
{
	bool                                               ServerRPC_EnableVoiceChanger_param1;                       
};

 
struct ABP_PlayerState_MainCity_C_ServerRPC_AddCommonTLogData_Params
{
	int                                                ServerRPC_AddCommonTLogData_param1;                        
	struct FString                                     StrProperty_1;                                             
	int                                                ServerRPC_AddCommonTLogData_param3;                        
};

 
struct ABP_PlayerState_MainCity_C_ReportClientPing_Params
{
	int                                                ReportClientPing_param1;                                   
	int                                                ReportClientPing_param2;                                   
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_TeammateTakeOverFeature_RPC_Server_ResponseTeammateTakeOver___Params
{
	bool                                               __FeatureRPC_TeammateTakeOverFeature_RPC_Server_ResponseTeammateTakeOver___param1; 
	bool                                               __FeatureRPC_TeammateTakeOverFeature_RPC_Server_ResponseTeammateTakeOver___param2; 
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_StoreFeature_RPC_Server_ShowNearestStore___Params
{
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_StoreFeature_RPC_Server_OpenStore___Params
{
	class AActor*                                      __FeatureRPC_StoreFeature_RPC_Server_OpenStore___param1;   
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_StoreFeature_RPC_Server_CloseStore___Params
{
	class AActor*                                      __FeatureRPC_StoreFeature_RPC_Server_CloseStore___param1;  
	int                                                __FeatureRPC_StoreFeature_RPC_Server_CloseStore___param2;  
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_StoreFeature_RPC_Server_BuyGoods___Params
{
	class AActor*                                      __FeatureRPC_StoreFeature_RPC_Server_BuyGoods___param1;    
	TArray<int>                                        __FeatureRPC_StoreFeature_RPC_Server_BuyGoods___param2;    
	TArray<int>                                        __FeatureRPC_StoreFeature_RPC_Server_BuyGoods___param3;    
	TArray<int>                                        __FeatureRPC_StoreFeature_RPC_Server_BuyGoods___param4;    
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_PhotoGrapherFeature_RPC_Server_PlayPetFeature___Params
{
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_PhotoGrapherFeature_RPC_Server_PhotographerOp___Params
{
	int                                                __FeatureRPC_PhotoGrapherFeature_RPC_Server_PhotographerOp___param1; 
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_PhotoGrapherFeature_RPC_Server_ChangePhotoGrapherOpenState___Params
{
	bool                                               __FeatureRPC_PhotoGrapherFeature_RPC_Server_ChangePhotoGrapherOpenState___param1; 
	int                                                __FeatureRPC_PhotoGrapherFeature_RPC_Server_ChangePhotoGrapherOpenState___param2; 
};

 
struct ABP_PlayerState_MainCity_C___FeatureRPC_PhotoGrapherFeature_RPC_Server_ChangeEmotePlayRate___Params
{
	int                                                __FeatureRPC_PhotoGrapherFeature_RPC_Server_ChangeEmotePlayRate___param1; 
};

 
struct ABP_PlayerState_MainCity_C_MultiCast_GenericRPC_Params
{
	int                                                MultiCast_GenericRPC_param1;                               
	TArray<unsigned char>                              MultiCast_GenericRPC_param2;                               
};

 
struct ABP_PlayerState_MainCity_C_UserConstructionScript_Params
{
};

}

