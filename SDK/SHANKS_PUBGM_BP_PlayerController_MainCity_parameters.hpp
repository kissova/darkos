// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ClientStopReqInteractEmote___Params
{
	class UObject*                                     __FeatureRPC_InteractEmotePCFeature_ClientStopReqInteractEmote___param1; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ClientStopReqInteractEmote___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ClientRecResponseInteractEmoteResponse___Params
{
	class UObject*                                     __FeatureRPC_InteractEmotePCFeature_ClientRecResponseInteractEmoteResponse___param1; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ClientRecResponseInteractEmoteResponse___param2; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ClientRecResponseInteractEmoteResponse___param3; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ClientRecInteractEmoteReq___Params
{
	class UObject*                                     __FeatureRPC_InteractEmotePCFeature_ClientRecInteractEmoteReq___param1; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ClientRecInteractEmoteReq___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_HeroPropFeature_RPC_Client_AutoSelectSkill___Params
{
	int                                                __FeatureRPC_HeroPropFeature_RPC_Client_AutoSelectSkill___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_DebugFakePawnPCFeature_ClientRPC_SimPosRsp___Params
{
	int64_t                                            __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_SimPosRsp___param1; 
	float                                              __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_SimPosRsp___param2; 
	float                                              __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_SimPosRsp___param3; 
	float                                              __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_SimPosRsp___param4; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_DebugFakePawnPCFeature_ClientRPC_PosRsp___Params
{
	float                                              __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_PosRsp___param1; 
	float                                              __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_PosRsp___param2; 
	float                                              __FeatureRPC_DebugFakePawnPCFeature_ClientRPC_PosRsp___param3; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ServerStopReqInteractEmote___Params
{
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerStopReqInteractEmote___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ServerResponseInteractEmoteReq___Params
{
	class UObject*                                     __FeatureRPC_InteractEmotePCFeature_ServerResponseInteractEmoteReq___param1; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerResponseInteractEmoteReq___param2; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerResponseInteractEmoteReq___param3; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ServerReqPlayInteractEmote___Params
{
	class UObject*                                     __FeatureRPC_InteractEmotePCFeature_ServerReqPlayInteractEmote___param1; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerReqPlayInteractEmote___param2; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerReqPlayInteractEmote___param3; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerReqPlayInteractEmote___param4; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_InteractEmotePCFeature_ServerFinishEmote___Params
{
	class UObject*                                     __FeatureRPC_InteractEmotePCFeature_ServerFinishEmote___param1; 
	int                                                __FeatureRPC_InteractEmotePCFeature_ServerFinishEmote___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_HeroPropFeature_RPC_Server_SetRollSkillInfo___Params
{
	int                                                __FeatureRPC_HeroPropFeature_RPC_Server_SetRollSkillInfo___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_DebugFakePawnPCFeature_ServerRPC_PosReq___Params
{
};

 
struct ABP_PlayerController_MainCity_C_RPC_ClientHUDDisplayHitDamage_Params
{
	int                                                RPC_ClientHUDDisplayHitDamage_param1;                      
	bool                                               RPC_ClientHUDDisplayHitDamage_param2;                      
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_WonderfulPeriod_Params
{
	int                                                RPC_Client_WonderfulPeriod_param1;                         
	float                                              RPC_Client_WonderfulPeriod_param2;                         
	float                                              RPC_Client_WonderfulPeriod_param3;                         
	TArray<float>                                      RPC_Client_WonderfulPeriod_param4;                         
	int                                                RPC_Client_WonderfulPeriod_param5;                         
	float                                              RPC_Client_WonderfulPeriod_param6;                         
	bool                                               RPC_Client_WonderfulPeriod_param7;                         
	TArray<struct FWonderfulSubTypeInfo>               RPC_Client_WonderfulPeriod_param8;                         
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_ShowBattleGMOutputText_Params
{
	struct FString                                     StrProperty_24;                                            
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_PostTGPAIS_Params
{
	int                                                RPC_Client_PostTGPAIS_param1;                              
	struct FString                                     StrProperty_23;                                            
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_PopupAFKWindow_Params
{
	bool                                               RPC_Client_PopupAFKWindow_param1;                          
	bool                                               RPC_Client_PopupAFKWindow_param2;                          
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_NotifyUseShareSkin_Params
{
	int                                                RPC_Client_NotifyUseShareSkin_param1;                      
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_MarkShoot_Params
{
	class AActor*                                      RPC_Client_MarkShoot_param1;                               
	class AActor*                                      RPC_Client_MarkShoot_param2;                               
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_MaliciousTeammateVictimReceiveTips_Params
{
	struct FString                                     StrProperty_22;                                            
	bool                                               RPC_Client_MaliciousTeammateVictimReceiveTips_param2;      
	int                                                RPC_Client_MaliciousTeammateVictimReceiveTips_param3;      
};

 
struct ABP_PlayerController_MainCity_C_RPC_Client_MaliciousTeammateReceiveWarningTips_Params
{
};

 
struct ABP_PlayerController_MainCity_C_Client_GenericRPC_Params
{
	int                                                Client_GenericRPC_param1;                                  
	TArray<unsigned char>                              Client_GenericRPC_param2;                                  
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_SecurityNotifyPCFeature_ClientRPC_WeakTips___Params
{
	struct FString                                     StrProperty_21;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_SecurityNotifyPCFeature_ClientRPC_SyncBanID___Params
{
	int                                                __FeatureRPC_SecurityNotifyPCFeature_ClientRPC_SyncBanID___param1; 
	int                                                __FeatureRPC_SecurityNotifyPCFeature_ClientRPC_SyncBanID___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_SecurityNotifyPCFeature_ClientRPC_StrongTips___Params
{
	struct FString                                     StrProperty_20;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_SecurityNotifyPCFeature_ClientRPC_NormalTips___Params
{
	struct FString                                     StrProperty_19;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_PlayerControllerFatalDamageFeature_RPC_Client_BroadcastFatalDamageToClientForLua___Params
{
	struct FFatalDamageParameterCompress               __FeatureRPC_PlayerControllerFatalDamageFeature_RPC_Client_BroadcastFatalDamageToClientForLua___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_OncePerGameAkEventFeature_RPC_Client_PlayAkEvent___Params
{
	struct FString                                     StrProperty_18;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_NewbieAssistFeature_RPC_Client_RescueOtherSuccessfully___Params
{
	uint32_t                                           __FeatureRPC_NewbieAssistFeature_RPC_Client_RescueOtherSuccessfully___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_TriggerWatchLike___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerWatchLike___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerWatchLike___param2; 
	uint64_t                                           __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerWatchLike___param3; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerWatchLike___param4; 
	struct FString                                     StrProperty_17;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_TriggerLike___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerLike___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerLike___param2; 
	uint64_t                                           __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerLike___param3; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_TriggerLike___param4; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_ShowOff___Params
{
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_ShowOff___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_RPGiveNotify___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Client_RPGiveNotify___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_RPGiveNotify___param2; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_RPGiveNotify___param3; 
	struct FString                                     StrProperty_15;                                            
	struct FString                                     StrProperty_16;                                            
	bool                                               __FeatureRPC_IngameLikeFeature_RPC_Client_RPGiveNotify___param6; 
	bool                                               __FeatureRPC_IngameLikeFeature_RPC_Client_RPGiveNotify___param7; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_RecieveLike___Params
{
	uint64_t                                           __FeatureRPC_IngameLikeFeature_RPC_Client_RecieveLike___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_RecieveLike___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_LikeProgress___Params
{
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_LikeProgress___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_KillNumChange___Params
{
	struct FString                                     StrProperty_14;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Client_HideLike___Params
{
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Client_HideLike___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCClient_XSuitIconRsp___Params
{
	bool                                               __FeatureRPC_CommerFeature_RPCClient_XSuitIconRsp___param1; 
	int                                                __FeatureRPC_CommerFeature_RPCClient_XSuitIconRsp___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCClient_TeamShowPetEnlargeDataRsp___Params
{
	struct FString                                     StrProperty_13;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCClient_TeamShowPetEffectRsp___Params
{
	struct FString                                     StrProperty_12;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCClient_TeamShowMiniTvDataRsp___Params
{
	struct FString                                     StrProperty_11;                                            
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCClient_CollectScoreRsp___Params
{
	bool                                               __FeatureRPC_CommerFeature_RPCClient_CollectScoreRsp___param1; 
	struct FString                                     StrProperty_10;                                            
	int                                                __FeatureRPC_CommerFeature_RPCClient_CollectScoreRsp___param3; 
	int                                                __FeatureRPC_CommerFeature_RPCClient_CollectScoreRsp___param4; 
	bool                                               __FeatureRPC_CommerFeature_RPCClient_CollectScoreRsp___param5; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCClient_AliasEnterBroadcastRsp___Params
{
	int                                                __FeatureRPC_CommerFeature_RPCClient_AliasEnterBroadcastRsp___param1; 
	int                                                __FeatureRPC_CommerFeature_RPCClient_AliasEnterBroadcastRsp___param2; 
	struct FString                                     StrProperty_9;                                             
	int                                                __FeatureRPC_CommerFeature_RPCClient_AliasEnterBroadcastRsp___param4; 
};

 
struct ABP_PlayerController_MainCity_C_Server_GenericRPC_Params
{
	int                                                Server_GenericRPC_param1;                                  
	TArray<unsigned char>                              Server_GenericRPC_param2;                                  
};

 
struct ABP_PlayerController_MainCity_C_RPC_Server_SetPetRandomAnimDisable_Params
{
	bool                                               RPC_Server_SetPetRandomAnimDisable_param1;                 
};

 
struct ABP_PlayerController_MainCity_C_RPC_Server_SetGameReadyCountDown_Params
{
	int                                                RPC_Server_SetGameReadyCountDown_param1;                   
};

 
struct ABP_PlayerController_MainCity_C_RPC_Server_SetAutoUseMelee_Params
{
	bool                                               RPC_Server_SetAutoUseMelee_param1;                         
};

 
struct ABP_PlayerController_MainCity_C_RPC_Server_ReqUseShareSkin_Params
{
};

 
struct ABP_PlayerController_MainCity_C_RPC_Server_RealUseShareSkin_Params
{
};

 
struct ABP_PlayerController_MainCity_C_RPC_Server_PlaySpecifiedPetAnimation_Params
{
	int                                                RPC_Server_PlaySpecifiedPetAnimation_param1;               
	float                                              RPC_Server_PlaySpecifiedPetAnimation_param2;               
	int                                                RPC_Server_PlaySpecifiedPetAnimation_param3;               
	bool                                               RPC_Server_PlaySpecifiedPetAnimation_param4;               
	bool                                               RPC_Server_PlaySpecifiedPetAnimation_param5;               
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_NewbieAssistFeature_RPC_Server_StartNewbieAssistDSSubSystem___Params
{
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_MLAIVoiceFeature_RPC_Server_SendRSTSSubtitleText___Params
{
	struct FString                                     StrProperty_7;                                             
	float                                              __FeatureRPC_MLAIVoiceFeature_RPC_Server_SendRSTSSubtitleText___param2; 
	float                                              __FeatureRPC_MLAIVoiceFeature_RPC_Server_SendRSTSSubtitleText___param3; 
	struct FString                                     StrProperty_8;                                             
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_MLAIVoiceFeature_RPC_Server_SendAIVoiceTLog___Params
{
	uint64_t                                           __FeatureRPC_MLAIVoiceFeature_RPC_Server_SendAIVoiceTLog___param1; 
	struct FString                                     StrProperty_5;                                             
	struct FString                                     StrProperty_6;                                             
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_ShowOff___Params
{
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_ShowOff___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_RPGive___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Server_RPGive___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_RPGive___param2; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_RPGive___param3; 
	struct FString                                     StrProperty_3;                                             
	struct FString                                     StrProperty_4;                                             
	bool                                               __FeatureRPC_IngameLikeFeature_RPC_Server_RPGive___param6; 
	bool                                               __FeatureRPC_IngameLikeFeature_RPC_Server_RPGive___param7; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_RespondLike___Params
{
	uint64_t                                           __FeatureRPC_IngameLikeFeature_RPC_Server_RespondLike___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_RespondLike___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_LikeSwitch___Params
{
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_LikeSwitch___param1; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_Like___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Server_Like___param1;   
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_Like___param2;   
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_ClientReady___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Server_ClientReady___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_ClientReady___param2; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_IngameLikeFeature_RPC_Server_ClientEnterCircle___Params
{
	uint32_t                                           __FeatureRPC_IngameLikeFeature_RPC_Server_ClientEnterCircle___param1; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_ClientEnterCircle___param2; 
	int                                                __FeatureRPC_IngameLikeFeature_RPC_Server_ClientEnterCircle___param3; 
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCServer_XSuitIconReq___Params
{
	struct FString                                     StrProperty_2;                                             
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCServer_CollectScoreReq___Params
{
	struct FString                                     StrProperty_1;                                             
};

 
struct ABP_PlayerController_MainCity_C___FeatureRPC_CommerFeature_RPCServer_AliasEnterBroadcastReq___Params
{
};

 
struct ABP_PlayerController_MainCity_C_RPC_Multicast_OnCreateDecal_Params
{
	int                                                RPC_Multicast_OnCreateDecal_param1;                        
};

 
struct ABP_PlayerController_MainCity_C_PostOnShowTouchInterface_Params
{
	bool                                               bShow;                                                     
};

 
struct ABP_PlayerController_MainCity_C_NotCanShowTouchInterfaceHandle_Params
{
	bool                                               NotCanShow;                                                
};

 
struct ABP_PlayerController_MainCity_C_ReadAutoEquipMelleeConfig_Params
{
	bool                                               NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_TriggerInputAction_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_SwitchFreeViewInOB_Params
{
};

 
struct ABP_PlayerController_MainCity_C_SwitchToTeammate_Params
{
	int                                                TeammateIdx;                                               
};

 
struct ABP_PlayerController_MainCity_C_LuaShouldShowTouchInterface_Params
{
	bool                                               bShow;                                                     
	bool                                               ShouldShow;                                                
};

 
struct ABP_PlayerController_MainCity_C_CreateTouchComp_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReadSceenMoveXAdd_Params
{
	bool                                               SceenMoveXAdd;                                             
};

 
struct ABP_PlayerController_MainCity_C_ReadClientReplayConfig_Params
{
};

 
struct ABP_PlayerController_MainCity_C_MapFromCBToESBH_Params
{
	class USettingConfig_C*                            SettingConfig;                                             
};

 
struct ABP_PlayerController_MainCity_C_ReceiveLuaTick_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReceiveLuaBeginPlay_Params
{
};

 
struct ABP_PlayerController_MainCity_C_StopAvatarDownload_Params
{
};

 
struct ABP_PlayerController_MainCity_C_SetMultiVersionRedSwitchConfig_Params
{
};

 
struct ABP_PlayerController_MainCity_C_MapFromCBToESGlobal_Params
{
	class USettingConfig_C*                            SettingConfig;                                             
};

 
struct ABP_PlayerController_MainCity_C_MapFromCBToESVN_Params
{
	class USettingConfig_C*                            SettingConfig;                                             
};

 
struct ABP_PlayerController_MainCity_C_MapFromCBToESJK_Params
{
	class USettingConfig_C*                            SettingConfig;                                             
};

 
struct ABP_PlayerController_MainCity_C_MapFromCBToES_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigEffectSettingColorSingleLayer_Params
{
	int                                                NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigEffectSettingColorMultiLayer_Params
{
	int                                                NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_InitNewbieCounts_Params
{
};

 
struct ABP_PlayerController_MainCity_C_AddIgnoreCameraMoveIndex_Params
{
	TEnumAsByte<ETouchIndex>                           _Index;                                                    
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigColorBlindnessTypeBoolDelegate_Params
{
	bool                                               NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigColorBlindnessTypeIntDelegate_Params
{
	int                                                NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_CheckGlobalReadRed_Params
{
	struct FString                                     StrID;                                                     
	bool                                               bIsRed;                                                    
};

 
struct ABP_PlayerController_MainCity_C_CheckIsBood_Params
{
	struct FString                                     StrID;                                                     
	bool                                               bIsBlood;                                                  
};

 
struct ABP_PlayerController_MainCity_C_CheckJapnReadRed_Params
{
	struct FString                                     StrID;                                                     
	bool                                               bIsRed;                                                    
};

 
struct ABP_PlayerController_MainCity_C_GetJKCBColor_Params
{
	struct FString                                     ID;                                                        
	bool                                               bFind;                                                     
	struct FLinearColor                                Color;                                                     
};

 
struct ABP_PlayerController_MainCity_C_GetVNCBColor_Params
{
	struct FString                                     ID;                                                        
	bool                                               bFind;                                                     
	struct FLinearColor                                Color;                                                     
};

 
struct ABP_PlayerController_MainCity_C_GetCBColor_Params
{
	struct FBP_STRUCT_ColorBlindnessConfig_type        tempCBData;                                                
	struct FLinearColor                                Color;                                                     
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigColorBlindnessType_Params
{
};

 
struct ABP_PlayerController_MainCity_C_CurGameMode_Params
{
	int                                                GameMode;                                                  
};

 
struct ABP_PlayerController_MainCity_C_IsFPP_Params
{
	bool                                               IsFPP;                                                     
};

 
struct ABP_PlayerController_MainCity_C_OnRep_InWateringRange_Params
{
};

 
struct ABP_PlayerController_MainCity_C_LoadAllBattleSound_Params
{
};

 
struct ABP_PlayerController_MainCity_C_AsyncLoadBattleSound_Params
{
	class UObject*                                     Object;                                                    
	int                                                SoundID;                                                   
};

 
struct ABP_PlayerController_MainCity_C_LoadBattleSound_Params
{
	struct FString                                     BankName;                                                  
	struct FString                                     EventName;                                                 
	int                                                SoundID;                                                   
};

 
struct ABP_PlayerController_MainCity_C_SetAlwaysHideTouchInterface_Params
{
	bool                                               Hide;                                                      
};

 
struct ABP_PlayerController_MainCity_C_PlayBattleSoundInBP_Params
{
	int                                                SoundID;                                                   
};

 
struct ABP_PlayerController_MainCity_C_IsReleasePosInAimBtnRange_Params
{
	struct FVector*                                    Loc;                                                       
	bool                                               ReturnValue;                                               
};

 
struct ABP_PlayerController_MainCity_C_ReadEmoteDataRowPC_Params
{
};

 
struct ABP_PlayerController_MainCity_C_IsAtaptation_Params
{
	bool                                               adaptation;                                                
};

 
struct ABP_PlayerController_MainCity_C_ReadAdaptationTable_Params
{
};

 
struct ABP_PlayerController_MainCity_C_InitWeather_Params
{
};

 
struct ABP_PlayerController_MainCity_C_SetMotionParam_Params
{
};

 
struct ABP_PlayerController_MainCity_C_GetStickLeftSize_Params
{
	struct FVector2D                                   Size;                                                      
};

 
struct ABP_PlayerController_MainCity_C_ShowFightingUI_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ShowAutoSprintBtn_Params
{
	bool                                               Visible;                                                   
	struct FVector2D                                   showPos_;                                                  
	bool                                               inside;                                                    
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigCrossHairColor_Params
{
	int                                                NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigMotionControl_Params
{
	int                                                NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigAutoAim_Params
{
	bool                                               NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_ReadConfigFromHUD_Params
{
};

 
struct ABP_PlayerController_MainCity_C_DebugNotDrawGuideLine_Params
{
};

 
struct ABP_PlayerController_MainCity_C_BindOrUnBindJoyStickSprint_Params
{
	bool                                               IsBind;                                                    
};

 
struct ABP_PlayerController_MainCity_C_SwitchAimMode_Params
{
};

 
struct ABP_PlayerController_MainCity_C_HandleJumpBtnPressEvent_Params
{
};

 
struct ABP_PlayerController_MainCity_C_OnRep_bInCar_Params
{
};

 
struct ABP_PlayerController_MainCity_C_RefreshUI_Params
{
	float                                              DeltaTime;                                                 
};

 
struct ABP_PlayerController_MainCity_C_UpdateInputPanel_Params
{
};

 
struct ABP_PlayerController_MainCity_C_RefreshWeaponPanel_Params
{
};

 
struct ABP_PlayerController_MainCity_C_SetTouchInputEnabled_Params
{
	bool                                               bEnabled;                                                  
};

 
struct ABP_PlayerController_MainCity_C_ShowMainInputControl_Params
{
	bool                                               bShow;                                                     
};

 
struct ABP_PlayerController_MainCity_C_ShowTouchInterface_Params
{
	bool                                               bShow;                                                     
};

 
struct ABP_PlayerController_MainCity_C_EnableDeathGray_Params
{
	float                                              BlendWeight;                                               
};

 
struct ABP_PlayerController_MainCity_C_SetDeathGrayLerpValue_Params
{
	float                                              Lerp;                                                      
};

 
struct ABP_PlayerController_MainCity_C_SetPostProcessVolume_Params
{
};

 
struct ABP_PlayerController_MainCity_C_UserConstructionScript_Params
{
};

 
struct ABP_PlayerController_MainCity_C_GrayToOne__FinishedFunc_Params
{
};

 
struct ABP_PlayerController_MainCity_C_GrayToOne__UpdateFunc_Params
{
};

 
struct ABP_PlayerController_MainCity_C_GrayToZero__FinishedFunc_Params
{
};

 
struct ABP_PlayerController_MainCity_C_GrayToZero__UpdateFunc_Params
{
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSetMouseCursor_K2Node_InputActionEvent_174_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCFire_K2Node_InputActionEvent_173_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCFire_K2Node_InputActionEvent_172_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAim_K2Node_InputActionEvent_171_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAim_K2Node_InputActionEvent_170_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSwitchWeaponShootType_K2Node_InputActionEvent_169_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCChangeThrowMode_K2Node_InputActionEvent_168_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCFreeCamera_K2Node_InputActionEvent_167_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCFreeCamera_K2Node_InputActionEvent_166_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCEntireMapZoomIn_K2Node_InputActionEvent_165_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCEntireMapZoomOut_K2Node_InputActionEvent_164_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCReload_K2Node_InputActionEvent_163_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCProne_K2Node_InputActionEvent_162_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSwitchPMode_K2Node_InputActionEvent_161_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAutoSprint_K2Node_InputActionEvent_160_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCCrouch_K2Node_InputActionEvent_159_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectNextWeapon_K2Node_InputActionEvent_158_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectPreWeapon_K2Node_InputActionEvent_157_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSetTeamSpeaker_K2Node_InputActionEvent_156_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSetTeamMicphone_K2Node_InputActionEvent_155_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectGrenade_K2Node_InputActionEvent_154_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectSmokeGrenade_K2Node_InputActionEvent_153_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectMedKit_K2Node_InputActionEvent_152_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectMolotovCocktailOrStunGrenade_K2Node_InputActionEvent_151_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectFirstAidKit_K2Node_InputActionEvent_150_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectBandages_K2Node_InputActionEvent_149_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectEnergyDrink_K2Node_InputActionEvent_148_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectMelee_K2Node_InputActionEvent_147_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCCancelThrow_K2Node_InputActionEvent_146_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVault_K2Node_InputActionEvent_145_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVault_K2Node_InputActionEvent_144_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSprint_K2Node_InputActionEvent_143_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSprint_K2Node_InputActionEvent_142_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCCloseUI_K2Node_InputActionEvent_141_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCChangeSeat_K2Node_InputActionEvent_140_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCChangeSeat_K2Node_InputActionEvent_139_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCExitVehicle_K2Node_InputActionEvent_138_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBasicSkill1_K2Node_InputActionEvent_137_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBasicSkill1_K2Node_InputActionEvent_136_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBasicSkill2_K2Node_InputActionEvent_135_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBasicSkill2_K2Node_InputActionEvent_134_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBasicSkill3_K2Node_InputActionEvent_133_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBasicSkill3_K2Node_InputActionEvent_132_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleForward_K2Node_InputActionEvent_131_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleForward_K2Node_InputActionEvent_130_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleBackward_K2Node_InputActionEvent_129_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleBackward_K2Node_InputActionEvent_128_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleTurnLeft_K2Node_InputActionEvent_127_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleTurnLeft_K2Node_InputActionEvent_126_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleTurnRight_K2Node_InputActionEvent_125_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleTurnRight_K2Node_InputActionEvent_124_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleControl_K2Node_InputActionEvent_123_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCVehicleControl_K2Node_InputActionEvent_122_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAircraftThrust_K2Node_InputActionEvent_121_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAircraftThrust_K2Node_InputActionEvent_120_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAircraftThrustBackward_K2Node_InputActionEvent_119_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCAircraftThrustBackward_K2Node_InputActionEvent_118_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeam_PostTeamID_K2Node_InputActionEvent_117_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeam_ClearTeamID_K2Node_InputActionEvent_116_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeam_DelOneNum_K2Node_InputActionEvent_115_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_ToggleTeamListPanel_K2Node_InputActionEvent_114_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_ToggleTeamListPanel_K2Node_InputActionEvent_113_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_OBSkipOverPanel_K2Node_InputActionEvent_112_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeammate1_K2Node_InputActionEvent_111_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeammate2_K2Node_InputActionEvent_110_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeammate3_K2Node_InputActionEvent_109_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_SwitchToTeammate4_K2Node_InputActionEvent_108_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_OBSwitchFreeView_K2Node_InputActionEvent_107_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSwimup_K2Node_InputActionEvent_106_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSwimup_K2Node_InputActionEvent_105_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCPeekRight_K2Node_InputActionEvent_104_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCPeekRight_K2Node_InputActionEvent_103_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCPeekLeft_K2Node_InputActionEvent_102_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCPeekLeft_K2Node_InputActionEvent_101_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCChangeSight_K2Node_InputActionEvent_100_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCChangeSight_K2Node_InputActionEvent_99_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCQuickSign_K2Node_InputActionEvent_98_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectWeapon3_K2Node_InputActionEvent_97_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectWeapon2_K2Node_InputActionEvent_96_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSelectWeapon1_K2Node_InputActionEvent_95_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCQuickChatMenu_K2Node_InputActionEvent_94_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCBackPack_K2Node_InputActionEvent_93_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCEntireMap_K2Node_InputActionEvent_92_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSwimDown_K2Node_InputActionEvent_91_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCSwimDown_K2Node_InputActionEvent_90_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_GoBack_K2Node_InputActionEvent_89_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_InpActEvt_PCOBViewAttacker_K2Node_InputActionEvent_88_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ABP_PlayerController_MainCity_C_OnShowAnimationButton_Params
{
	bool*                                              IsShow;                                                    
	int*                                               NewUIType;                                                 
};

 
struct ABP_PlayerController_MainCity_C_OnCharacterCurrentActivityIDRep_Params
{
	int*                                               CurrentActivityID;                                         
};

 
struct ABP_PlayerController_MainCity_C_ReceiveBeginPlay_Params
{
};

 
struct ABP_PlayerController_MainCity_C_OnSpectatorCameraChange_Params
{
	bool*                                              bDie;                                                      
};

 
struct ABP_PlayerController_MainCity_C_OnStopFireEventHandle_Params
{
};

 
struct ABP_PlayerController_MainCity_C_OnSwitchCameraSatrtHandle_Params
{
	TEnumAsByte<EPlayerCameraMode>                     CameraMode;                                                
};

 
struct ABP_PlayerController_MainCity_C_OnPlayerPutDownActorHandle_Params
{
	class ASTExtraBaseCharacter*                       TargetPlayer;                                              
	class AActor*                                      TargetActor;                                               
};

 
struct ABP_PlayerController_MainCity_C_OnSwitchWeaponHandle_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReceiveTick_Params
{
	float*                                             DeltaSeconds;                                              
};

 
struct ABP_PlayerController_MainCity_C_OnUseInventoryitemHandle_Params
{
};

 
struct ABP_PlayerController_MainCity_C_RefreshTopMostUIPanel_Params
{
	TEnumAsByte<ETopMostUIPanelType>*                  Type;                                                      
};

 
struct ABP_PlayerController_MainCity_C_GameStart_Params
{
};

 
struct ABP_PlayerController_MainCity_C_SetMoveableAirborne_Params
{
	bool                                               NewParam;                                                  
};

 
struct ABP_PlayerController_MainCity_C_OnLandOnGroundAfterJumpPlaneEnd_Params
{
};

 
struct ABP_PlayerController_MainCity_C_SetPanels_Params
{
	TArray<class UUAEUserWidget*>*                     panels;                                                    
};

 
struct ABP_PlayerController_MainCity_C_DoUITouchMove_Params
{
	struct FVector*                                    Loc;                                                       
};

 
struct ABP_PlayerController_MainCity_C_PressFire_Params
{
	int*                                               FingerIndex;                                               
};

 
struct ABP_PlayerController_MainCity_C_ShowFireBtn_Params
{
	bool*                                              bShow;                                                     
};

 
struct ABP_PlayerController_MainCity_C_PressGrenade_Params
{
	bool*                                              isThrow;                                                   
};

 
struct ABP_PlayerController_MainCity_C_MemberVoice_Params
{
	int*                                               Member;                                                    
	int*                                               status;                                                    
};

 
struct ABP_PlayerController_MainCity_C_ReceiveClientRestart_Params
{
};

 
struct ABP_PlayerController_MainCity_C_OnWeaponEquipAttachment_Params
{
	TEnumAsByte<ESurviveWeaponPropSlot>*               WeaponPropSlot;                                            
	struct FItemDefineID*                              DefineID;                                                  
	bool*                                              bEquip;                                                    
};

 
struct ABP_PlayerController_MainCity_C_MotionControliOS_Params
{
	struct FVector                                     AxisValue;                                                 
};

 
struct ABP_PlayerController_MainCity_C_InpAxisKeyEvt_RotationRate_K2Node_InputVectorAxisEvent_1_Params
{
	struct FVector                                     AxisValue;                                                 
};

 
struct ABP_PlayerController_MainCity_C_MotionControlAndroidTick_Params
{
};

 
struct ABP_PlayerController_MainCity_C_MotionControlAndroid_Params
{
	struct FVector                                     AxisValue;                                                 
};

 
struct ABP_PlayerController_MainCity_C_ReceiveBackpackComponent_Params
{
};

 
struct ABP_PlayerController_MainCity_C_InitNewbieComponent_Params
{
	TArray<int>*                                       FinishedGuide;                                             
	TArray<int>*                                       FinishedCounts;                                            
	int*                                               PlayerLevel;                                               
	int*                                               PlayerExperienceType;                                      
};

 
struct ABP_PlayerController_MainCity_C_DebugOpenGuide_Params
{
};

 
struct ABP_PlayerController_MainCity_C_BP_OceanSideDetected_Params
{
	struct FVector*                                    OceansideLocation;                                         
	bool*                                              bDetectedRiver;                                            
};

 
struct ABP_PlayerController_MainCity_C_CallShowTouchInterface_Params
{
	bool*                                              InShow;                                                    
};

 
struct ABP_PlayerController_MainCity_C_OnGameModeStateChanged_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReleaseFire_Params
{
};

 
struct ABP_PlayerController_MainCity_C_OnRep_InWateringRangeBP_Params
{
};

 
struct ABP_PlayerController_MainCity_C_PlayerExitJumpEvent_Params
{
};

 
struct ABP_PlayerController_MainCity_C_EnterFightingStateDelegate_Params
{
};

 
struct ABP_PlayerController_MainCity_C_GameStartCountDownDelegate_Params
{
	float                                              CountDownTime;                                             
};

 
struct ABP_PlayerController_MainCity_C_LuaReceiveBeginPlay_Params
{
};

 
struct ABP_PlayerController_MainCity_C_InpAxisKeyEvt_Acceleration_K2Node_InputVectorAxisEvent_4_Params
{
	struct FVector                                     AxisValue;                                                 
};

 
struct ABP_PlayerController_MainCity_C_DynamicHoldGun_Params
{
	bool                                               BoolValue;                                                 
};

 
struct ABP_PlayerController_MainCity_C_InitIngameUI_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ActivateDefaultTouchInterface_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ExecuteUbergraph_BP_PlayerController_MainCity_Params
{
	int                                                EntryPoint;                                                
};

 
struct ABP_PlayerController_MainCity_C_VaultFailDS__DelegateSignature_Params
{
};

 
struct ABP_PlayerController_MainCity_C_BindEventToBackpackComponent__DelegateSignature_Params
{
};

 
struct ABP_PlayerController_MainCity_C_PlayerLeaveWater__DelegateSignature_Params
{
	bool                                               HideLung;                                                  
};

 
struct ABP_PlayerController_MainCity_C_PlayerEnterWater__DelegateSignature_Params
{
};

 
struct ABP_PlayerController_MainCity_C_AirborneLanded__DelegateSignature_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReloadingCDEnd__DelegateSignature_Params
{
};

 
struct ABP_PlayerController_MainCity_C_ReloadingCDStart__DelegateSignature_Params
{
	float                                              CD;                                                        
};

}

