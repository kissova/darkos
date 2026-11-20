// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_PlayerCharacter_MainCity_C_ShowScreenDamage_Params
{
	float                                              Damage;                                                    
	TEnumAsByte<EDamageType>                           DamageEventType;                                           
};

 
struct ABP_PlayerCharacter_MainCity_C_GetBattleItemHandlePath_Params
{
	int                                                ItemId;                                                    
	struct FString                                     EmotePath;                                                 
};

 
struct ABP_PlayerCharacter_MainCity_C_RefreshWeaponSight_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_HandleOnLandedSetAutoSprint_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_ChangeParticleEffect_Params
{
	class UParticleSystemComponent*                    Particle;                                                  
	struct FVector                                     _3DScale;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_SpawnEmitterEffect_Params
{
	struct FVector                                     RelativeLocation;                                          
	class UParticleSystem*                             PSRef;                                                     
	class USceneComponent*                             AttachParent;                                              
	struct FVector                                     RelativeScale;                                             
};

 
struct ABP_PlayerCharacter_MainCity_C_GetEmoteHandlePath_Params
{
	int*                                               ItemId;                                                    
	struct FString                                     ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_Replay_IsEnemyFrameUIExisted_Params
{
	bool                                               bIsExisted;                                                
};

 
struct ABP_PlayerCharacter_MainCity_C_HandleOnLanded_Params
{
	float                                              ForceLandTime;                                             
};

 
struct ABP_PlayerCharacter_MainCity_C_GetGameModeState_Params
{
	struct FName                                       CurModeState;                                              
};

 
struct ABP_PlayerCharacter_MainCity_C_SetTpCameraFov_Params
{
	float                                              FOV;                                                       
};

 
struct ABP_PlayerCharacter_MainCity_C_SetCapsuleParentBounds_Params
{
	bool                                               UseParentBounds;                                           
};

 
struct ABP_PlayerCharacter_MainCity_C_ClearDecalBakingRTCache_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_IsAngledSightAvailable_Params
{
	bool                                               ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_RefreshAngledSightUI_Params
{
	bool                                               HaveAngledSight;                                           
	bool                                               IsAngledSight;                                             
};

 
struct ABP_PlayerCharacter_MainCity_C_ShowAngledSightState_Params
{
	bool                                               IsAngled;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_GetAngledSightRotator_Params
{
	class ASTExtraShootWeapon*                         NewParam;                                                  
	struct FRotator                                    NewParam1;                                                 
};

 
struct ABP_PlayerCharacter_MainCity_C_AngledSightAnimLogic_Params
{
	TEnumAsByte<EAngledSightType>                      Selection;                                                 
};

 
struct ABP_PlayerCharacter_MainCity_C_AngledSightAnimUpdate_Params
{
	float                                              InputPin;                                                  
	bool                                               bIsOnlyTurn;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_Replay_CreateEnemyFrameUI_Params
{
	bool                                               isPlayingCompletePlayback;                                 
	bool                                               is_enemy;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_Replay_SetVisiableOfFrameUI_Params
{
	bool                                               is_Visiable;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_UpdateEmoteWeaponIdInfo_Params
{
	int                                                ID;                                                        
	bool                                               Ret;                                                       
};

 
struct ABP_PlayerCharacter_MainCity_C_AllowWater_Params
{
	bool                                               bCanEnter;                                                 
};

 
struct ABP_PlayerCharacter_MainCity_C_ShouldRedBlood_Params
{
	bool                                               ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_CheckHasVehicleAvatar_Params
{
	class ASTExtraVehicleBase*                         InVehicle;                                                 
	class ASTExtraBaseCharacter*                       PlayerCharacter;                                           
	int                                                InItemID;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_ChangeCurVehicleAvatar_Params
{
	class ASTExtraVehicleBase*                         InVehicle;                                                 
};

 
struct ABP_PlayerCharacter_MainCity_C_HandleOnChangedVehicleSeat_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_GetMasterBoneComponent_Params
{
	class UMeshComponent*                              MasterBoneComponent;                                       
};

 
struct ABP_PlayerCharacter_MainCity_C_InitDefaultAvatarByResID_Params
{
	int                                                AGender;                                                   
	int                                                Head;                                                      
	int                                                hair;                                                      
};

 
struct ABP_PlayerCharacter_MainCity_C_GetGrenadeCameraShakeByDir_Params
{
	struct FVector                                     ImpulseDir;                                                
	class UClass*                                      RetVar;                                                    
};

 
struct ABP_PlayerCharacter_MainCity_C_GetEmoteHandle_Params
{
	int*                                               ItemId;                                                    
	class UBackpackEmoteHandle*                        ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetShootWeaponNameByWeapon_Params
{
	int*                                               ItemDefineID;                                              
	struct FString                                     ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetThirdPersonCamera_Params
{
	class UCameraComponent*                            ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetThirdPersonSpringArm_Params
{
	class USpringArmComponent*                         ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetFPPCamera_Params
{
	class UCameraComponent*                            ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetFPPSpringArm_Params
{
	class USpringArmComponent*                         ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetFirstPersonCamera_Params
{
	class UCameraComponent*                            ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetFirstPersonSpringArm_Params
{
	class USpringArmComponent*                         ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetScopeCamera_Params
{
	class UCameraComponent*                            ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetScopeSpringArm_Params
{
	class USpringArmComponent*                         ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_ShouldAutoScopeWhenPeek_Params
{
	bool                                               ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_GetControllerViewCamera_Params
{
	class UCameraComponent*                            Camera;                                                    
};

 
struct ABP_PlayerCharacter_MainCity_C_HandleOnDetachedVehicle_Params
{
	class ASTExtraVehicleBase*                         NewParam;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_HandleOnAttachedVehicle_Params
{
	class ASTExtraVehicleBase*                         InVehicle;                                                 
};

 
struct ABP_PlayerCharacter_MainCity_C_GetActiveSpringArm_Params
{
	class USpringArmComponent*                         ReturnValue;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_AimInterupted_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_GetWeapon_Params
{
	struct FVector                                     NewParam;                                                  
	struct FRotator                                    NewParam1;                                                 
	bool                                               bHaveWeapon;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_ResetBPCameraSetting_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_ShowDebugArrow_Params
{
	class USceneComponent*                             self2;                                                     
	struct FRotator                                    InRot;                                                     
	struct FLinearColor                                Color;                                                     
};

 
struct ABP_PlayerCharacter_MainCity_C_IsAutonomous_Params
{
	bool                                               NewParam;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_PickUp_Params
{
	class APickUpWrapperActor*                         NewParam;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_DoPickUpTarget_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_RotateMesh_Params
{
	struct FRotator                                    NewParam;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_SetAllCollisionEnabled_Params
{
	bool                                               bEnable;                                                   
};

 
struct ABP_PlayerCharacter_MainCity_C_MoveOutScope_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_MoveInScope_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_Reload_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_SwitchCrouch_Params
{
	TEnumAsByte<ESTEPoseState>                         NewParam;                                                  
	TEnumAsByte<ESTEPoseState>                         preState;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_UserConstructionScript_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_ScopeTimeline__FinishedFunc_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_ScopeTimeline__UpdateFunc_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_OnEnterStateForBp_Params
{
	EPawnState*                                        State;                                                     
};

 
struct ABP_PlayerCharacter_MainCity_C_OnLeaveStateForBp_Params
{
	EPawnState*                                        State;                                                     
};

 
struct ABP_PlayerCharacter_MainCity_C_ReceiveDestroyed_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_PawnVaultServerStopCheckBluePrint_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_PawnVaultStopBluePrint_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_OnWeaponEquipmentUpdate_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_SwitchSightAngledLocal_Params
{
	TEnumAsByte<EAngledSightType>*                     Type;                                                      
	bool*                                              IsOnlyTurn;                                                
};

 
struct ABP_PlayerCharacter_MainCity_C_DoAngledSight_Params
{
	bool                                               IsPush;                                                    
};

 
struct ABP_PlayerCharacter_MainCity_C_ParachutePlaySound_Params
{
	class UAkAudioEvent**                              LocalAkEvent;                                              
	class UAkAudioEvent**                              RemoteAkEvent;                                             
};

 
struct ABP_PlayerCharacter_MainCity_C_ReceivePossessed_Params
{
	class AController**                                NewController;                                             
};

 
struct ABP_PlayerCharacter_MainCity_C_BPReceiveRadialDamage_Params
{
	float*                                             DamageReceived;                                            
	class UDamageType**                                DamageType;                                                
	struct FVector*                                    Origin;                                                    
	float*                                             Radius;                                                    
	struct FHitResult*                                 HitInfo;                                                   
	class AController**                                InstigatedBy;                                              
	class AActor**                                     DamageCauser;                                              
	struct FVector*                                    ImpulseDir;                                                
	float*                                             CamerShakeScale;                                           
};

 
struct ABP_PlayerCharacter_MainCity_C_PlayScopeInTimeline_Params
{
	float                                              Rate;                                                      
};

 
struct ABP_PlayerCharacter_MainCity_C_DoNormalSight_Params
{
	bool                                               IsPush;                                                    
};

 
struct ABP_PlayerCharacter_MainCity_C_ScopeInStop_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_PawnVaultAllBluePrint_Params
{
	float*                                             dis;                                                       
	float*                                             Height;                                                    
	float*                                             Length;                                                    
	struct FString*                                    VaultKey;                                                  
	struct FVector*                                    StartPos;                                                  
	class AActor**                                     checkActor;                                                
	float*                                             crossblockMaxFall;                                         
	float*                                             crossblockMaxDis;                                          
	struct FVector*                                    HitPoint;                                                  
	struct FRotator*                                   MoveDir;                                                   
};

 
struct ABP_PlayerCharacter_MainCity_C_PawnVaultServerBluePrint_Params
{
	float*                                             dis;                                                       
	float*                                             Height;                                                    
	float*                                             Length;                                                    
	struct FString*                                    VaultKey;                                                  
	struct FVector*                                    StartPos;                                                  
	class AActor**                                     checkActor;                                                
	float*                                             crossblockMaxFall;                                         
	float*                                             crossblockMaxDis;                                          
	struct FVector*                                    HitPoint;                                                  
	class AActor**                                     WindowActor;                                               
	struct FRotator*                                   MoveDir;                                                   
};

 
struct ABP_PlayerCharacter_MainCity_C_OnUnEquipWeapon_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_OnPetOwnerPossessed_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_StopSwitchAngledSight_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_ParachuteOnWater_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_BPReceiveDamage_Params
{
	float*                                             Damage;                                                    
	class UDamageType**                                DamageType;                                                
	class AController**                                InstigatedBy;                                              
	class AActor**                                     DamageCauser;                                              
	TEnumAsByte<EDamageType>*                          DamageEventType;                                           
};

 
struct ABP_PlayerCharacter_MainCity_C_CustomEvent_4_Params
{
	class ASTExtraShootWeapon*                         Weapon;                                                    
	EWeaponAttachmentSocketType                        Type;                                                      
	bool                                               bEquip;                                                    
};

 
struct ABP_PlayerCharacter_MainCity_C_EnablePet_Params
{
	bool*                                              Enable;                                                    
};

 
struct ABP_PlayerCharacter_MainCity_C_CustomEvent_1_Params
{
	bool                                               bIsBegin;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_OnPoseStateChange_Params
{
	TEnumAsByte<ESTEPoseState>*                        LastState;                                                 
	TEnumAsByte<ESTEPoseState>*                        CurState;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_OnLanded_Params
{
	struct FHitResult*                                 Hit;                                                       
};

 
struct ABP_PlayerCharacter_MainCity_C_OnNotifyHurt_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_OnEquipWeapon_Params
{
	TEnumAsByte<ESurviveWeaponPropSlot>*               Slot;                                                      
};

 
struct ABP_PlayerCharacter_MainCity_C_OnVehicleStateChange_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_OnHitByCake_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_OnBPStateCheckIn_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_LuaReceiveBeginPlay_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_SwitchRearSight_Params
{
	int                                                PrevIndex;                                                 
	int                                                NewIndex;                                                  
	struct FRotator                                    AngleRotator;                                              
};

 
struct ABP_PlayerCharacter_MainCity_C_ReloadEvent_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_BPNotifyStartDying_Params
{
	class AController**                                Killer;                                                    
	class AActor**                                     DamageCauser;                                              
	struct FHitResult*                                 KillingHitInfo;                                            
	struct FVector*                                    KillingHitImpulseDir;                                      
	class UClass**                                     KillingHitDamageType;                                      
};

 
struct ABP_PlayerCharacter_MainCity_C_ReceiveBeginPlay_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_BPOnRespawned_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_RemoveRemainingCameraBlood_Params
{
	int                                                SeatType;                                                  
};

 
struct ABP_PlayerCharacter_MainCity_C_StateEnterHandler_Event_1_Params
{
	EPawnState                                         State;                                                     
};

 
struct ABP_PlayerCharacter_MainCity_C_BindAndExecStateChanged_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_DoWeaponSight_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_SetWeaponSightStateLocal_Params
{
	bool*                                              IsOpenWeaponSight;                                         
};

 
struct ABP_PlayerCharacter_MainCity_C_RearSightTimeLineUpdate_Params
{
	float*                                             Alpha;                                                     
};

 
struct ABP_PlayerCharacter_MainCity_C_RearSightTimeLineFinish_Params
{
	int*                                               InRearSightNewIndex;                                       
};

 
struct ABP_PlayerCharacter_MainCity_C_AngleSightTimeLineUpdate_Params
{
	float*                                             Alpha;                                                     
};

 
struct ABP_PlayerCharacter_MainCity_C_AngleSightTimeLineFinish_Params
{
};

 
struct ABP_PlayerCharacter_MainCity_C_DoAutoReloadCurrentWeapon_Params
{
	class ASTExtraShootWeapon**                        ShootWeapon;                                               
};

 
struct ABP_PlayerCharacter_MainCity_C_ExecuteUbergraph_BP_PlayerCharacter_MainCity_Params
{
	int                                                EntryPoint;                                                
};

 
struct ABP_PlayerCharacter_MainCity_C_OnCakePlacement__DelegateSignature_Params
{
	bool                                               Success;                                                   
};

}

