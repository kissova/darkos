// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_PlayerLobbyPawn_C_UpdateCameraLocation_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_SetCompRotate_Params
{
	class USceneComponent*                             RotateComp;                                                
	float                                              Rotate;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_SetAddCharacterWeaponAnimListHandle_Params
{
	TArray<struct FLobbyCharacterWeaponAnimData>       addAnimData;                                               
};

 
struct ABP_PlayerLobbyPawn_C_CharEquipWeaponPendant_Params
{
	int                                                WeaponId;                                                  
	EWeaponPendantSocketType                           PendantSocketType;                                         
};

 
struct ABP_PlayerLobbyPawn_C_WeaponAllAssetLoadFinish_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_CharUnEquipWeaponByResId_Params
{
	int                                                resID;                                                     
	struct FName                                       SocketName;                                                
};

 
struct ABP_PlayerLobbyPawn_C_CharUnEquipExtraWeapon_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_SetForceUseDefaultIdle_Params
{
	bool                                               Force;                                                     
};

 
struct ABP_PlayerLobbyPawn_C_UpdateClothInten_Params
{
	float                                              leten;                                                     
};

 
struct ABP_PlayerLobbyPawn_C_UpdateClothMatParam_Params
{
	float                                              RotateSpeed;                                               
};

 
struct ABP_PlayerLobbyPawn_C_StopActionCamera_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_RotateOnTickInternal_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_GetCurrentActionID_Params
{
	int                                                ActionID;                                                  
};

 
struct ABP_PlayerLobbyPawn_C_OnAvatarAllMeshLoaded_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_TryRotateAvatar_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_SetAvatarVisibleForEmote_Params
{
	bool                                               Visible;                                                   
};

 
struct ABP_PlayerLobbyPawn_C_RequestWeaponDIYData_Params
{
	struct FString                                     InPlayerUID;                                               
	int                                                WeaponAvatarID;                                            
	int                                                InDIYPlanID;                                               
};

 
struct ABP_PlayerLobbyPawn_C_SetIsMVPMotion_Params
{
	bool                                               isMVPMotion;                                               
};

 
struct ABP_PlayerLobbyPawn_C_InitDefaultAvatarByResID_Params
{
	int                                                AGender;                                                   
	int                                                Head;                                                      
	int                                                hair;                                                      
};

 
struct ABP_PlayerLobbyPawn_C_SetClothAnimDyAlphaInst_Params
{
	float                                              Alpha;                                                     
};

 
struct ABP_PlayerLobbyPawn_C_SetClothAnimDyAlphaGrad_Params
{
	float                                              Alpha;                                                     
};

 
struct ABP_PlayerLobbyPawn_C_SetClothAnimDyAlpha_Params
{
	float                                              Alpha;                                                     
};

 
struct ABP_PlayerLobbyPawn_C_RotateOnTick_Params
{
	float                                              RotateTime;                                                
	float                                              TargetRotation;                                            
};

 
struct ABP_PlayerLobbyPawn_C_OnEndActionHandle_Params
{
	int                                                ActionID;                                                  
};

 
struct ABP_PlayerLobbyPawn_C_OnPlayActionHandle_Params
{
	int                                                ActionID;                                                  
};

 
struct ABP_PlayerLobbyPawn_C_SetConflictRuleEnable_Params
{
	bool                                               bEnableConflictRule;                                       
};

 
struct ABP_PlayerLobbyPawn_C_PutOffEquipmentBySlot_Params
{
	EAvatarSlotType                                    SlotType;                                                  
	bool                                               Result;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_PlayEmoteLoop_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_ShouldCurEmoteShowWeapon_Params
{
	bool                                               Result;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_HandleWeaponDisplayWhenPlayEmote_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_GetAllEquipmentList_Params
{
	TArray<int>                                        Result;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_SetCanRotate_Params
{
	bool                                               canRotate;                                                 
};

 
struct ABP_PlayerLobbyPawn_C_PutOffEquipmentByResID_Params
{
	int                                                resID;                                                     
	bool                                               Result;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_HideWeapon_Params
{
	bool                                               isHide;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_CharPlayEmoteByResId_Params
{
	int                                                EmoteId;                                                   
	struct FString                                     ExtraInfo;                                                 
};

 
struct ABP_PlayerLobbyPawn_C_CharUnEquipWeapon_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_CharEquipWeaponByResId_Params
{
	int                                                resID;                                                     
	bool                                               bUse;                                                      
	bool                                               bAsync;                                                    
	struct FName                                       SocketName;                                                
	class ASTExtraWeapon*                              Weapon;                                                    
};

 
struct ABP_PlayerLobbyPawn_C_GetEmoteHandle_Params
{
	int*                                               ItemId;                                                    
	class UBackpackEmoteHandle*                        ReturnValue;                                               
};

 
struct ABP_PlayerLobbyPawn_C_GetBPID_Params
{
	int                                                RowName;                                                   
	int                                                BPID;                                                      
};

 
struct ABP_PlayerLobbyPawn_C_UserConstructionScript_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_Timeline_0__FinishedFunc_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_Timeline_0__UpdateFunc_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_ReceiveTick_Params
{
	float*                                             DeltaSeconds;                                              
};

 
struct ABP_PlayerLobbyPawn_C_TickClothLeten_Params
{
	float                                              From;                                                      
};

 
struct ABP_PlayerLobbyPawn_C_ExecuteUbergraph_BP_PlayerLobbyPawn_Params
{
	int                                                EntryPoint;                                                
};

 
struct ABP_PlayerLobbyPawn_C_OnPreChangeEquip__DelegateSignature_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_OnSceneType2Change__DelegateSignature_Params
{
	int                                                sceneType;                                                 
};

 
struct ABP_PlayerLobbyPawn_C_OnchangeGender__DelegateSignature_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_OnChangeEquipment__DelegateSignature_Params
{
};

 
struct ABP_PlayerLobbyPawn_C_OnStopAction__DelegateSignature_Params
{
	int                                                ActionID;                                                  
};

 
struct ABP_PlayerLobbyPawn_C_OnPlayAction__DelegateSignature_Params
{
	int                                                ActionID;                                                  
};

}

