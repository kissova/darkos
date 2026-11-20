// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

TArray<int> UCharacterAvatarComp2_BP_C::GetHeadIgnoreSlots(int* InItemHeadID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetHeadIgnoreSlots");

	UCharacterAvatarComp2_BP_C_GetHeadIgnoreSlots_Params params;
	params.InItemHeadID = InItemHeadID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::CanUseDefaultAvatarHandleItem(int* InSlotID, int* InItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.CanUseDefaultAvatarHandleItem");

	UCharacterAvatarComp2_BP_C_CanUseDefaultAvatarHandleItem_Params params;
	params.InSlotID = InSlotID;
	params.InItemID = InItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

int UCharacterAvatarComp2_BP_C::GetDefaultAvatarHandleItem(int* InSlotID, int* InItemID, int* AdditionalItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetDefaultAvatarHandleItem");

	UCharacterAvatarComp2_BP_C_GetDefaultAvatarHandleItem_Params params;
	params.InSlotID = InSlotID;
	params.InItemID = InItemID;
	params.AdditionalItemID = AdditionalItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UCharacterAvatarComp2_BP_C::PrintDefaultConfig()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.PrintDefaultConfig");

	UCharacterAvatarComp2_BP_C_PrintDefaultConfig_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::HandleCharacterHiddenChange(bool bHidden)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.HandleCharacterHiddenChange");

	UCharacterAvatarComp2_BP_C_HandleCharacterHiddenChange_Params params;
	params.bHidden = bHidden;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::HandlePlayerScopeInOrOut(bool bScopeIn)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.HandlePlayerScopeInOrOut");

	UCharacterAvatarComp2_BP_C_HandlePlayerScopeInOrOut_Params params;
	params.bScopeIn = bScopeIn;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::EnableAvatarAnimation(bool IsEnable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.EnableAvatarAnimation");

	UCharacterAvatarComp2_BP_C_EnableAvatarAnimation_Params params;
	params.IsEnable = IsEnable;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

int UCharacterAvatarComp2_BP_C::GetRepalceIDOnVehicle(int* OriginID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetRepalceIDOnVehicle");

	UCharacterAvatarComp2_BP_C_GetRepalceIDOnVehicle_Params params;
	params.OriginID = OriginID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EAvatarSlotNameConfig UCharacterAvatarComp2_BP_C::GetBPSlotNameConfigType(class UBackpackAvatarHandle** InAvatarHandle)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetBPSlotNameConfigType");

	UCharacterAvatarComp2_BP_C_GetBPSlotNameConfigType_Params params;
	params.InAvatarHandle = InAvatarHandle;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::IsEnableItemDownload(int* ItemId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.IsEnableItemDownload");

	UCharacterAvatarComp2_BP_C_IsEnableItemDownload_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FSoftObjectPath UCharacterAvatarComp2_BP_C::GetBatchDefaultBodyPath()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetBatchDefaultBodyPath");

	UCharacterAvatarComp2_BP_C_GetBatchDefaultBodyPath_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::HideHeadMesh(class UMeshComponent** MasterBoneComp, class USkeletalMesh** SkeletalMesh)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.HideHeadMesh");

	UCharacterAvatarComp2_BP_C_HideHeadMesh_Params params;
	params.MasterBoneComp = MasterBoneComp;
	params.SkeletalMesh = SkeletalMesh;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::PutOffEquimentByResID(int* resID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.PutOffEquimentByResID");

	UCharacterAvatarComp2_BP_C_PutOffEquimentByResID_Params params;
	params.resID = resID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::PutOnEquipmentByResID(int* resID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.PutOnEquipmentByResID");

	UCharacterAvatarComp2_BP_C_PutOnEquipmentByResID_Params params;
	params.resID = resID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

int UCharacterAvatarComp2_BP_C::GetFakeAvatarHandleItem_InDev(int* InSlotID, int* InItemID, int* AdditionalItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetFakeAvatarHandleItem_InDev");

	UCharacterAvatarComp2_BP_C_GetFakeAvatarHandleItem_InDev_Params params;
	params.InSlotID = InSlotID;
	params.InItemID = InItemID;
	params.AdditionalItemID = AdditionalItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::GenerateClientDefaultAvatar(class UBattleItemHandleBase** InAvatarHandle)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GenerateClientDefaultAvatar");

	UCharacterAvatarComp2_BP_C_GenerateClientDefaultAvatar_Params params;
	params.InAvatarHandle = InAvatarHandle;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

bool UCharacterAvatarComp2_BP_C::BPClientPostProcessViewDataMiddle()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.BPClientPostProcessViewDataMiddle");

	UCharacterAvatarComp2_BP_C_BPClientPostProcessViewDataMiddle_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UCharacterAvatarComp2_BP_C::ProcessGodzillaSuit()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.ProcessGodzillaSuit");

	UCharacterAvatarComp2_BP_C_ProcessGodzillaSuit_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

int UCharacterAvatarComp2_BP_C::GetFakeAvatarHandleItem(int* InSlotID, int* InItemID, int* AdditionalItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetFakeAvatarHandleItem");

	UCharacterAvatarComp2_BP_C_GetFakeAvatarHandleItem_Params params;
	params.InSlotID = InSlotID;
	params.InItemID = InItemID;
	params.AdditionalItemID = AdditionalItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

void UCharacterAvatarComp2_BP_C::CheckAvatarWhoHideWho(EAvatarSlotType SlotType, const struct FItemDefineID& resID, TArray<int>* HideSomeAvatar, TArray<int>* HideBySomeAvatar)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.CheckAvatarWhoHideWho");

	UCharacterAvatarComp2_BP_C_CheckAvatarWhoHideWho_Params params;
	params.SlotType = SlotType;
	params.resID = resID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (HideSomeAvatar != nullptr)
		*HideSomeAvatar = params.HideSomeAvatar;
	if (HideBySomeAvatar != nullptr)
		*HideBySomeAvatar = params.HideBySomeAvatar;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::SetEquipmentPattern(EAvatarSlotType SlotType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.SetEquipmentPattern");

	UCharacterAvatarComp2_BP_C_SetEquipmentPattern_Params params;
	params.SlotType = SlotType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void UCharacterAvatarComp2_BP_C::SetEquipmentColor(EAvatarSlotType SlotType, const struct FLinearColor& MaskColor1, const struct FLinearColor& MaskColor2, const struct FLinearColor& MaskColor3)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.SetEquipmentColor");

	UCharacterAvatarComp2_BP_C_SetEquipmentColor_Params params;
	params.SlotType = SlotType;
	params.MaskColor1 = MaskColor1;
	params.MaskColor2 = MaskColor2;
	params.MaskColor3 = MaskColor3;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

class UBackpackAvatarItemPattern* UCharacterAvatarComp2_BP_C::CreateAvatarItemPattern(EAvatarSlotType* InSlotType, int* InPatternID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.CreateAvatarItemPattern");

	UCharacterAvatarComp2_BP_C_CreateAvatarItemPattern_Params params;
	params.InSlotType = InSlotType;
	params.InPatternID = InPatternID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

class UBackpackAvatarItemColor* UCharacterAvatarComp2_BP_C::CreateAvatarItemColor(EAvatarSlotType* InSlotType, int* InColorID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.CreateAvatarItemColor");

	UCharacterAvatarComp2_BP_C_CreateAvatarItemColor_Params params;
	params.InSlotType = InSlotType;
	params.InColorID = InColorID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

int UCharacterAvatarComp2_BP_C::GetEquipmentSkinItemID(int* InItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.GetEquipmentSkinItemID");

	UCharacterAvatarComp2_BP_C_GetEquipmentSkinItemID_Params params;
	params.InItemID = InItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

void UCharacterAvatarComp2_BP_C::Bp_ProcessAvatarLogicUnequipped(int SlotID, const struct FItemDefineID& OldItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.Bp_ProcessAvatarLogicUnequipped");

	UCharacterAvatarComp2_BP_C_Bp_ProcessAvatarLogicUnequipped_Params params;
	params.SlotID = SlotID;
	params.OldItemID = OldItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UCharacterAvatarComp2_BP_C::Bp_ProcessAvatarLogicEquipped(int SlotID, const struct FItemDefineID& NewItemID, const struct FItemDefineID& OldItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.Bp_ProcessAvatarLogicEquipped");

	UCharacterAvatarComp2_BP_C_Bp_ProcessAvatarLogicEquipped_Params params;
	params.SlotID = SlotID;
	params.NewItemID = NewItemID;
	params.OldItemID = OldItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::PutOnDefaultEquipment(class UBackpackAvatarHandle* ItemHandle)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.PutOnDefaultEquipment");

	UCharacterAvatarComp2_BP_C_PutOnDefaultEquipment_Params params;
	params.ItemHandle = ItemHandle;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool UCharacterAvatarComp2_BP_C::InitBodyMeshByHead(struct FItemDefineID* InItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.InitBodyMeshByHead");

	UCharacterAvatarComp2_BP_C_InitBodyMeshByHead_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (InItemID != nullptr)
		*InItemID = params.InItemID;

	return params.ReturnValue;
}


 
 

void UCharacterAvatarComp2_BP_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.ReceiveBeginPlay");

	UCharacterAvatarComp2_BP_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UCharacterAvatarComp2_BP_C::Bp_EventAvatarLogicEquipped(int SlotID, const struct FItemDefineID& NewItemID, const struct FItemDefineID& OldItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.Bp_EventAvatarLogicEquipped");

	UCharacterAvatarComp2_BP_C_Bp_EventAvatarLogicEquipped_Params params;
	params.SlotID = SlotID;
	params.NewItemID = NewItemID;
	params.OldItemID = OldItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UCharacterAvatarComp2_BP_C::Bp_EventAvatarLogicUnequipped(int SlotID, const struct FItemDefineID& OldItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.Bp_EventAvatarLogicUnequipped");

	UCharacterAvatarComp2_BP_C_Bp_EventAvatarLogicUnequipped_Params params;
	params.SlotID = SlotID;
	params.OldItemID = OldItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UCharacterAvatarComp2_BP_C::PreHanleEquipCloth(struct FBattleItemUseTarget* Target, class UBackpackAvatarHandle** InAvatarHandle, EBattleItemUseReason* Reason)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.PreHanleEquipCloth");

	UCharacterAvatarComp2_BP_C_PreHanleEquipCloth_Params params;
	params.Target = Target;
	params.InAvatarHandle = InAvatarHandle;
	params.Reason = Reason;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCharacterAvatarComp2_BP_C::ClearEventFromOnAvatarEquippedEvent()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.ClearEventFromOnAvatarEquippedEvent");

	UCharacterAvatarComp2_BP_C_ClearEventFromOnAvatarEquippedEvent_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::OnPlayerScopeIn(bool bIsBegin)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.OnPlayerScopeIn");

	UCharacterAvatarComp2_BP_C_OnPlayerScopeIn_Params params;
	params.bIsBegin = bIsBegin;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::OnPlayerScopeOut(bool bIsBegin)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.OnPlayerScopeOut");

	UCharacterAvatarComp2_BP_C_OnPlayerScopeOut_Params params;
	params.bIsBegin = bIsBegin;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::OnCharacterHiddenStateChange(bool bIsHidden)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.OnCharacterHiddenStateChange");

	UCharacterAvatarComp2_BP_C_OnCharacterHiddenStateChange_Params params;
	params.bIsHidden = bIsHidden;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCharacterAvatarComp2_BP_C::ExecuteUbergraph_CharacterAvatarComp2_BP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CharacterAvatarComp2_BP.CharacterAvatarComp2_BP_C.ExecuteUbergraph_CharacterAvatarComp2_BP");

	UCharacterAvatarComp2_BP_C_ExecuteUbergraph_CharacterAvatarComp2_BP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

