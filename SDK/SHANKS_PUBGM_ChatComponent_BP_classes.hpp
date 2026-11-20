// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UChatComponent_BP_C : public UChatComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FString                                     addToUIText;                                               
	TArray<struct FString>                             UITextArray;                                               
	int                                                FirstIndex;                                                
	unsigned char                                      UnknownData00[0x4];                                        
	struct FString                                     currContentMsg;                                            
	bool                                               bInitSetting;                                              
	unsigned char                                      UnknownData01[0x7];                                        
	struct FString                                     FriendChatStrGid;                                          
	struct FString                                     FriendChatSenderName;                                      
	struct FString                                     FriendChatContent;                                         
	bool                                               FriendChatSelfMsg;                                         
	unsigned char                                      UnknownData02[0x7];                                        
	struct FString                                     FriendInviteStrGid;                                        
	struct FString                                     FriendInviteSenderName;                                    
	struct FString                                     FriendInviteBattleTextValue;                               
	struct FString                                     FriendReplyStrGid;                                         
	struct FString                                     FriendReplySenderName;                                     
	bool                                               FriendReplyReply;                                          
	bool                                               isMe;                                                      
	unsigned char                                      UnknownData03[0x2];                                        
	int                                                UI_MsgID;                                                  
	struct FString                                     UI_ItemName;                                               
	int                                                UI_AlternateMsgID;                                         
	unsigned char                                      UnknownData04[0x4];                                        
	class USettingConfig_C*                            SettingConfig;                                             
	TArray<int>                                        ChatFlagTypeList;                                          
	TArray<int>                                        TmpChatIDList;                                             
	bool                                               bIsInfectMode;                                             
	unsigned char                                      UnknownData05[0x7];                                        
	TArray<struct FChatQuickTextInfo>                  ChatQuikcTextIDList_HumanMenu;                             
	TArray<struct FChatQuickTextInfo>                  ChatQuikcTextIDList_HumanTurnplate;                        
	TArray<struct FChatQuickTextInfo>                  ChatQuikcTextIDList_ZombieMenu;                            
	TArray<struct FChatQuickTextInfo>                  ChatQuikcTextIDList_ZombieTurnplate;                       
	TArray<int>                                        InfectModePlayerType;                                      
	ECharacterMainType                                 CurInfectModePlayerType;                                   
	unsigned char                                      UnknownData06[0x3];                                        
	struct FQuickChatIDAndAudio                        QuickChat;                                                 
	unsigned char                                      UnknownData07[0x4];                                        
	unsigned char                                      UnknownData08[0x50];                                       
	bool                                               bIsVehicleWarMode;                                         
	unsigned char                                      UnknownData09[0x7];                                        
	TArray<struct FChatQuickTextInfo>                  ChatQuikcTextIDList_VWMenu;                                
	TArray<struct FChatQuickTextInfo>                  ChatQuikcTextIDList_VWTurnplate;                           
	int                                                TraceItemID;                                               
	unsigned char                                      UnknownData10[0x4];                                        
	unsigned char                                      UnknownData11[0x50];                                       
	unsigned char                                      UnknownData12[0x50];                                       
	TArray<int>                                        SpecialShowDistanceMsgID;                                  
	int                                                MaxShowVoiceDistance;                                      
	bool                                               bIsMarkText;                                               
	unsigned char                                      UnknownData13[0x3];                                        
	struct FString                                     MarkText;                                                  
	TArray<struct FString>                             MarkTextArray;                                             
	int                                                addToUIMsgID;                                              
	unsigned char                                      UnknownData14[0x4];                                        
	TMap<int, int>                                     UIMsgIDMap;                                                
	unsigned char                                      UnknownData15[0x50];                                       
	float                                              CDMsgDuration;                                             
	unsigned char                                      UnknownData16[0x4];                                        
	TArray<struct FChatQuickTextInfo>                  NewVar_1;                                                  

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass ChatComponent_BP.ChatComponent_BP_C");
		return pStaticClass;
	}


	void GetIsForbidCustomChat(bool* bIsForbid);
	void PlayAutoLanguageMsg(int actorid, int MsgID);
	void CheckCDMsgs(int MsgID, bool* bIsShow);
	void AddMarkAndPlaySound(const struct FString& Name, const struct FString& Content, int MsgID, int ItemCount, int ItemId, const struct FString& PlayerKeyString, bool bIsMe, bool PlaySound, bool ShowChat, float Distance);
	void AddOneMarkToUIInner(bool bIsMe, const struct FString& TextMsg);
	void IsActorInGlobal(int actorid, bool* IsExist);
	void CheckIsAddReplyBtn(int MsgID, const struct FString& PlayerName);
	void GetSpecialDistanceString(const struct FString& SendPlayerName, struct FText* DistanceText);
	void DistanceToString(int Distance, int MsgID, const struct FString& PlayerName, struct FText* DistanceText);
	void GetActorNameByID(int actorid, struct FString* actorName);
	void GetLocalText(int MsgID, int ItemId, const struct FString& PlayerKeyString, int Distance, const struct FString& PlayerName, int ItemCount, struct FString* ContentMsg);
	void LoadVehicleModeQuickMsg();
	void IsVehicleWarMode(bool* IsVehicleWarMode);
	void InitActorIDList();
	void LoadInfectModeQuickMsg();
	void IsInfectMode(bool* IsInfectMode);
	void InitChatFlagList();
	void SetTurnplateQuickChatList();
	void GetActorBankByID(int actorid, struct FString* BankName);
	void SwitchActorAudio(int actorid);
	void LoadSingleAudio(int chatTextID);
	void LoadAllAudio();
	void CreateAudio(class UObject* audio, int resID);
	void SetQuickChatList();
	void InitFromSetting();
	void AddOneMsgToUIInner(bool isMe);
	void PlaySound(int MsgID, int actorid);
	void AddToArray();
	void AddOneMsgToUI1(struct FString* Name, struct FString* Content, int* MsgID, int* audioID, int* ItemId, struct FString* PlayerKeyString, bool* isMe, bool* PlaySound, bool* ShowChat, float* Distance);
	void NotifyFriendChat(struct FString* str_gid, struct FString* sender_name, struct FString* chat_content, bool* self_msg);
	void NotifyFriendInvite(struct FString* str_gid, struct FString* sender_name);
	void NotifyFriendReplyInvite(struct FString* str_gid, struct FString* sender_name, bool* bReply);
	void CloseChatHistoryList();
	void UpdateQuickItemText(int* MsgID, int* resID, int* alternateMsgID, int* ItemCount);
	void ReportBattleChat(int* MsgID, struct FString* Msg, int* msgExtraParam);
	void ReceiveBeginPlay();
	void AddOneMarkToUI(struct FString* Name, struct FString* Content, int* MsgID, int* audioID, int* ItemId, struct FString* PlayerKeyString, bool* isMe, bool* PlaySound, bool* ShowChat, float* Distance);
	void ExecuteUbergraph_ChatComponent_BP(int EntryPoint);
};


}

