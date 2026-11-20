// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UChatComponent_BP_C_GetIsForbidCustomChat_Params
{
	bool                                               bIsForbid;                                                 
};

 
struct UChatComponent_BP_C_PlayAutoLanguageMsg_Params
{
	int                                                actorid;                                                   
	int                                                MsgID;                                                     
};

 
struct UChatComponent_BP_C_CheckCDMsgs_Params
{
	int                                                MsgID;                                                     
	bool                                               bIsShow;                                                   
};

 
struct UChatComponent_BP_C_AddMarkAndPlaySound_Params
{
	struct FString                                     Name;                                                      
	struct FString                                     Content;                                                   
	int                                                MsgID;                                                     
	int                                                ItemCount;                                                 
	int                                                ItemId;                                                    
	struct FString                                     PlayerKeyString;                                           
	bool                                               bIsMe;                                                     
	bool                                               PlaySound;                                                 
	bool                                               ShowChat;                                                  
	float                                              Distance;                                                  
};

 
struct UChatComponent_BP_C_AddOneMarkToUIInner_Params
{
	bool                                               bIsMe;                                                     
	struct FString                                     TextMsg;                                                   
};

 
struct UChatComponent_BP_C_IsActorInGlobal_Params
{
	int                                                actorid;                                                   
	bool                                               IsExist;                                                   
};

 
struct UChatComponent_BP_C_CheckIsAddReplyBtn_Params
{
	int                                                MsgID;                                                     
	struct FString                                     PlayerName;                                                
};

 
struct UChatComponent_BP_C_GetSpecialDistanceString_Params
{
	struct FString                                     SendPlayerName;                                            
	struct FText                                       DistanceText;                                              
};

 
struct UChatComponent_BP_C_DistanceToString_Params
{
	int                                                Distance;                                                  
	int                                                MsgID;                                                     
	struct FString                                     PlayerName;                                                
	struct FText                                       DistanceText;                                              
};

 
struct UChatComponent_BP_C_GetActorNameByID_Params
{
	int                                                actorid;                                                   
	struct FString                                     actorName;                                                 
};

 
struct UChatComponent_BP_C_GetLocalText_Params
{
	int                                                MsgID;                                                     
	int                                                ItemId;                                                    
	struct FString                                     PlayerKeyString;                                           
	int                                                Distance;                                                  
	struct FString                                     PlayerName;                                                
	int                                                ItemCount;                                                 
	struct FString                                     ContentMsg;                                                
};

 
struct UChatComponent_BP_C_LoadVehicleModeQuickMsg_Params
{
};

 
struct UChatComponent_BP_C_IsVehicleWarMode_Params
{
	bool                                               IsVehicleWarMode;                                          
};

 
struct UChatComponent_BP_C_InitActorIDList_Params
{
};

 
struct UChatComponent_BP_C_LoadInfectModeQuickMsg_Params
{
};

 
struct UChatComponent_BP_C_IsInfectMode_Params
{
	bool                                               IsInfectMode;                                              
};

 
struct UChatComponent_BP_C_InitChatFlagList_Params
{
};

 
struct UChatComponent_BP_C_SetTurnplateQuickChatList_Params
{
};

 
struct UChatComponent_BP_C_GetActorBankByID_Params
{
	int                                                actorid;                                                   
	struct FString                                     BankName;                                                  
};

 
struct UChatComponent_BP_C_SwitchActorAudio_Params
{
	int                                                actorid;                                                   
};

 
struct UChatComponent_BP_C_LoadSingleAudio_Params
{
	int                                                chatTextID;                                                
};

 
struct UChatComponent_BP_C_LoadAllAudio_Params
{
};

 
struct UChatComponent_BP_C_CreateAudio_Params
{
	class UObject*                                     audio;                                                     
	int                                                resID;                                                     
};

 
struct UChatComponent_BP_C_SetQuickChatList_Params
{
};

 
struct UChatComponent_BP_C_InitFromSetting_Params
{
};

 
struct UChatComponent_BP_C_AddOneMsgToUIInner_Params
{
	bool                                               isMe;                                                      
};

 
struct UChatComponent_BP_C_PlaySound_Params
{
	int                                                MsgID;                                                     
	int                                                actorid;                                                   
};

 
struct UChatComponent_BP_C_AddToArray_Params
{
};

 
struct UChatComponent_BP_C_AddOneMsgToUI1_Params
{
	struct FString*                                    Name;                                                      
	struct FString*                                    Content;                                                   
	int*                                               MsgID;                                                     
	int*                                               audioID;                                                   
	int*                                               ItemId;                                                    
	struct FString*                                    PlayerKeyString;                                           
	bool*                                              isMe;                                                      
	bool*                                              PlaySound;                                                 
	bool*                                              ShowChat;                                                  
	float*                                             Distance;                                                  
};

 
struct UChatComponent_BP_C_NotifyFriendChat_Params
{
	struct FString*                                    str_gid;                                                   
	struct FString*                                    sender_name;                                               
	struct FString*                                    chat_content;                                              
	bool*                                              self_msg;                                                  
};

 
struct UChatComponent_BP_C_NotifyFriendInvite_Params
{
	struct FString*                                    str_gid;                                                   
	struct FString*                                    sender_name;                                               
};

 
struct UChatComponent_BP_C_NotifyFriendReplyInvite_Params
{
	struct FString*                                    str_gid;                                                   
	struct FString*                                    sender_name;                                               
	bool*                                              bReply;                                                    
};

 
struct UChatComponent_BP_C_CloseChatHistoryList_Params
{
};

 
struct UChatComponent_BP_C_UpdateQuickItemText_Params
{
	int*                                               MsgID;                                                     
	int*                                               resID;                                                     
	int*                                               alternateMsgID;                                            
	int*                                               ItemCount;                                                 
};

 
struct UChatComponent_BP_C_ReportBattleChat_Params
{
	int*                                               MsgID;                                                     
	struct FString*                                    Msg;                                                       
	int*                                               msgExtraParam;                                             
};

 
struct UChatComponent_BP_C_ReceiveBeginPlay_Params
{
};

 
struct UChatComponent_BP_C_AddOneMarkToUI_Params
{
	struct FString*                                    Name;                                                      
	struct FString*                                    Content;                                                   
	int*                                               MsgID;                                                     
	int*                                               audioID;                                                   
	int*                                               ItemId;                                                    
	struct FString*                                    PlayerKeyString;                                           
	bool*                                              isMe;                                                      
	bool*                                              PlaySound;                                                 
	bool*                                              ShowChat;                                                  
	float*                                             Distance;                                                  
};

 
struct UChatComponent_BP_C_ExecuteUbergraph_ChatComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

}

