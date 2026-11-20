// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_PlayerCharacter_MainCity_C : public ASTExtraPlayerCharacter
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UCharFollowExComponent_C*                    CharFollowExComponent;                                     
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
	class UStaticMeshComponent*                        ScopeStaticMesh;                                           
	class UObserverCameraComponent*                    ObserverCameraFPPMode;                                     
	class UFPPSpringArmComponent*                      FPPSpringArm;                                              
	class UParticleSystemComponent*                    ParticleSystem;                                            
	class UCameraComponent*                            ScopingCamera;                                             
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
	float                                              ScopeTimeline_NewTrack_1_78F4366F444D4C9163BD20B1EDD15636; 
	TEnumAsByte<ETimelineDirection>                    ScopeTimeline__Direction_78F4366F444D4C9163BD20B1EDD15636; 
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
	struct FScriptMulticastDelegate                    OnCakePlacement;                                           
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

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_PlayerCharacter_MainCity.BP_PlayerCharacter_MainCity_C");
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
	void OnEnterStateForBp(EPawnState* State);
	void OnLeaveStateForBp(EPawnState* State);
	void ReceiveDestroyed();
	void PawnVaultServerStopCheckBluePrint();
	void PawnVaultStopBluePrint();
	void OnWeaponEquipmentUpdate();
	void SwitchSightAngledLocal(TEnumAsByte<EAngledSightType>* Type, bool* IsOnlyTurn);
	void DoAngledSight(bool IsPush);
	void ParachutePlaySound(class UAkAudioEvent** LocalAkEvent, class UAkAudioEvent** RemoteAkEvent);
	void ReceivePossessed(class AController** NewController);
	void BPReceiveRadialDamage(float* DamageReceived, class UDamageType** DamageType, struct FVector* Origin, float* Radius, struct FHitResult* HitInfo, class AController** InstigatedBy, class AActor** DamageCauser, struct FVector* ImpulseDir, float* CamerShakeScale);
	void PlayScopeInTimeline(float Rate);
	void DoNormalSight(bool IsPush);
	void ScopeInStop();
	void PawnVaultAllBluePrint(float* dis, float* Height, float* Length, struct FString* VaultKey, struct FVector* StartPos, class AActor** checkActor, float* crossblockMaxFall, float* crossblockMaxDis, struct FVector* HitPoint, struct FRotator* MoveDir);
	void PawnVaultServerBluePrint(float* dis, float* Height, float* Length, struct FString* VaultKey, struct FVector* StartPos, class AActor** checkActor, float* crossblockMaxFall, float* crossblockMaxDis, struct FVector* HitPoint, class AActor** WindowActor, struct FRotator* MoveDir);
	void OnUnEquipWeapon();
	void OnPetOwnerPossessed();
	void StopSwitchAngledSight();
	void ParachuteOnWater();
	void BPReceiveDamage(float* Damage, class UDamageType** DamageType, class AController** InstigatedBy, class AActor** DamageCauser, TEnumAsByte<EDamageType>* DamageEventType);
	void CustomEvent_4(class ASTExtraShootWeapon* Weapon, EWeaponAttachmentSocketType Type, bool bEquip);
	void EnablePet(bool* Enable);
	void CustomEvent_1(bool bIsBegin);
	void OnPoseStateChange(TEnumAsByte<ESTEPoseState>* LastState, TEnumAsByte<ESTEPoseState>* CurState);
	void OnLanded(struct FHitResult* Hit);
	void OnNotifyHurt();
	void OnEquipWeapon(TEnumAsByte<ESurviveWeaponPropSlot>* Slot);
	void OnVehicleStateChange();
	void OnHitByCake();
	void OnBPStateCheckIn();
	void LuaReceiveBeginPlay();
	void SwitchRearSight(int PrevIndex, int NewIndex, const struct FRotator& AngleRotator);
	void ReloadEvent();
	void BPNotifyStartDying(class AController** Killer, class AActor** DamageCauser, struct FHitResult* KillingHitInfo, struct FVector* KillingHitImpulseDir, class UClass** KillingHitDamageType);
	void ReceiveBeginPlay();
	void BPOnRespawned();
	void RemoveRemainingCameraBlood(int SeatType);
	void StateEnterHandler_Event_1(EPawnState State);
	void BindAndExecStateChanged();
	void DoWeaponSight();
	void SetWeaponSightStateLocal(bool* IsOpenWeaponSight);
	void RearSightTimeLineUpdate(float* Alpha);
	void RearSightTimeLineFinish(int* InRearSightNewIndex);
	void AngleSightTimeLineUpdate(float* Alpha);
	void AngleSightTimeLineFinish();
	void DoAutoReloadCurrentWeapon(class ASTExtraShootWeapon** ShootWeapon);
	void ExecuteUbergraph_BP_PlayerCharacter_MainCity(int EntryPoint);
	void OnCakePlacement__DelegateSignature(bool Success);
};


}

