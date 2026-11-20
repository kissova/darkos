// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_PlayerPawn_C : public ASTExtraPlayerCharacter
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UBP_CharacterSearchOtherComp_C*              BP_CharacterSearchOtherComp;                               
	class UStaticMeshComponent*                        ScopeStaticMesh;                                           
	class UScopeCameraComponent*                       ScopingCameraNew;                                          
	class UCharacterFollowComponent_C*                 CharacterFollowComponent;                                  
	class UCharacterAnimShareParamsComp*               CharacterAnimShareParamsComp;                              
	class UBP_PlayEmoteComponent_C*                    BP_PlayEmoteComponent;                                     
	class UCharacterBoundCapsuleComonent*              MeshBoundCapsuleComonent;                                  
	class UDynamicOptimizeCharacterComps_C*            DynamicOptimizeCharacterComps;                             
	class UBP_CharacterCarryBackComp_C*                BP_CharacterCarryBackComp;                                 
	class UBP_SkillManagerComponent_C*                 BP_SkillManagerComponent;                                  
	class UCustomCameraComponent*                      Camera;                                                    
	class UCapsuleComponent*                           ShareBounds;                                               
	class UCharacterAnimList_Skill_C*                  CharacterAnimList_Skill;                                   
	class UStaticMeshComponent*                        SCOPE;                                                     
	class UPostProcessComponent*                       PostProcess;                                               
	class USpringArmComponent*                         ShoulderCameraSpringArm;                                   
	class USceneComponent*                             ShoulderCameraOffset;                                      
	class UCharacterAnimList_Base_C*                   CharacterAnimList_Base;                                    
	class UPetComponent_BP_C*                          PetComponent_BP;                                           
	class UCharacterAvatarComp2_BP_C*                  CharacterAvatarComp2_BP;                                   
	class UObserverCameraComponent*                    ObserverCameraFPPMode;                                     
	class UFPPSpringArmComponent*                      FPPSpringArm;                                              
	class UFPPComponent_C*                             FPPComponent;                                              
	class UParticleSystemComponent*                    ParticleSystem;                                            
	class USpringArmComponent*                         ScopingSpringArm;                                          
	class UCapsuleComponent*                           HitBox_Prone;                                              
	class UCapsuleComponent*                           HitBox_Stand;                                              
	class UVault_Controller_C*                         Vault_Controller;                                          
	class UBP_SwimController_C*                        BP_SwimController;                                         
	class UBP_AutoAimingComponent_C*                   BP_AutoAimingComponent;                                    
	class UCharacterWeaponManagerComponent*            CharacterWeaponManager;                                    
	class UPickupManagerComponent*                     PickupManager;                                             
	class USceneComponent*                             CameraRoot;                                                
	class UCustomSpringArmComponent*                   CustomSpringArm;                                           
	class UCameraSettingComponent_C*                   CameraSettingComponent;                                    
	float                                              ScopeTimeline_NewTrack_1_FBCE53A7433799FDD4E08AA77C9DCE27; 
	TEnumAsByte<ETimelineDirection>                    ScopeTimeline__Direction_FBCE53A7433799FDD4E08AA77C9DCE27; 
	unsigned char                                      UnknownData00[0x3];                                        
	class UTimelineComponent*                          ScopeTimeline;                                             
	bool                                               IsReloading;                                               
	unsigned char                                      UnknownData01[0x3];                                        
	float                                              ReloadingCDMax;                                            
	bool                                               Jumped;                                                    
	TEnumAsByte<EPlayerCameraMode>                     CurCameraMode;                                             
	unsigned char                                      UnknownData02[0x2];                                        
	struct FSTR_CameraSetting                          StandCameraSetting;                                        
	struct FVector                                     Normal;                                                    
	unsigned char                                      UnknownData03[0x4];                                        
	class APickUpWrapperActor*                         PickUpTarget_1;                                            
	bool                                               bIsPicking;                                                
	unsigned char                                      UnknownData04[0x3];                                        
	float                                              DefaultCapsuleRadius;                                      
	class USkeletalMeshComponent*                      ParachuteComponent_1;                                      
	TArray<class USpringArmComponent*>                 SpringArms;                                                
	TArray<class UCameraComponent*>                    Cameras;                                                   
	class USpringArmComponent*                         CurActiveSpringArm;                                        
	class USpringArmComponent*                         NewVar_1;                                                  
	TEnumAsByte<ESTEPoseState>                         CurPoseState;                                              
	unsigned char                                      UnknownData05[0x7];                                        
	TMap<int, class UBackpackEmoteHandle*>             EmoteBPIDToAnimHandleMap;                                  
	class UParticleSystem*                             DecentBloodSpot;                                           
	class UParticleSystem*                             BloodSpot_Red;                                             
	class UParticleSystem*                             BloodSpot_Green;                                           
	TArray<EPawnState>                                 DisallowedWateringStates;                                  
	class UChildActorComponent*                        PaintDecalDetectComp;                                      
	class ASTExtraWeapon*                              CurUseingEmoteWeapon;                                      
	class UMaterialBillboardComponent*                 FrameUIBillboard;                                          
	bool                                               bIsAngledSightOnlyTurn_1;                                  
	unsigned char                                      UnknownData06[0x7];                                        
	class UMeshComponent*                              OriginAttachComponent;                                     
	class UMeshComponent*                              TargetAttachComponent;                                     
	struct FRotator                                    OriginRotOffset;                                           
	struct FDollyZoomParam                             OriginDollyZoomParam;                                      
	struct FDollyZoomParam                             TargetDollyZoomParam;                                      
	unsigned char                                      UnknownData07[0x4];                                        
	struct FName                                       HurtSoundSwitchState;                                      
	struct FVector                                     BloodScale;                                                
	unsigned char                                      UnknownData08[0x4];                                        
	struct FScriptMulticastDelegate                    OnCakePlacement;                                           
	class UPhysicsAsset*                               ShootPhysicsAssetOpt;                                      
	class UPhysicsAsset*                               ShootPhysicsAsset;                                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_PlayerPawn.BP_PlayerPawn_C");
		return pStaticClass;
	}


	void ShowScreenDamage(float Damage, TEnumAsByte<EDamageType> DamageEventType);
	void GetBattleItemHandlePath(int ItemId, struct FString* EmotePath);
	void RefreshWeaponSight();
	void HandleOnLandedSetAutoSprint();
	void ChangeParticleEffect(class UParticleSystemComponent* Particle, const struct FVector& _3DScale);
	void SpawnEmitterEffect(const struct FVector& RelativeLocation, class UParticleSystem* PSRef, class USceneComponent* AttachParent, const struct FVector& RelativeScale);
	struct FString GetEmoteHandlePath(int* ItemId);
	void Replay_IsEnemyFrameUIExisted(bool* bIsExisted);
	void HandleOnLanded(float ForceLandTime);
	void GetGameModeState(struct FName* CurModeState);
	void SetTpCameraFov(float FOV);
	void SetCapsuleParentBounds(bool UseParentBounds);
	void ClearDecalBakingRTCache();
	bool IsAngledSightAvailable();
	void RefreshAngledSightUI(bool HaveAngledSight, bool IsAngledSight);
	void ShowAngledSightState(bool IsAngled);
	void GetAngledSightRotator(class ASTExtraShootWeapon* NewParam, struct FRotator* NewParam1);
	void AngledSightAnimLogic(TEnumAsByte<EAngledSightType> Selection);
	void AngledSightAnimUpdate(float InputPin, bool bIsOnlyTurn);
	void Replay_CreateEnemyFrameUI(bool isPlayingCompletePlayback, bool is_enemy);
	void Replay_SetVisiableOfFrameUI(bool is_Visiable);
	void UpdateEmoteWeaponIdInfo(int ID, bool* Ret);
	void AllowWater(bool* bCanEnter);
	bool ShouldRedBlood();
	void CheckHasVehicleAvatar(class ASTExtraVehicleBase* InVehicle, class ASTExtraBaseCharacter* PlayerCharacter, int* InItemID);
	void ChangeCurVehicleAvatar(class ASTExtraVehicleBase* InVehicle);
	void HandleOnChangedVehicleSeat();
	void GetMasterBoneComponent(class UMeshComponent** MasterBoneComponent);
	void InitDefaultAvatarByResID(int AGender, int Head, int hair);
	void GetGrenadeCameraShakeByDir(const struct FVector& ImpulseDir, class UClass** RetVar);
	class UBackpackEmoteHandle* GetEmoteHandle(int* ItemId);
	struct FString GetShootWeaponNameByWeapon(int* ItemDefineID);
	class UCameraComponent* GetThirdPersonCamera();
	class USpringArmComponent* GetThirdPersonSpringArm();
	class UCameraComponent* GetFPPCamera();
	class USpringArmComponent* GetFPPSpringArm();
	class UCameraComponent* GetFirstPersonCamera();
	class USpringArmComponent* GetFirstPersonSpringArm();
	class UCameraComponent* GetScopeCamera();
	class USpringArmComponent* GetScopeSpringArm();
	bool ShouldAutoScopeWhenPeek();
	void GetControllerViewCamera(class UCameraComponent** Camera);
	void HandleOnDetachedVehicle(class ASTExtraVehicleBase* NewParam);
	void HandleOnAttachedVehicle(class ASTExtraVehicleBase* InVehicle);
	class USpringArmComponent* GetActiveSpringArm();
	void AimInterupted();
	void GetWeapon(struct FVector* NewParam, struct FRotator* NewParam1, bool* bHaveWeapon);
	void ResetBPCameraSetting();
	void ShowDebugArrow(class USceneComponent* self2, const struct FRotator& InRot, const struct FLinearColor& Color);
	void IsAutonomous(bool* NewParam);
	void PickUp(class APickUpWrapperActor* NewParam);
	void DoPickUpTarget();
	void RotateMesh(const struct FRotator& NewParam);
	void SetAllCollisionEnabled(bool bEnable);
	void MoveOutScope();
	void MoveInScope();
	void Reload();
	void SwitchCrouch(TEnumAsByte<ESTEPoseState> NewParam, TEnumAsByte<ESTEPoseState> preState);
	void UserConstructionScript();
	void ScopeTimeline__FinishedFunc();
	void ScopeTimeline__UpdateFunc();
	void OnPetOwnerPossessed();
	void ReceiveBeginPlay();
	void BPNotifyStartDying(class AController** Killer, class AActor** DamageCauser, struct FHitResult* KillingHitInfo, struct FVector* KillingHitImpulseDir, class UClass** KillingHitDamageType);
	void ReloadEvent();
	void OnEquipWeapon(TEnumAsByte<ESurviveWeaponPropSlot>* Slot);
	void OnNotifyHurt();
	void OnLanded(struct FHitResult* Hit);
	void OnPoseStateChange(TEnumAsByte<ESTEPoseState>* LastState, TEnumAsByte<ESTEPoseState>* CurState);
	void BPReceiveDamage(float* Damage, class UDamageType** DamageType, class AController** InstigatedBy, class AActor** DamageCauser, TEnumAsByte<EDamageType>* DamageEventType);
	void ParachuteOnWater();
	void OnUnEquipWeapon();
	void PawnVaultServerBluePrint(float* dis, float* Height, float* Length, struct FString* VaultKey, struct FVector* StartPos, class AActor** checkActor, float* crossblockMaxFall, float* crossblockMaxDis, struct FVector* HitPoint, class AActor** WindowActor, struct FRotator* MoveDir);
	void PawnVaultAllBluePrint(float* dis, float* Height, float* Length, struct FString* VaultKey, struct FVector* StartPos, class AActor** checkActor, float* crossblockMaxFall, float* crossblockMaxDis, struct FVector* HitPoint, struct FRotator* MoveDir);
	void ScopeInStop();
	void PlayScopeInTimeline(float Rate);
	void BPReceiveRadialDamage(float* DamageReceived, class UDamageType** DamageType, struct FVector* Origin, float* Radius, struct FHitResult* HitInfo, class AController** InstigatedBy, class AActor** DamageCauser, struct FVector* ImpulseDir, float* CamerShakeScale);
	void ReceivePossessed(class AController** NewController);
	void ParachutePlaySound(class UAkAudioEvent** LocalAkEvent, class UAkAudioEvent** RemoteAkEvent);
	void OnWeaponEquipmentUpdate();
	void BindAndExecStateChanged();
	void StateEnterHandler_Event_1(EPawnState State);
	void OnHitByCake();
	void EnablePet(bool* Enable);
	void OnEnterStateForBp(EPawnState* State);
	void OnLeaveStateForBp(EPawnState* State);
	void ReceiveDestroyed();
	void PawnVaultServerStopCheckBluePrint();
	void PawnVaultStopBluePrint();
	void SwitchSightAngledLocal(TEnumAsByte<EAngledSightType>* Type, bool* IsOnlyTurn);
	void DoAngledSight(bool IsPush);
	void DoNormalSight(bool IsPush);
	void StopSwitchAngledSight();
	void CustomEvent_4(class ASTExtraShootWeapon* Weapon, EWeaponAttachmentSocketType Type, bool bEquip);
	void CustomEvent_1(bool bIsBegin);
	void OnVehicleStateChange();
	void OnBPStateCheckIn();
	void LuaReceiveBeginPlay();
	void SwitchRearSight(int PrevIndex, int NewIndex, const struct FRotator& AngleRotator);
	void BPOnRespawned();
	void RemoveRemainingCameraBlood(int SeatType);
	void DoWeaponSight();
	void SetWeaponSightStateLocal(bool* IsOpenWeaponSight);
	void RearSightTimeLineUpdate(float* Alpha);
	void RearSightTimeLineFinish(int* InRearSightNewIndex);
	void AngleSightTimeLineUpdate(float* Alpha);
	void AngleSightTimeLineFinish();
	void DoAutoReloadCurrentWeapon(class ASTExtraShootWeapon** ShootWeapon);
	void ExecuteUbergraph_BP_PlayerPawn(int EntryPoint);
	void OnCakePlacement__DelegateSignature(bool Success);
};


}

