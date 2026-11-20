// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBehaviorControlComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                       
	class APawn*                                       OwnerPawn;                                                 
	class AAIController*                               AIController;                                              
	class UBehaviorTreeComponent*                      BehaviorTreeComp;                                          
	class UBlackboardComponent*                        BlackboardComp;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.BehaviorControlComponent");
		return pStaticClass;
	}


	void UnPossessed();
	void StopBehaviorTree();
	void StopBehavior(const struct FString& Reason);
	bool RunBehaviorTreeByIndex(int PathIndex);
	void ResumeBehavior(const struct FString& Reason);
	void RestartBehavior();
	void PossessedBy(class AController* NewController);
	void PauseBehavior(const struct FString& Reason);
	void OnPlayerActiveRegionsChanged(bool bEnter);
};


 
 
class UBTDecorator_Generic_HasAIState : public UBTDecorator
{
public:
	TArray<struct FGameplayTag>                        States;                                                    
	EHasAITagStateLogic                                LogicOp;                                                   
	bool                                               bExact;                                                    
	unsigned char                                      UnknownData00[0x6];                                        
	struct FBlackboardKeySelector                      BBKeyTarget;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.BTDecorator_Generic_HasAIState");
		return pStaticClass;
	}

};


 
 
class UBTService_Generic_ChooseEnemy : public UBTService
{
public:
	struct FBlackboardKeySelector                      BBKeyEnemy;                                                
	struct FBlackboardKeySelector                      BBKeyCanNotSeeTarget;                                      
	struct FBlackboardKeySelector                      BBKeyDynamicSearchRuleIndex;                               
	bool                                               bShowDebugInfo;                                            
	unsigned char                                      UnknownData00[0x3];                                        
	float                                              DebugInfoLife;                                             

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.BTService_Generic_ChooseEnemy");
		return pStaticClass;
	}

};


 
 
class UBTTask_Generic_ClearEnemy : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      BBKeyEnemy;                                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.BTTask_Generic_ClearEnemy");
		return pStaticClass;
	}

};


 
 
class AGenericAIController : public AAIController
{
public:
	unsigned char                                      UnknownData00[0x58];                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericAIController");
		return pStaticClass;
	}

};


 
 
class AGenericCharacter : public ACharacter
{
public:
	unsigned char                                      UnknownData00[0x80];                                       
	uint32_t                                           PlayerKey;                                                 
	unsigned char                                      UnknownData01[0x4];                                        
	class UStateReflectComp*                           StateReflectComp;                                          
	class UAttrModifyComponent*                        AttrModifyComp;                                            
	struct FString                                     LuaFilePath;                                               
	unsigned char                                      UnknownData02[0x8];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericCharacter");
		return pStaticClass;
	}


	void OnStateLeft(const struct FGameplayTag& State);
	void OnStateEntered(const struct FGameplayTag& State);
	void OnRep_PlayerKey();
	bool IsInObjectPool();
	bool IsAlive();
	void HandleStateLeft(const struct FGameplayTag& State);
	void HandleStateEntered(const struct FGameplayTag& State);
	class UStateReflectComp* GetStateReflectComp();
};


 
 
class UGenericChooseEnemyComponent : public UActorComponent
{
public:
	struct FGenericMonsterSensingConfig                SensingConfig;                                             
	struct FGenericSensingRuntimeState                 RuntimeState;                                              
	unsigned char                                      UnknownData00[0x4];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericChooseEnemyComponent");
		return pStaticClass;
	}


	class ACharacter* SelectFromCandidates(TArray<class ACharacter*> Filtered, EGenericSearchEnemyRule Rule);
	bool IsValidEnemy(class ACharacter* Target, bool bUseMonsterFilter, bool* bOutIsNearDeath);
	static bool IsTargetAlive(class ACharacter* Target);
	bool IsEnemyByActor(class ACharacter* InTarget);
	static float GetTargetHealth(class ACharacter* Target);
	struct FGenericMonsterSensingConfig GetSensingConfig();
	class AGenericMonsterBase* GetOwnerMonster();
	void CollectPlayerCandidates(TArray<class ACharacter*>* OutPlayers);
	void CollectMonsterCandidates(TArray<class ACharacter*>* OutMonsters);
};


 
 
class AGenericMonsterBase : public AGenericCharacter
{
public:
	unsigned char                                      UnknownData00[0x68];                                       
	struct FScriptMulticastDelegate                    OnMonsterSetPlayedIdleIndex;                               
	struct FMonsterIdleIndex                           MonsterIdleIndex;                                          
	struct FScriptMulticastDelegate                    OnMonsterHurting;                                          
	struct FScriptMulticastDelegate                    OnEnemyChanged;                                            
	float                                              WalkSpeed;                                                 
	float                                              RunSpeed;                                                  
	float                                              SpeedScale;                                                
	int                                                TeamID;                                                    
	int                                                Campid;                                                    
	int                                                MonsterLevel;                                              
	struct FString                                     CharacterName;                                             
	class UUTSkillManagerComponent*                    SkillManager;                                              
	class USTBuffSystemComponent*                      BuffSystem;                                                
	class USimulateSyncSmoothComponent*                SimulateSyncSmooth;                                        
	class UGenericChooseEnemyComponent*                ChooseEnemyComponent;                                      
	class UBehaviorControlComponent*                   BehaviorControlComp;                                       
	bool                                               bEnableSimulateSyncSmooth;                                 
	unsigned char                                      UnknownData01[0x3];                                        
	float                                              MovementTickInterval;                                      
	ERegionSizeIndex                                   RegionSize;                                                
	bool                                               bRegionStatic;                                             
	unsigned char                                      AutoDormancyType;                                          
	unsigned char                                      UnknownData02[0x1];                                        
	float                                              SpawnAnimTime;                                             
	unsigned char                                      UnknownData03[0x18];                                       
	float                                              LandDuration;                                              
	float                                              InAirVelocityThreshold;                                    
	float                                              MoveSpeedTolerance;                                        
	unsigned char                                      UnknownData04[0x4];                                        
	bool                                               bAllowVehicleKnockback;                                    
	unsigned char                                      UnknownData05[0x3];                                        
	float                                              VehicleHitLaunchPitchDeg;                                  
	float                                              VehicleHitRefMinImpulse;                                   
	float                                              VehicleHitRefMaxImpulse;                                   
	float                                              VehicleHitMinLaunchVelocity;                               
	float                                              VehicleHitMaxLaunchVelocity;                               
	bool                                               bAllowLaunchAirState;                                      
	unsigned char                                      UnknownData06[0x3];                                        
	float                                              DelayCheckLaunchAirState;                                  
	float                                              MinLaunchAirGroundTime;                                    
	float                                              MaxLaunchAirGroundTime;                                    
	float                                              LaunchAirRiseUpDuration;                                   
	unsigned char                                      UnknownData07[0x1C];                                       
	float                                              StunBeginAnimTime;                                         
	float                                              StunAnimTime;                                              
	float                                              StunRecoveryAnimTime;                                      
	unsigned char                                      UnknownData08[0x1C];                                       
	bool                                               CloseCollisionForMeshOnDS;                                 
	bool                                               bForceAnimationUpdatedOnClient;                            
	bool                                               bHideMeshUntilAnimAssetsLoaded;                            
	unsigned char                                      UnknownData09[0x1];                                        
	float                                              ShowMeshDelayAfterAnimAssetsLoaded;                        
	struct FScriptMulticastDelegate                    OnEditorKeyPressedDelegate;                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericMonsterBase");
		return pStaticClass;
	}


	void SetTeamID(int NewTeamId);
	void SetSpeedScale(float NewSpeedScale);
	void SetMonsterIdleIndex(int NewIndex);
	void SetCharacterName(const struct FString& NewCharacterName);
	void SetCampID(int NewCampID);
	class ACharacter* SelectEnemyByLua(TArray<class ACharacter*> Candidates);
	float ReviseSenseDistanceByActor(float InDistance, class AActor* InTarget);
	void ReceivedPlayerActiveRegionsChanged(bool bEnter);
	void OnSmoothComponentSnapshotPreReplicate();
	void OnRep_MonsterIdleIndex();
	void OnRep_CampID();
	void LeaveLaunchAirRiseUp();
	void LeaveLaunchAirGround();
	void LaunchCharacterWithParam(const struct FVector& LaunchVelocity, bool bChangeState);
	bool IsValidEnemyTarget(class AActor* InTarget);
	bool IsEnemyByActor(class ACharacter* InTarget);
	int GetTeamId();
	float GetSpeedScale();
	struct FGenericMonsterSensingConfig GetSensingConfig();
	int GetMonsterIdleIndex();
	float GetCurrentSpeed();
	class UGenericChooseEnemyComponent* GetChooseEnemyComponent();
	struct FString GetCharacterName();
	int GetCampId();
	class USTBuffSystemComponent* GetBuffComponent();
	void FinishStunRecovery();
	void ExitSpawnState();
	void EnterStunRecovery();
	void EnterStun();
	void DoHurting(const struct FVector& HurtDir);
	void ClearStunState();
	void ClearLaunchAirState();
	void CheckLaunchAirState();
	void ChangeWalkSpeed(EMobWalkType InWalkType);
};


 
 
class AGenericMonster : public AGenericMonsterBase
{
public:
	unsigned char                                      UnknownData00[0xA0];                                       
	float                                              HealthMax;                                                 
	float                                              Health;                                                    
	TArray<EDamageableGameObjectType>                  DamageableGameObjectTypes;                                 
	float                                              TakeDamageScale;                                           
	float                                              DamageScale;                                               
	class UCurveFloat*                                 VehicleSpeedDamageCurve;                                   
	float                                              VehicleHitDamageScale;                                     
	float                                              VehicleHitMinDamageSpeedKmh;                               
	float                                              VehicleHitRefDamageSpeedKmh;                               
	float                                              VehicleHitMinDamageImpulse;                                
	float                                              VehicleHitRefDamageImpulse;                                
	float                                              VehicleHitMinDamage;                                       
	float                                              VehicleHitMaxDamage;                                       
	float                                              DeadAnimTime;                                              
	float                                              HurtAnimTime;                                              
	unsigned char                                      IsInvincible : 1;                                          
	unsigned char                                      UnknownData01[0x1];                                        
	bool                                               bForceOpenPawnCollision;                                   
	bool                                               bShowGenericHPBar;                                         
	int                                                GenericHPBarPlanID;                                        
	int                                                CustomHPBarType;                                           
	int                                                CustomHPBarScreenMarkID;                                   
	unsigned char                                      UnknownData02[0x4];                                        
	struct FString                                     CustomHPBarUIConfig;                                       
	unsigned char                                      UnknownData03[0x10];                                       
	class UPartHitComponentBase*                       PartHitComp;                                               
	unsigned char                                      UnknownData04[0x8];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericMonster");
		return pStaticClass;
	}


	void SetTakeDamageScale(float NewTakeDamageScale);
	void SetIsInvincible(bool bInvincible, unsigned char InMaskBit);
	void SetHealthMax(float NewHealthMax);
	void SetHealth(float NewHealth);
	void SetDamageScale(float NewDamageScale);
	float OnTargetTakeDamage(class AActor* DamageTarget, float Damage, class AController* EventInstigator);
	void OnDie(class APawn* Causer);
	float HandleTargetTakeDamage(class AActor* DamageTarget, float Damage, class AController* EventInstigator);
	float GetTakeDamageScale();
	class UPartHitComponentBase* GetPartHitComponentBase();
	bool GetIsInvincible();
	float GetHealthMax();
	float GetHealth();
	float GetDamageScale();
	float CalcVehicleHitDamage(class ASTExtraVehicleBase* OtherVehicle, const struct FVector& HitImpulseDirection, float HitSpeed);
	void BPReceiveDamage(float Damage, class UDamageType* DamageType, class AController* InstigatedBy, class AActor* DamageCauser, TEnumAsByte<EDamageType> DamageEventType);
	float BPPreTakeDamage(float DamageAmount, const struct FDamageEvent& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);
};


 
 
class UGenericMonsterAnimInstance : public UDataDriverAnimInstance
{
public:
	unsigned char                                      UnknownData00[0x8];                                        
	float                                              Speed;                                                     
	float                                              RandomIdleIndex;                                           
	int                                                RandomIdleIndexInt;                                        
	unsigned char                                      UnknownData01[0x4];                                        
	struct FGameplayTag                                RandomIdleBS1DTag;                                         
	struct FVector                                     HurtDirection;                                             
	float                                              HurtingAccumulate;                                         
	bool                                               bIsHurting;                                                
	unsigned char                                      UnknownData02[0x3];                                        
	float                                              HurtingAnimPlayRate;                                       
	struct FGameplayTag                                HurtBSTag;                                                 
	TMap<struct FGameplayTag, struct FGameplayTag>     StateToMontageParamMap;                                    
	bool                                               bMonsterIdleIndexDelegateBound;                            
	unsigned char                                      UnknownData03[0x7];                                        
	class AGenericMonsterBase*                         CachedOwnerMonster;                                        
	bool                                               bMonsterHurtingDelegateBound;                              
	unsigned char                                      UnknownData04[0x7];                                        
	class UStateReflectComp*                           CachedStateReflectComp;                                    
	TArray<struct FGameplayTag>                        PendingMontageTags;                                        
	bool                                               bAnimAssetsLoadedDelegateBound;                            
	unsigned char                                      UnknownData05[0xF];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericMonsterAnimInstance");
		return pStaticClass;
	}


	float PlayMontageWithAnimEventByName(const struct FName& InTag);
	float PlayMontageWithAnimEvent(const struct FGameplayTag& EventTag);
	void OnMonsterRandomIdleIndexSet(int NewIndex);
	void OnMonsterHurting(class AGenericMonsterBase* Monster, const struct FVector& HurtDir);
	void HandleStateEntered(const struct FGameplayTag& State);
	class UGenericMonsterAnimShareParamsComp* GetMonsterShareParams();
};


 
 
class UGenericMonsterAnimShareParamsComp : public UDataDriverAnimShareParamsComp
{
public:
	struct FSoftObjectPath                             AnimDataAsset;                                             
	int64_t                                            AnimAssetContextKey;                                       
	TMap<struct FGameplayTag, struct FGameplayTag>     StateToAnimParamMap;                                       
	unsigned char                                      UnknownData00[0x18];                                       
	class UStateReflectComp*                           CachedStateRef;                                            
	struct FName                                       AnimSourceKey;                                             
	bool                                               bAnimAssetsLoaded;                                         
	unsigned char                                      UnknownData01[0x7];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericMonsterAnimShareParamsComp");
		return pStaticClass;
	}


	bool IsAnimAssetsLoaded();
	void HandleStateLeft(const struct FGameplayTag& State);
	void HandleStateEntered(const struct FGameplayTag& State);
	class UAnimationAsset* GetLoadedAnimAsset(const struct FGameplayTag& Tag);
};


 
 
class AGenericMonsterEditor : public AGenericMonster
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericMonsterEditor");
		return pStaticClass;
	}

};


 
 
class AGenericNPC : public AGenericMonsterBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericNPC");
		return pStaticClass;
	}

};


 
 
class UGenericPartHitComponent : public UPartHitComponentBase
{
public:
	class ACharacter*                                  OwnerCharacter;                                            
	float                                              UpdateHitBoxDeltaTime;                                     
	bool                                               bActivePartHit;                                            
	unsigned char                                      UnknownData00[0x3];                                        
	uint64_t                                           LastPartHitRefreshBoxCollisionFrameNum;                    
	TMap<struct FGameplayTag, TEnumAsByte<ESTEPoseState>> TagToPoseMap;                                              
	TMap<TEnumAsByte<ESTEPoseState>, struct FHitBoxTagInfo> HitBoxTagMapData;                                          
	struct FHitBoxTagInfo                              UselessHitBoxData;                                         
	TArray<class UPrimitiveComponent*>                 HitBoxList;                                                
	unsigned char                                      UnknownData01[0x20];                                       
	TMap<struct FString, EAvatarDamagePosition>        NewHitBodyPosMap;                                          
	float                                              PawnCollisionCountdown;                                    
	bool                                               bIsRefreshPawnCollision;                                   
	unsigned char                                      UnknownData02[0x3];                                        
	float                                              BoxCollisionCountdown;                                     
	bool                                               bIsRefreshBoxCollision;                                    
	TEnumAsByte<EHitPartJugementType>                  ClientHitPartJudgment;                                     
	unsigned char                                      UnknownData03[0x1];                                        
	bool                                               bDebugDrawHitPos;                                          
	bool                                               bCloseCharacterMeshCollision;                              
	unsigned char                                      UnknownData04[0x7];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.GenericPartHitComponent");
		return pStaticClass;
	}


	void UpdatePoseCollisionShapes(TEnumAsByte<ESTEPoseState> PoseState);
	void UpdateAllInstanceBodyTransform(int Type);
	void RefreshWorldBoxCollision(float countdown);
	void RefreshByStateChange(const struct FGameplayTag& State);
	void InitBodyHitBox();
	class UPrimitiveComponent* GetHitBoxByState(TEnumAsByte<ESTEPoseState> InPoseState);
	EAvatarDamagePosition GetHitBodyTypeByHitPos(const struct FVector& InHitPos);
	EAvatarDamagePosition GetHitBodyTypeByBoneName(const struct FString& InBoneName);
	EAvatarDamagePosition GetHitBodyType(const struct FVector& InHitPos, const struct FVector& InImpactVec, const struct FString& InBoneName);
	TEnumAsByte<EHitPartJugementType> GetCurHitPartJudgementType();
	void CloseBodyBulletCollision();
	EAvatarDamagePosition CalcHitBodyType(const struct FVector& InHitPos, const struct FVector& InProjvec, const struct FVector& InCenterPos, const struct FBodyTypeDef& InBodyDef);
};


 
 
class UStateReflectComp : public UActorComponent
{
public:
	class UStateRelationDataAsset*                     RelationData;                                              
	struct FScriptMulticastDelegate                    OnStateEntered;                                            
	struct FScriptMulticastDelegate                    OnStateLeft;                                               
	struct FGameplayTagContainer                       CurrentStates;                                             

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.StateReflectComp");
		return pStaticClass;
	}


	void OnRep_CurrentStates(const struct FGameplayTagContainer& OldStates);
	void LeaveState(const struct FGameplayTag& State);
	bool HasState(const struct FGameplayTag& State, bool bExact);
	struct FGameplayTagContainer GetCurrentStates();
	bool EnterState(const struct FGameplayTag& State);
	bool CanEnterState(const struct FGameplayTag& State);
};


 
 
class UStateRelationDataAsset : public UDataAsset
{
public:
	TArray<struct FStateRelationEntry>                 Entries;                                                   
	unsigned char                                      UnknownData00[0x50];                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericFeatures.StateRelationDataAsset");
		return pStaticClass;
	}

};


}

