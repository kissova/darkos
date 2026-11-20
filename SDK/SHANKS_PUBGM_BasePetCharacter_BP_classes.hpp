// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABasePetCharacter_BP_C : public ASTExtraFightPetCharacter
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UPetBubbleComponent_BP_C*                    PetBubbleComponent_BP;                                     
	class UPetAvatarComponent_BP_C*                    PetAvatarComponent_BP;                                     
	class USTBuffSystemComponent*                      STBuffSystem;                                              
	class UPetEntityComponent_BP_C*                    PetEntity;                                                 
	class UPetEventManagerComponent*                   PetEventManager;                                           
	float                                              Timeline_0_Track_CE2094E94B1D206C7858FC99724BAEFA;         
	TEnumAsByte<ETimelineDirection>                    Timeline_0__Direction_CE2094E94B1D206C7858FC99724BAEFA;    
	unsigned char                                      UnknownData00[0x3];                                        
	class UTimelineComponent*                          Timeline_1;                                                
	class ASTExtraPlayerController*                    OwnerCharacterController;                                  
	struct FScriptMulticastDelegate                    PetOwnerStateChangeDispatcher;                             
	TArray<int>                                        UnlockAnimIds;                                             
	class USplineComponent*                            PetParachuteSpline;                                        
	class USplineMeshComponent*                        ParachuteSpline;                                           
	bool                                               VisibilityToSet;                                           
	unsigned char                                      UnknownData01[0x7];                                        
	struct FTimerHandle                                CheckAirAttackTimer;                                       
	struct FVector                                     CurAttackArea;                                             
	bool                                               IsInAttackArea;                                            
	unsigned char                                      UnknownData02[0x3];                                        
	struct FTimerHandle                                DebugLineTimer;                                            
	bool                                               IsPlayingAppearAnim;                                       
	unsigned char                                      UnknownData03[0x3];                                        
	float                                              PetAppearTime;                                             
	float                                              PetDelayLeaveDisappearTime;                                
	unsigned char                                      UnknownData04[0x4];                                        
	struct FTimerHandle                                PetDelayLeaveDisappearTimer;                               
	bool                                               HasResetAttachByAnim;                                      
	EPawnState                                         TPlayerState;                                              
	TEnumAsByte<EPawnStateChangeType>                  TChangeType;                                               
	unsigned char                                      UnknownData05[0x1];                                        
	float                                              TeleportMinAngle;                                          
	float                                              TeleportMaxAngle;                                          
	bool                                               ShouldHideOnFirstPersonView;                               
	unsigned char                                      UnknownData06[0x3];                                        
	struct FVector                                     SwimOffset;                                                
	int                                                CountToPlayWinAnim;                                        
	int                                                MaxCountToPlayWinAnim;                                     
	float                                              IntervalToPlayWinAnim;                                     
	bool                                               bPetHidden;                                                
	bool                                               bPetExitParachuteForPlayerState;                           
	bool                                               bScopeInState;                                             
	unsigned char                                      UnknownData07[0x1];                                        
	struct FVector                                     OriginalMeshScale;                                         
	bool                                               bSkipResetVisibilityWhenStateChange;                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BasePetCharacter_BP.BasePetCharacter_BP_C");
		return pStaticClass;
	}


	void NeedUpdateTranslationInParachuteState(bool* Ret);
	void LoadAvatarLater(TArray<int>* NewParam);
	void LoadBehaviorTree();
	void ResetPetVisibility();
	void IsTeammateWithPetOwner(class ASTExtraPlayerCharacter* OtherPlayer, bool* NewParam);
	void HandleAirAttack(const struct FVector& Area, bool IsAirAttacking);
	void SetPetHidden(bool bHidden);
	void OnPetSwimmingStateChange(bool bEnter);
	void GetGameModeType(EGameModeType* GameModeType);
	void HandleOnOwnerWin();
	void OnPetOwnerFallingModeChange(bool IsFalling);
	void StopCurMontage();
	void ChangeToDefaultAttachInfo();
	void OnDelayLeaveDisappear();
	void OnPetLeaveState(TEnumAsByte<EPetState> LeaveState);
	void OnPetEnterState(TEnumAsByte<EPetState> EnterState);
	void OnPetAppearAnimEnd();
	void OnPetDisappearStateChange(bool IsEnter);
	void GetPetParachuteEquipments(TArray<int>* Out);
	void HandlePetStopParachute();
	void HandlePetStartParachute();
	void DetachFromOwnerPlayer();
	void InitPetAvatar();
	void SetPetFollowType(TEnumAsByte<EPetFollowOwnerType> Type);
	void PetHasDisappearState(bool* Out);
	void OnPetFlyAroundStateChange(bool IsEnter);
	void OnPetFollowStateChange(bool IsEnter);
	void UpdateAttachInfoByOwnerDefaultAvatar();
	void ResetAttachInfo();
	void GetPetInfo(struct FGameModePlayerPetInfo* PetInfo);
	void GetPetEntity(class UPetEntityComponent_BP_C** PetEntity);
	void DisableUnuseComponent();
	void CalcInAirAttackArea();
	void SelfPetVisibleSettingChanged(bool In);
	void OtherPetVisibleSettingChanged(bool In);
	void PetOtherVisibleSetting(bool* Out);
	void PetSelfVisibleSetting(bool* Out);
	void GetPetDefaultFollowType(TEnumAsByte<EPetFollowOwnerType>* FollowType);
	void DrawPetDebugInfo();
	void AttachToOwnerPlayer();
	void PetOwnerStopEmote(int EmoteId, int StopReason);
	void PetOwnerPlayEmote(int EmoteId);
	void AnimIdIsValid(int AnimId, bool* IsValid);
	void GetPetRspInfoWithPlayerEmoteId(int PlayerEmoteId, struct FBP_STRUCT_PetPlayerEmoteTable_type* Out_Row, bool* found);
	struct FString GetPetAnimLimitePlayerState(int* AnimId);
	TArray<int> GetPetUnlockAnimIds();
	class ASTExtraBaseCharacter* GetPetOwnerCharacter();
	void GetPetAttachInfo(struct FPetAttachInfo* AttachInfo);
	void GetPetEventManager(class UPetEventManagerComponent** PetEventManager);
	void SetOwnerCharacterPC();
	void GetOwnerCharacter(class ABP_PlayerPawn_C** OwnerCharacter);
	void SetOwnerCharacter(class ABP_PlayerPawn_C* Owner);
	void GetFollowPos(float MinRadius, float MaxRadius, struct FTransform* Out);
	void UserConstructionScript();
	void Timeline_0__FinishedFunc();
	void Timeline_0__UpdateFunc();
	void BindEvent();
	void BndEvt__PetEventManager_K2Node_ComponentBoundEvent_0_PetEventDelegate__DelegateSignature(class UPetWaitEventInfo* EventInfo);
	void PlayerStateChange(EPawnState State, TEnumAsByte<EPawnStateChangeType> ChangeType);
	void ReceiveBeginPlay();
	void PetOwnerCharacterBecomeValid();
	void UpdateSplineInfo();
	void PetStopParchute();
	void PetStartParachute();
	void OnPetStateChangeEvent(TEnumAsByte<EPetState> State, bool IsEnter);
	void OnPetMontageEvent(const struct FPetMontageData& MontageData);
	void OnAsyncLoadPetAnimRes(class UObject* LoadObject);
	void SetPetVisibility(bool* Visible);
	void OnOwnerWinEvent();
	void OnOwnerKillSomeone();
	void OnOwnerAssistKill();
	void OnMoveVoiceAround(class ASTExtraBaseCharacter* nowCharacter, const struct FVector& posVector, float showTime);
	void OnShotVoiceAround(class ASTExtraBaseCharacter* OwnerPawn, class ASTExtraShootWeapon* nowWeapon, const struct FVector& posVector, float showTime, bool isslience, bool isExplosion);
	void TriggerPetEvent(class UPetWaitEventInfo** Event);
	void NotifyBpDrawDebugLineChange(bool* Draw);
	void DebugLineTimerEvent();
	void OnPetOwnerStateInterruptEvent(EPawnState State, EPawnState InterruptedBy);
	void OnOwnerAvatarEquipped(EAvatarSlotType* SlotType, bool* IsEquipped, int* InItemID);
	void PetEnterPlane();
	void OnPetOwnerFallingModeChangeEvent(bool IsFalling);
	void OnOwnerPerspectiveChanged(bool IsFPP);
	void OnOwnerHoldGrenadeStateChange();
	void OnPetOwnerShoot(EPawnState State);
	void OnPetVisibility_EnterHide();
	void OnPetVisibility_EnterVisible();
	void OnPlayerEnterParachute();
	void OnPlayerExitParachute(EExitParachuteType exitType);
	void MyPetVisibleSettingTPP(bool BoolValue);
	void MyPetVisibleSettingFPP(bool BoolValue);
	void On(class ASTExtraBaseCharacter* DeadCharacter, class AController* Killer, class AActor* DamageCauser, const struct FHitResult& KillingHitInfo, const struct FVector& KillingHitImpulseDir, class UClass* KillingHitDamageType);
	void OnPlayerScopIN(bool bIsBegin);
	void CustomEvent(bool bIsBegin);
	void OnAvatarAllMeshLoaded_Event_1();
	void CustomEvent_2(bool bIsBegin);
	void CustomEvent_3(bool bIsBegin);
	void OnPlayerRespawned(class AUAEPlayerController* PlayerController);
	void OnRep_AttachToPetOwner();
	void ResetMaterialIfNeed();
	void ExecuteUbergraph_BasePetCharacter_BP(int EntryPoint);
	void PetOwnerStateChangeDispatcher__DelegateSignature(EPawnState State, TEnumAsByte<EPawnStateChangeType> ChangeType);
};


}

