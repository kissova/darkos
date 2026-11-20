// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABasePetCharacter_BP_C_NeedUpdateTranslationInParachuteState_Params
{
	bool                                               Ret;                                                       
};

 
struct ABasePetCharacter_BP_C_LoadAvatarLater_Params
{
	TArray<int>                                        NewParam;                                                  
};

 
struct ABasePetCharacter_BP_C_LoadBehaviorTree_Params
{
};

 
struct ABasePetCharacter_BP_C_ResetPetVisibility_Params
{
};

 
struct ABasePetCharacter_BP_C_IsTeammateWithPetOwner_Params
{
	class ASTExtraPlayerCharacter*                     OtherPlayer;                                               
	bool                                               NewParam;                                                  
};

 
struct ABasePetCharacter_BP_C_HandleAirAttack_Params
{
	struct FVector                                     Area;                                                      
	bool                                               IsAirAttacking;                                            
};

 
struct ABasePetCharacter_BP_C_SetPetHidden_Params
{
	bool                                               bHidden;                                                   
};

 
struct ABasePetCharacter_BP_C_OnPetSwimmingStateChange_Params
{
	bool                                               bEnter;                                                    
};

 
struct ABasePetCharacter_BP_C_GetGameModeType_Params
{
	EGameModeType                                      GameModeType;                                              
};

 
struct ABasePetCharacter_BP_C_HandleOnOwnerWin_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetOwnerFallingModeChange_Params
{
	bool                                               IsFalling;                                                 
};

 
struct ABasePetCharacter_BP_C_StopCurMontage_Params
{
};

 
struct ABasePetCharacter_BP_C_ChangeToDefaultAttachInfo_Params
{
};

 
struct ABasePetCharacter_BP_C_OnDelayLeaveDisappear_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetLeaveState_Params
{
	TEnumAsByte<EPetState>                             LeaveState;                                                
};

 
struct ABasePetCharacter_BP_C_OnPetEnterState_Params
{
	TEnumAsByte<EPetState>                             EnterState;                                                
};

 
struct ABasePetCharacter_BP_C_OnPetAppearAnimEnd_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetDisappearStateChange_Params
{
	bool                                               IsEnter;                                                   
};

 
struct ABasePetCharacter_BP_C_GetPetParachuteEquipments_Params
{
	TArray<int>                                        Out;                                                       
};

 
struct ABasePetCharacter_BP_C_HandlePetStopParachute_Params
{
};

 
struct ABasePetCharacter_BP_C_HandlePetStartParachute_Params
{
};

 
struct ABasePetCharacter_BP_C_DetachFromOwnerPlayer_Params
{
};

 
struct ABasePetCharacter_BP_C_InitPetAvatar_Params
{
};

 
struct ABasePetCharacter_BP_C_SetPetFollowType_Params
{
	TEnumAsByte<EPetFollowOwnerType>                   Type;                                                      
};

 
struct ABasePetCharacter_BP_C_PetHasDisappearState_Params
{
	bool                                               Out;                                                       
};

 
struct ABasePetCharacter_BP_C_OnPetFlyAroundStateChange_Params
{
	bool                                               IsEnter;                                                   
};

 
struct ABasePetCharacter_BP_C_OnPetFollowStateChange_Params
{
	bool                                               IsEnter;                                                   
};

 
struct ABasePetCharacter_BP_C_UpdateAttachInfoByOwnerDefaultAvatar_Params
{
};

 
struct ABasePetCharacter_BP_C_ResetAttachInfo_Params
{
};

 
struct ABasePetCharacter_BP_C_GetPetInfo_Params
{
	struct FGameModePlayerPetInfo                      PetInfo;                                                   
};

 
struct ABasePetCharacter_BP_C_GetPetEntity_Params
{
	class UPetEntityComponent_BP_C*                    PetEntity;                                                 
};

 
struct ABasePetCharacter_BP_C_DisableUnuseComponent_Params
{
};

 
struct ABasePetCharacter_BP_C_CalcInAirAttackArea_Params
{
};

 
struct ABasePetCharacter_BP_C_SelfPetVisibleSettingChanged_Params
{
	bool                                               In;                                                        
};

 
struct ABasePetCharacter_BP_C_OtherPetVisibleSettingChanged_Params
{
	bool                                               In;                                                        
};

 
struct ABasePetCharacter_BP_C_PetOtherVisibleSetting_Params
{
	bool                                               Out;                                                       
};

 
struct ABasePetCharacter_BP_C_PetSelfVisibleSetting_Params
{
	bool                                               Out;                                                       
};

 
struct ABasePetCharacter_BP_C_GetPetDefaultFollowType_Params
{
	TEnumAsByte<EPetFollowOwnerType>                   FollowType;                                                
};

 
struct ABasePetCharacter_BP_C_DrawPetDebugInfo_Params
{
};

 
struct ABasePetCharacter_BP_C_AttachToOwnerPlayer_Params
{
};

 
struct ABasePetCharacter_BP_C_PetOwnerStopEmote_Params
{
	int                                                EmoteId;                                                   
	int                                                StopReason;                                                
};

 
struct ABasePetCharacter_BP_C_PetOwnerPlayEmote_Params
{
	int                                                EmoteId;                                                   
};

 
struct ABasePetCharacter_BP_C_AnimIdIsValid_Params
{
	int                                                AnimId;                                                    
	bool                                               IsValid;                                                   
};

 
struct ABasePetCharacter_BP_C_GetPetRspInfoWithPlayerEmoteId_Params
{
	int                                                PlayerEmoteId;                                             
	struct FBP_STRUCT_PetPlayerEmoteTable_type         Out_Row;                                                   
	bool                                               found;                                                     
};

 
struct ABasePetCharacter_BP_C_GetPetAnimLimitePlayerState_Params
{
	int*                                               AnimId;                                                    
	struct FString                                     ReturnValue;                                               
};

 
struct ABasePetCharacter_BP_C_GetPetUnlockAnimIds_Params
{
	TArray<int>                                        ReturnValue;                                               
};

 
struct ABasePetCharacter_BP_C_GetPetOwnerCharacter_Params
{
	class ASTExtraBaseCharacter*                       ReturnValue;                                               
};

 
struct ABasePetCharacter_BP_C_GetPetAttachInfo_Params
{
	struct FPetAttachInfo                              AttachInfo;                                                
};

 
struct ABasePetCharacter_BP_C_GetPetEventManager_Params
{
	class UPetEventManagerComponent*                   PetEventManager;                                           
};

 
struct ABasePetCharacter_BP_C_SetOwnerCharacterPC_Params
{
};

 
struct ABasePetCharacter_BP_C_GetOwnerCharacter_Params
{
	class ABP_PlayerPawn_C*                            OwnerCharacter;                                            
};

 
struct ABasePetCharacter_BP_C_SetOwnerCharacter_Params
{
	class ABP_PlayerPawn_C*                            Owner;                                                     
};

 
struct ABasePetCharacter_BP_C_GetFollowPos_Params
{
	float                                              MinRadius;                                                 
	float                                              MaxRadius;                                                 
	struct FTransform                                  Out;                                                       
};

 
struct ABasePetCharacter_BP_C_UserConstructionScript_Params
{
};

 
struct ABasePetCharacter_BP_C_Timeline_0__FinishedFunc_Params
{
};

 
struct ABasePetCharacter_BP_C_Timeline_0__UpdateFunc_Params
{
};

 
struct ABasePetCharacter_BP_C_BindEvent_Params
{
};

 
struct ABasePetCharacter_BP_C_BndEvt__PetEventManager_K2Node_ComponentBoundEvent_0_PetEventDelegate__DelegateSignature_Params
{
	class UPetWaitEventInfo*                           EventInfo;                                                 
};

 
struct ABasePetCharacter_BP_C_PlayerStateChange_Params
{
	EPawnState                                         State;                                                     
	TEnumAsByte<EPawnStateChangeType>                  ChangeType;                                                
};

 
struct ABasePetCharacter_BP_C_ReceiveBeginPlay_Params
{
};

 
struct ABasePetCharacter_BP_C_PetOwnerCharacterBecomeValid_Params
{
};

 
struct ABasePetCharacter_BP_C_UpdateSplineInfo_Params
{
};

 
struct ABasePetCharacter_BP_C_PetStopParchute_Params
{
};

 
struct ABasePetCharacter_BP_C_PetStartParachute_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetStateChangeEvent_Params
{
	TEnumAsByte<EPetState>                             State;                                                     
	bool                                               IsEnter;                                                   
};

 
struct ABasePetCharacter_BP_C_OnPetMontageEvent_Params
{
	struct FPetMontageData                             MontageData;                                               
};

 
struct ABasePetCharacter_BP_C_OnAsyncLoadPetAnimRes_Params
{
	class UObject*                                     LoadObject;                                                
};

 
struct ABasePetCharacter_BP_C_SetPetVisibility_Params
{
	bool*                                              Visible;                                                   
};

 
struct ABasePetCharacter_BP_C_OnOwnerWinEvent_Params
{
};

 
struct ABasePetCharacter_BP_C_OnOwnerKillSomeone_Params
{
};

 
struct ABasePetCharacter_BP_C_OnOwnerAssistKill_Params
{
};

 
struct ABasePetCharacter_BP_C_OnMoveVoiceAround_Params
{
	class ASTExtraBaseCharacter*                       nowCharacter;                                              
	struct FVector                                     posVector;                                                 
	float                                              showTime;                                                  
};

 
struct ABasePetCharacter_BP_C_OnShotVoiceAround_Params
{
	class ASTExtraBaseCharacter*                       OwnerPawn;                                                 
	class ASTExtraShootWeapon*                         nowWeapon;                                                 
	struct FVector                                     posVector;                                                 
	float                                              showTime;                                                  
	bool                                               isslience;                                                 
	bool                                               isExplosion;                                               
};

 
struct ABasePetCharacter_BP_C_TriggerPetEvent_Params
{
	class UPetWaitEventInfo**                          Event;                                                     
};

 
struct ABasePetCharacter_BP_C_NotifyBpDrawDebugLineChange_Params
{
	bool*                                              Draw;                                                      
};

 
struct ABasePetCharacter_BP_C_DebugLineTimerEvent_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetOwnerStateInterruptEvent_Params
{
	EPawnState                                         State;                                                     
	EPawnState                                         InterruptedBy;                                             
};

 
struct ABasePetCharacter_BP_C_OnOwnerAvatarEquipped_Params
{
	EAvatarSlotType*                                   SlotType;                                                  
	bool*                                              IsEquipped;                                                
	int*                                               InItemID;                                                  
};

 
struct ABasePetCharacter_BP_C_PetEnterPlane_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetOwnerFallingModeChangeEvent_Params
{
	bool                                               IsFalling;                                                 
};

 
struct ABasePetCharacter_BP_C_OnOwnerPerspectiveChanged_Params
{
	bool                                               IsFPP;                                                     
};

 
struct ABasePetCharacter_BP_C_OnOwnerHoldGrenadeStateChange_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetOwnerShoot_Params
{
	EPawnState                                         State;                                                     
};

 
struct ABasePetCharacter_BP_C_OnPetVisibility_EnterHide_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPetVisibility_EnterVisible_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPlayerEnterParachute_Params
{
};

 
struct ABasePetCharacter_BP_C_OnPlayerExitParachute_Params
{
	EExitParachuteType                                 exitType;                                                  
};

 
struct ABasePetCharacter_BP_C_MyPetVisibleSettingTPP_Params
{
	bool                                               BoolValue;                                                 
};

 
struct ABasePetCharacter_BP_C_MyPetVisibleSettingFPP_Params
{
	bool                                               BoolValue;                                                 
};

 
struct ABasePetCharacter_BP_C_On_Params
{
	class ASTExtraBaseCharacter*                       DeadCharacter;                                             
	class AController*                                 Killer;                                                    
	class AActor*                                      DamageCauser;                                              
	struct FHitResult                                  KillingHitInfo;                                            
	struct FVector                                     KillingHitImpulseDir;                                      
	class UClass*                                      KillingHitDamageType;                                      
};

 
struct ABasePetCharacter_BP_C_OnPlayerScopIN_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct ABasePetCharacter_BP_C_CustomEvent_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct ABasePetCharacter_BP_C_OnAvatarAllMeshLoaded_Event_1_Params
{
};

 
struct ABasePetCharacter_BP_C_CustomEvent_2_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct ABasePetCharacter_BP_C_CustomEvent_3_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct ABasePetCharacter_BP_C_OnPlayerRespawned_Params
{
	class AUAEPlayerController*                        PlayerController;                                          
};

 
struct ABasePetCharacter_BP_C_OnRep_AttachToPetOwner_Params
{
};

 
struct ABasePetCharacter_BP_C_ResetMaterialIfNeed_Params
{
};

 
struct ABasePetCharacter_BP_C_ExecuteUbergraph_BasePetCharacter_BP_Params
{
	int                                                EntryPoint;                                                
};

 
struct ABasePetCharacter_BP_C_PetOwnerStateChangeDispatcher__DelegateSignature_Params
{
	EPawnState                                         State;                                                     
	TEnumAsByte<EPawnStateChangeType>                  ChangeType;                                                
};

}

