// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCharacterAvatarComp2_BP_C : public UCharacterAvatarComponent2
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UBackpackAvatarItemColor*                    BasedAvatarColorHandle;                                    
	class UBackpackAvatarItemPattern*                  BasedAvatarPatternHandle;                                  
	EBattleItemUseReason                               PreEquipClothReason;                                       
	unsigned char                                      UnknownData00[0x7];                                        
	unsigned char                                      UnknownData01[0x28];                                       
	unsigned char                                      UnknownData02[0x28];                                       
	bool                                               bForbidBindAvatarEquippedEvent;                            
	unsigned char                                      UnknownData03[0x7];                                        
	TArray<int>                                        NeedModifyVehicleID;                                       
	TMap<EAvatarSlotType, int>                         SlotToFakeHandleMap;                                       
	TMap<int, class UObject*>                          CurHandhleMap;                                             

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C");
		return pStaticClass;
	}


	TArray<int> GetHeadIgnoreSlots(int* InItemHeadID);
	bool CanUseDefaultAvatarHandleItem(int* InSlotID, int* InItemID);
	int GetDefaultAvatarHandleItem(int* InSlotID, int* InItemID, int* AdditionalItemID);
	void PrintDefaultConfig();
	void HandleCharacterHiddenChange(bool bHidden);
	void HandlePlayerScopeInOrOut(bool bScopeIn);
	void EnableAvatarAnimation(bool IsEnable);
	int GetRepalceIDOnVehicle(int* OriginID);
	EAvatarSlotNameConfig GetBPSlotNameConfigType(class UBackpackAvatarHandle** InAvatarHandle);
	bool IsEnableItemDownload(int* ItemId);
	struct FSoftObjectPath GetBatchDefaultBodyPath();
	bool HideHeadMesh(class UMeshComponent** MasterBoneComp, class USkeletalMesh** SkeletalMesh);
	bool PutOffEquimentByResID(int* resID);
	bool PutOnEquipmentByResID(int* resID);
	int GetFakeAvatarHandleItem_InDev(int* InSlotID, int* InItemID, int* AdditionalItemID);
	bool GenerateClientDefaultAvatar(class UBattleItemHandleBase** InAvatarHandle);
	bool BPClientPostProcessViewDataMiddle();
	void ProcessGodzillaSuit();
	int GetFakeAvatarHandleItem(int* InSlotID, int* InItemID, int* AdditionalItemID);
	void CheckAvatarWhoHideWho(EAvatarSlotType SlotType, const struct FItemDefineID& resID, TArray<int>* HideSomeAvatar, TArray<int>* HideBySomeAvatar);
	void SetEquipmentPattern(EAvatarSlotType SlotType);
	void SetEquipmentColor(EAvatarSlotType SlotType, const struct FLinearColor& MaskColor1, const struct FLinearColor& MaskColor2, const struct FLinearColor& MaskColor3);
	class UBackpackAvatarItemPattern* CreateAvatarItemPattern(EAvatarSlotType* InSlotType, int* InPatternID);
	class UBackpackAvatarItemColor* CreateAvatarItemColor(EAvatarSlotType* InSlotType, int* InColorID);
	int GetEquipmentSkinItemID(int* InItemID);
	void Bp_ProcessAvatarLogicUnequipped(int SlotID, const struct FItemDefineID& OldItemID);
	void Bp_ProcessAvatarLogicEquipped(int SlotID, const struct FItemDefineID& NewItemID, const struct FItemDefineID& OldItemID);
	bool PutOnDefaultEquipment(class UBackpackAvatarHandle* ItemHandle);
	bool InitBodyMeshByHead(struct FItemDefineID* InItemID);
	void ReceiveBeginPlay();
	void Bp_EventAvatarLogicEquipped(int SlotID, const struct FItemDefineID& NewItemID, const struct FItemDefineID& OldItemID);
	void Bp_EventAvatarLogicUnequipped(int SlotID, const struct FItemDefineID& OldItemID);
	void PreHanleEquipCloth(struct FBattleItemUseTarget* Target, class UBackpackAvatarHandle** InAvatarHandle, EBattleItemUseReason* Reason);
	void ClearEventFromOnAvatarEquippedEvent();
	void OnPlayerScopeIn(bool bIsBegin);
	void OnPlayerScopeOut(bool bIsBegin);
	void OnCharacterHiddenStateChange(bool bIsHidden);
	void ExecuteUbergraph_CharacterAvatarComp2_BP(int EntryPoint);
};


}

