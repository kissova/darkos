// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UQuickSignComponent_BP_C_SetBoxMarkText_Params
{
	struct FString                                     InputParam;                                                
	struct FString                                     FinalText;                                                 
};

 
struct UQuickSignComponent_BP_C_GetMarkTextShowedInChatBox_Params
{
	struct FString                                     PlayerKey;                                                 
	int                                                OldTextID;                                                 
	struct FString                                     Text;                                                      
};

 
struct UQuickSignComponent_BP_C_SpectatorActorMark_Params
{
	struct FQuickSignMsg                               OriMarkInfo;                                               
	struct FQuickSignMsg                               MarkInfo;                                                  
	class AActor**                                     Actor;                                                     
};

 
struct UQuickSignComponent_BP_C_SetDistanceText_Params
{
	struct FVector                                     HidPosition;                                               
	EQuickSignSubType                                  MsgType;                                                   
};

 
struct UQuickSignComponent_BP_C_GetAudioEventAndBank_Params
{
	int                                                audioID;                                                   
	int                                                actorid;                                                   
	struct FString                                     OutBankName;                                               
	struct FString                                     OutEventName;                                              
};

 
struct UQuickSignComponent_BP_C_GetVoiceAudioID_Params
{
	int*                                               MsgType;                                                   
	int                                                ReturnValue;                                               
};

 
struct UQuickSignComponent_BP_C_PickupWrapperActorHandle_Params
{
	struct FString                                     Param;                                                     
	struct FQuickSignMark                              MarkInfo;                                                  
};

 
struct UQuickSignComponent_BP_C_GenerateMarkInfo_Params
{
	struct FQuickSignMsg                               MsgItem;                                                   
	struct FQuickSignMark                              MarkInfo;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UQuickSignComponent_BP_C_LoadConfig_Params
{
};

 
struct UQuickSignComponent_BP_C_ReceiveBeginPlay_Params
{
};

 
struct UQuickSignComponent_BP_C_ShowMsgTipsVoice_Params
{
	struct FQuickSignMsg*                              MsgItem;                                                   
	bool*                                              IsSelf;                                                    
	struct FString*                                    PlayerKey;                                                 
};

 
struct UQuickSignComponent_BP_C_PlayVoiceCD_Params
{
	float                                              Duration;                                                  
};

 
struct UQuickSignComponent_BP_C_ReportQuickSign_Params
{
	struct FQuickSignMsg*                              MsgItem;                                                   
};

 
struct UQuickSignComponent_BP_C_ExecuteUbergraph_QuickSignComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

}

