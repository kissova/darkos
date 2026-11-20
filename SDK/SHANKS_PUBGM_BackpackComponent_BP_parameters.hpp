// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBackpackComponent_BP_C_CheckItemAttrsFlag_Params
{
	int*                                               ItemId;                                                    
	EItemAttrs*                                        ItemAttrEnum;                                              
	bool                                               ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_GetItemAttrsFlag_Params
{
	int*                                               ItemId;                                                    
	int                                                ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_ServerPlaySoundByItemOperation_Params
{
	struct FItemDefineID                               DefineID;                                                  
	EBattleItemOperationType                           OperationType;                                             
	unsigned char                                      Reason;                                                    
};

 
struct UBackpackComponent_BP_C_GetChipAssociationType_Params
{
	int                                                Index;                                                     
	int                                                ChipAssociationType;                                       
};

 
struct UBackpackComponent_BP_C_GetSafetyBoxCapacity_Params
{
	float                                              ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_NewItemDefineID_Params
{
	struct FItemDefineID                               DefineID;                                                  
	struct FItemDefineID                               ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_CheckLeftLimitCountForItem_Params
{
	int*                                               InItemID;                                                  
	int*                                               InCount;                                                   
	int                                                ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_IsItemExist_Params
{
	struct FItemDefineID                               DefineID;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_GetEmptyChipSlotIdx_Params
{
	struct FBattleItemData                             ItemData;                                                  
	int                                                SupportChipNum;                                            
	int                                                Index;                                                     
};

 
struct UBackpackComponent_BP_C_GetItemSubType_Params
{
	int*                                               ItemId;                                                    
	int                                                ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_HasTagSub_Params
{
	int*                                               ItemId;                                                    
	struct FName                                       TagName;                                                   
	bool                                               ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_GetEquipChipNum_Params
{
	struct FBattleItemData                             ItemData;                                                  
	int                                                Num;                                                       
};

 
struct UBackpackComponent_BP_C_GetAvailableEquipChipSlot_Params
{
	int                                                ChipResID;                                                 
	bool                                               bFindEmptySlot;                                            
	bool                                               IsFind;                                                    
	struct FBattleItemUseTarget                        ItemUseTarget;                                             
};

 
struct UBackpackComponent_BP_C_IsAutoUse_Params
{
	int*                                               ItemId;                                                    
	bool                                               ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_CheckSkillPropItemCanBePickup_Params
{
	class UBackpackComponent**                         BackpackComp;                                              
	struct FItemDefineID*                              DefineID;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_UpdateCapacity_Params
{
	float                                              ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_GetBattleItemFeatureDataByDefineID_Params
{
	struct FItemDefineID                               DefineID;                                                  
	struct FBattleItemFeatureData                      ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_NewItemHandle_Params
{
	struct FItemDefineID                               DefineID;                                                  
	class UBattleItemHandleBase*                       ReturnValue;                                               
};

 
struct UBackpackComponent_BP_C_ReceiveBeginPlay_Params
{
};

 
struct UBackpackComponent_BP_C_ServerPlaySound_Params
{
	struct FItemDefineID                               DefineID;                                                  
	EBattleItemOperationType                           OperationType;                                             
	unsigned char                                      Reason;                                                    
};

 
struct UBackpackComponent_BP_C_OperationFailed_Params
{
	struct FItemDefineID                               DefineID;                                                  
	EBattleItemOperationType                           OperationType;                                             
	EBattleItemOperationFailedReason                   OperationFailedReason;                                     
};

 
struct UBackpackComponent_BP_C_ClientPlayerSound_Params
{
	struct FItemDefineID                               DefineID;                                                  
	EBattleItemOperationType                           OperationType;                                             
	unsigned char                                      Reason;                                                    
};

 
struct UBackpackComponent_BP_C_EventAutoEquipAim_Params
{
	bool                                               BoolValue;                                                 
};

 
struct UBackpackComponent_BP_C_EventPickClipType_Params
{
	int                                                IntValue;                                                  
};

 
struct UBackpackComponent_BP_C_ExecuteUbergraph_BackpackComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

}

