// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UQuickSignComponent_BP_C : public UQuickSignComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UUAEDataTable*                               QuickSignDataTable;                                        
	TMap<struct FString, struct FBP_STRUCT_QuickSignCfg_type> QuickTableConfigMap;                                       
	TMap<struct FString, struct FQuickSignMark>        QuickMarkMap;                                              
	struct FString                                     TeammateColor;                                             
	struct FString                                     SelfColor;                                                 
	struct FString                                     ColonChar;                                                 
	struct FString                                     EndChar;                                                   
	struct FString                                     SelfName;                                                  
	struct FQuickSignMsg                               CurrMsg;                                                   
	bool                                               IsPlayVoiceCooldown;                                       
	unsigned char                                      UnknownData00[0x7];                                        
	TMap<EWeaponAttachmentSocketType, int>             WeaponAttachmentSocketTextIDMap;                           
	TMap<int, int>                                     DefaultAudioMap;                                           
	struct FText                                       distanceString;                                            
	bool                                               isShowDistance;                                            
	unsigned char                                      UnknownData01[0x7];                                        
	TArray<EQuickSignSubType>                          ShowDistanceTypes;                                         
	int                                                CurDistance;                                               
	int                                                MaxShowVoiceDistance;                                      

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass QuickSignComponent_BP.QuickSignComponent_BP_C");
		return pStaticClass;
	}


	void SetBoxMarkText(const struct FString& InputParam, struct FString* FinalText);
	void GetMarkTextShowedInChatBox(const struct FString& PlayerKey, int OldTextID, struct FString* Text);
	void SpectatorActorMark(class AActor** Actor, struct FQuickSignMsg* OriMarkInfo, struct FQuickSignMsg* MarkInfo);
	void SetDistanceText(const struct FVector& HidPosition, EQuickSignSubType MsgType);
	void GetAudioEventAndBank(int audioID, int actorid, struct FString* OutBankName, struct FString* OutEventName);
	int GetVoiceAudioID(int* MsgType);
	void PickupWrapperActorHandle(const struct FString& Param, struct FQuickSignMark* MarkInfo);
	bool GenerateMarkInfo(struct FQuickSignMsg* MsgItem, struct FQuickSignMark* MarkInfo);
	void LoadConfig();
	void ReceiveBeginPlay();
	void ShowMsgTipsVoice(struct FQuickSignMsg* MsgItem, bool* IsSelf, struct FString* PlayerKey);
	void PlayVoiceCD(float Duration);
	void ReportQuickSign(struct FQuickSignMsg* MsgItem);
	void ExecuteUbergraph_QuickSignComponent_BP(int EntryPoint);
};


}

