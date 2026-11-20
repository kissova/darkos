// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBackpackComponent_BP_C : public UBackpackComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BackpackComponent_BP.BackpackComponent_BP_C");
		return pStaticClass;
	}


	bool CheckItemAttrsFlag(int* ItemId, EItemAttrs* ItemAttrEnum);
	int GetItemAttrsFlag(int* ItemId);
	void ServerPlaySoundByItemOperation(const struct FItemDefineID& DefineID, EBattleItemOperationType OperationType, unsigned char Reason);
	void GetChipAssociationType(int Index, int* ChipAssociationType);
	float GetSafetyBoxCapacity();
	struct FItemDefineID NewItemDefineID(struct FItemDefineID* DefineID);
	int CheckLeftLimitCountForItem(int* InItemID, int* InCount);
	bool IsItemExist(struct FItemDefineID* DefineID);
	void GetEmptyChipSlotIdx(const struct FBattleItemData& ItemData, int SupportChipNum, int* Index);
	int GetItemSubType(int* ItemId);
	bool HasTagSub(int* ItemId, struct FName* TagName);
	void GetEquipChipNum(const struct FBattleItemData& ItemData, int* Num);
	void GetAvailableEquipChipSlot(int ChipResID, bool bFindEmptySlot, bool* IsFind, struct FBattleItemUseTarget* ItemUseTarget);
	bool IsAutoUse(int* ItemId);
	bool CheckSkillPropItemCanBePickup(class UBackpackComponent** BackpackComp, struct FItemDefineID* DefineID);
	float UpdateCapacity();
	struct FBattleItemFeatureData GetBattleItemFeatureDataByDefineID(struct FItemDefineID* DefineID);
	class UBattleItemHandleBase* NewItemHandle(struct FItemDefineID* DefineID);
	void ReceiveBeginPlay();
	void ServerPlaySound(const struct FItemDefineID& DefineID, EBattleItemOperationType OperationType, unsigned char Reason);
	void OperationFailed(const struct FItemDefineID& DefineID, EBattleItemOperationType OperationType, EBattleItemOperationFailedReason OperationFailedReason);
	void ClientPlayerSound(const struct FItemDefineID& DefineID, EBattleItemOperationType OperationType, unsigned char Reason);
	void EventAutoEquipAim(bool BoolValue);
	void EventPickClipType(int IntValue);
	void ExecuteUbergraph_BackpackComponent_BP(int EntryPoint);
};


}

