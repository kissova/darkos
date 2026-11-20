// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UCharacterAvatarComp2_BP_C_GetHeadIgnoreSlots_Params
{
	int*                                               InItemHeadID;                                              
	TArray<int>                                        ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_CanUseDefaultAvatarHandleItem_Params
{
	int*                                               InSlotID;                                                  
	int*                                               InItemID;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_GetDefaultAvatarHandleItem_Params
{
	int*                                               InSlotID;                                                  
	int*                                               InItemID;                                                  
	int*                                               AdditionalItemID;                                          
	int                                                ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_PrintDefaultConfig_Params
{
};

 
struct UCharacterAvatarComp2_BP_C_HandleCharacterHiddenChange_Params
{
	bool                                               bHidden;                                                   
};

 
struct UCharacterAvatarComp2_BP_C_HandlePlayerScopeInOrOut_Params
{
	bool                                               bScopeIn;                                                  
};

 
struct UCharacterAvatarComp2_BP_C_EnableAvatarAnimation_Params
{
	bool                                               IsEnable;                                                  
};

 
struct UCharacterAvatarComp2_BP_C_GetRepalceIDOnVehicle_Params
{
	int*                                               OriginID;                                                  
	int                                                ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_GetBPSlotNameConfigType_Params
{
	class UBackpackAvatarHandle**                      InAvatarHandle;                                            
	EAvatarSlotNameConfig                              ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_IsEnableItemDownload_Params
{
	int*                                               ItemId;                                                    
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_GetBatchDefaultBodyPath_Params
{
	struct FSoftObjectPath                             ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_HideHeadMesh_Params
{
	class UMeshComponent**                             MasterBoneComp;                                            
	class USkeletalMesh**                              SkeletalMesh;                                              
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_PutOffEquimentByResID_Params
{
	int*                                               resID;                                                     
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_PutOnEquipmentByResID_Params
{
	int*                                               resID;                                                     
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_GetFakeAvatarHandleItem_InDev_Params
{
	int*                                               InSlotID;                                                  
	int*                                               InItemID;                                                  
	int*                                               AdditionalItemID;                                          
	int                                                ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_GenerateClientDefaultAvatar_Params
{
	class UBattleItemHandleBase**                      InAvatarHandle;                                            
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_BPClientPostProcessViewDataMiddle_Params
{
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_ProcessGodzillaSuit_Params
{
};

 
struct UCharacterAvatarComp2_BP_C_GetFakeAvatarHandleItem_Params
{
	int*                                               InSlotID;                                                  
	int*                                               InItemID;                                                  
	int*                                               AdditionalItemID;                                          
	int                                                ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_CheckAvatarWhoHideWho_Params
{
	EAvatarSlotType                                    SlotType;                                                  
	struct FItemDefineID                               resID;                                                     
	TArray<int>                                        HideSomeAvatar;                                            
	TArray<int>                                        HideBySomeAvatar;                                          
};

 
struct UCharacterAvatarComp2_BP_C_SetEquipmentPattern_Params
{
	EAvatarSlotType                                    SlotType;                                                  
};

 
struct UCharacterAvatarComp2_BP_C_SetEquipmentColor_Params
{
	EAvatarSlotType                                    SlotType;                                                  
	struct FLinearColor                                MaskColor1;                                                
	struct FLinearColor                                MaskColor2;                                                
	struct FLinearColor                                MaskColor3;                                                
};

 
struct UCharacterAvatarComp2_BP_C_CreateAvatarItemPattern_Params
{
	EAvatarSlotType*                                   InSlotType;                                                
	int*                                               InPatternID;                                               
	class UBackpackAvatarItemPattern*                  ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_CreateAvatarItemColor_Params
{
	EAvatarSlotType*                                   InSlotType;                                                
	int*                                               InColorID;                                                 
	class UBackpackAvatarItemColor*                    ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_GetEquipmentSkinItemID_Params
{
	int*                                               InItemID;                                                  
	int                                                ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_Bp_ProcessAvatarLogicUnequipped_Params
{
	int                                                SlotID;                                                    
	struct FItemDefineID                               OldItemID;                                                 
};

 
struct UCharacterAvatarComp2_BP_C_Bp_ProcessAvatarLogicEquipped_Params
{
	int                                                SlotID;                                                    
	struct FItemDefineID                               NewItemID;                                                 
	struct FItemDefineID                               OldItemID;                                                 
};

 
struct UCharacterAvatarComp2_BP_C_PutOnDefaultEquipment_Params
{
	class UBackpackAvatarHandle*                       ItemHandle;                                                
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_InitBodyMeshByHead_Params
{
	struct FItemDefineID                               InItemID;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UCharacterAvatarComp2_BP_C_ReceiveBeginPlay_Params
{
};

 
struct UCharacterAvatarComp2_BP_C_Bp_EventAvatarLogicEquipped_Params
{
	int                                                SlotID;                                                    
	struct FItemDefineID                               NewItemID;                                                 
	struct FItemDefineID                               OldItemID;                                                 
};

 
struct UCharacterAvatarComp2_BP_C_Bp_EventAvatarLogicUnequipped_Params
{
	int                                                SlotID;                                                    
	struct FItemDefineID                               OldItemID;                                                 
};

 
struct UCharacterAvatarComp2_BP_C_PreHanleEquipCloth_Params
{
	struct FBattleItemUseTarget*                       Target;                                                    
	class UBackpackAvatarHandle**                      InAvatarHandle;                                            
	EBattleItemUseReason*                              Reason;                                                    
};

 
struct UCharacterAvatarComp2_BP_C_ClearEventFromOnAvatarEquippedEvent_Params
{
};

 
struct UCharacterAvatarComp2_BP_C_OnPlayerScopeIn_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct UCharacterAvatarComp2_BP_C_OnPlayerScopeOut_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct UCharacterAvatarComp2_BP_C_OnCharacterHiddenStateChange_Params
{
	bool                                               bIsHidden;                                                 
};

 
struct UCharacterAvatarComp2_BP_C_ExecuteUbergraph_CharacterAvatarComp2_BP_Params
{
	int                                                EntryPoint;                                                
};

}

