// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBehaviorControlComponent_UnPossessed_Params
{
};

 
struct UBehaviorControlComponent_StopBehaviorTree_Params
{
};

 
struct UBehaviorControlComponent_StopBehavior_Params
{
	struct FString                                     Reason;                                                    
};

 
struct UBehaviorControlComponent_RunBehaviorTreeByIndex_Params
{
	int                                                PathIndex;                                                 
	bool                                               ReturnValue;                                               
};

 
struct UBehaviorControlComponent_ResumeBehavior_Params
{
	struct FString                                     Reason;                                                    
};

 
struct UBehaviorControlComponent_RestartBehavior_Params
{
};

 
struct UBehaviorControlComponent_PossessedBy_Params
{
	class AController*                                 NewController;                                             
};

 
struct UBehaviorControlComponent_PauseBehavior_Params
{
	struct FString                                     Reason;                                                    
};

 
struct UBehaviorControlComponent_OnPlayerActiveRegionsChanged_Params
{
	bool                                               bEnter;                                                    
};

 
struct AGenericCharacter_OnStateLeft_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct AGenericCharacter_OnStateEntered_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct AGenericCharacter_OnRep_PlayerKey_Params
{
};

 
struct AGenericCharacter_IsInObjectPool_Params
{
	bool                                               ReturnValue;                                               
};

 
struct AGenericCharacter_IsAlive_Params
{
	bool                                               ReturnValue;                                               
};

 
struct AGenericCharacter_HandleStateLeft_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct AGenericCharacter_HandleStateEntered_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct AGenericCharacter_GetStateReflectComp_Params
{
	class UStateReflectComp*                           ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_SelectFromCandidates_Params
{
	TArray<class ACharacter*>                          Filtered;                                                  
	EGenericSearchEnemyRule                            Rule;                                                      
	class ACharacter*                                  ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_IsValidEnemy_Params
{
	class ACharacter*                                  Target;                                                    
	bool                                               bOutIsNearDeath;                                           
	bool                                               bUseMonsterFilter;                                         
	bool                                               ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_IsTargetAlive_Params
{
	class ACharacter*                                  Target;                                                    
	bool                                               ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_IsEnemyByActor_Params
{
	class ACharacter*                                  InTarget;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_GetTargetHealth_Params
{
	class ACharacter*                                  Target;                                                    
	float                                              ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_GetSensingConfig_Params
{
	struct FGenericMonsterSensingConfig                ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_GetOwnerMonster_Params
{
	class AGenericMonsterBase*                         ReturnValue;                                               
};

 
struct UGenericChooseEnemyComponent_CollectPlayerCandidates_Params
{
	TArray<class ACharacter*>                          OutPlayers;                                                
};

 
struct UGenericChooseEnemyComponent_CollectMonsterCandidates_Params
{
	TArray<class ACharacter*>                          OutMonsters;                                               
};

 
struct AGenericMonsterBase_SetTeamID_Params
{
	int                                                NewTeamId;                                                 
};

 
struct AGenericMonsterBase_SetSpeedScale_Params
{
	float                                              NewSpeedScale;                                             
};

 
struct AGenericMonsterBase_SetMonsterIdleIndex_Params
{
	int                                                NewIndex;                                                  
};

 
struct AGenericMonsterBase_SetCharacterName_Params
{
	struct FString                                     NewCharacterName;                                          
};

 
struct AGenericMonsterBase_SetCampID_Params
{
	int                                                NewCampID;                                                 
};

 
struct AGenericMonsterBase_SelectEnemyByLua_Params
{
	TArray<class ACharacter*>                          Candidates;                                                
	class ACharacter*                                  ReturnValue;                                               
};

 
struct AGenericMonsterBase_ReviseSenseDistanceByActor_Params
{
	float                                              InDistance;                                                
	class AActor*                                      InTarget;                                                  
	float                                              ReturnValue;                                               
};

 
struct AGenericMonsterBase_ReceivedPlayerActiveRegionsChanged_Params
{
	bool                                               bEnter;                                                    
};

 
struct AGenericMonsterBase_OnSmoothComponentSnapshotPreReplicate_Params
{
};

 
struct AGenericMonsterBase_OnRep_MonsterIdleIndex_Params
{
};

 
struct AGenericMonsterBase_OnRep_CampID_Params
{
};

 
struct AGenericMonsterBase_LeaveLaunchAirRiseUp_Params
{
};

 
struct AGenericMonsterBase_LeaveLaunchAirGround_Params
{
};

 
struct AGenericMonsterBase_LaunchCharacterWithParam_Params
{
	struct FVector                                     LaunchVelocity;                                            
	bool                                               bChangeState;                                              
};

 
struct AGenericMonsterBase_IsValidEnemyTarget_Params
{
	class AActor*                                      InTarget;                                                  
	bool                                               ReturnValue;                                               
};

 
struct AGenericMonsterBase_IsEnemyByActor_Params
{
	class ACharacter*                                  InTarget;                                                  
	bool                                               ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetTeamId_Params
{
	int                                                ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetSpeedScale_Params
{
	float                                              ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetSensingConfig_Params
{
	struct FGenericMonsterSensingConfig                ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetMonsterIdleIndex_Params
{
	int                                                ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetCurrentSpeed_Params
{
	float                                              ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetChooseEnemyComponent_Params
{
	class UGenericChooseEnemyComponent*                ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetCharacterName_Params
{
	struct FString                                     ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetCampId_Params
{
	int                                                ReturnValue;                                               
};

 
struct AGenericMonsterBase_GetBuffComponent_Params
{
	class USTBuffSystemComponent*                      ReturnValue;                                               
};

 
struct AGenericMonsterBase_FinishStunRecovery_Params
{
};

 
struct AGenericMonsterBase_ExitSpawnState_Params
{
};

 
struct AGenericMonsterBase_EnterStunRecovery_Params
{
};

 
struct AGenericMonsterBase_EnterStun_Params
{
};

 
struct AGenericMonsterBase_DoHurting_Params
{
	struct FVector                                     HurtDir;                                                   
};

 
struct AGenericMonsterBase_ClearStunState_Params
{
};

 
struct AGenericMonsterBase_ClearLaunchAirState_Params
{
};

 
struct AGenericMonsterBase_CheckLaunchAirState_Params
{
};

 
struct AGenericMonsterBase_ChangeWalkSpeed_Params
{
	EMobWalkType                                       InWalkType;                                                
};

 
struct AGenericMonster_SetTakeDamageScale_Params
{
	float                                              NewTakeDamageScale;                                        
};

 
struct AGenericMonster_SetIsInvincible_Params
{
	bool                                               bInvincible;                                               
	unsigned char                                      InMaskBit;                                                 
};

 
struct AGenericMonster_SetHealthMax_Params
{
	float                                              NewHealthMax;                                              
};

 
struct AGenericMonster_SetHealth_Params
{
	float                                              NewHealth;                                                 
};

 
struct AGenericMonster_SetDamageScale_Params
{
	float                                              NewDamageScale;                                            
};

 
struct AGenericMonster_OnTargetTakeDamage_Params
{
	class AActor*                                      DamageTarget;                                              
	float                                              Damage;                                                    
	class AController*                                 EventInstigator;                                           
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_OnDie_Params
{
	class APawn*                                       Causer;                                                    
};

 
struct AGenericMonster_HandleTargetTakeDamage_Params
{
	class AActor*                                      DamageTarget;                                              
	float                                              Damage;                                                    
	class AController*                                 EventInstigator;                                           
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_GetTakeDamageScale_Params
{
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_GetPartHitComponentBase_Params
{
	class UPartHitComponentBase*                       ReturnValue;                                               
};

 
struct AGenericMonster_GetIsInvincible_Params
{
	bool                                               ReturnValue;                                               
};

 
struct AGenericMonster_GetHealthMax_Params
{
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_GetHealth_Params
{
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_GetDamageScale_Params
{
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_CalcVehicleHitDamage_Params
{
	class ASTExtraVehicleBase*                         OtherVehicle;                                              
	struct FVector                                     HitImpulseDirection;                                       
	float                                              HitSpeed;                                                  
	float                                              ReturnValue;                                               
};

 
struct AGenericMonster_BPReceiveDamage_Params
{
	float                                              Damage;                                                    
	class UDamageType*                                 DamageType;                                                
	class AController*                                 InstigatedBy;                                              
	class AActor*                                      DamageCauser;                                              
	TEnumAsByte<EDamageType>                           DamageEventType;                                           
};

 
struct AGenericMonster_BPPreTakeDamage_Params
{
	float                                              DamageAmount;                                              
	struct FDamageEvent                                DamageEvent;                                               
	class AController*                                 EventInstigator;                                           
	class AActor*                                      DamageCauser;                                              
	float                                              ReturnValue;                                               
};

 
struct UGenericMonsterAnimInstance_PlayMontageWithAnimEventByName_Params
{
	struct FName                                       InTag;                                                     
	float                                              ReturnValue;                                               
};

 
struct UGenericMonsterAnimInstance_PlayMontageWithAnimEvent_Params
{
	struct FGameplayTag                                EventTag;                                                  
	float                                              ReturnValue;                                               
};

 
struct UGenericMonsterAnimInstance_OnMonsterRandomIdleIndexSet_Params
{
	int                                                NewIndex;                                                  
};

 
struct UGenericMonsterAnimInstance_OnMonsterHurting_Params
{
	class AGenericMonsterBase*                         Monster;                                                   
	struct FVector                                     HurtDir;                                                   
};

 
struct UGenericMonsterAnimInstance_HandleStateEntered_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct UGenericMonsterAnimInstance_GetMonsterShareParams_Params
{
	class UGenericMonsterAnimShareParamsComp*          ReturnValue;                                               
};

 
struct UGenericMonsterAnimShareParamsComp_IsAnimAssetsLoaded_Params
{
	bool                                               ReturnValue;                                               
};

 
struct UGenericMonsterAnimShareParamsComp_HandleStateLeft_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct UGenericMonsterAnimShareParamsComp_HandleStateEntered_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct UGenericMonsterAnimShareParamsComp_GetLoadedAnimAsset_Params
{
	struct FGameplayTag                                Tag;                                                       
	class UAnimationAsset*                             ReturnValue;                                               
};

 
struct UGenericPartHitComponent_UpdatePoseCollisionShapes_Params
{
	TEnumAsByte<ESTEPoseState>                         PoseState;                                                 
};

 
struct UGenericPartHitComponent_UpdateAllInstanceBodyTransform_Params
{
	int                                                Type;                                                      
};

 
struct UGenericPartHitComponent_RefreshWorldBoxCollision_Params
{
	float                                              countdown;                                                 
};

 
struct UGenericPartHitComponent_RefreshByStateChange_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct UGenericPartHitComponent_InitBodyHitBox_Params
{
};

 
struct UGenericPartHitComponent_GetHitBoxByState_Params
{
	TEnumAsByte<ESTEPoseState>                         InPoseState;                                               
	class UPrimitiveComponent*                         ReturnValue;                                               
};

 
struct UGenericPartHitComponent_GetHitBodyTypeByHitPos_Params
{
	struct FVector                                     InHitPos;                                                  
	EAvatarDamagePosition                              ReturnValue;                                               
};

 
struct UGenericPartHitComponent_GetHitBodyTypeByBoneName_Params
{
	struct FString                                     InBoneName;                                                
	EAvatarDamagePosition                              ReturnValue;                                               
};

 
struct UGenericPartHitComponent_GetHitBodyType_Params
{
	struct FVector                                     InHitPos;                                                  
	struct FVector                                     InImpactVec;                                               
	struct FString                                     InBoneName;                                                
	EAvatarDamagePosition                              ReturnValue;                                               
};

 
struct UGenericPartHitComponent_GetCurHitPartJudgementType_Params
{
	TEnumAsByte<EHitPartJugementType>                  ReturnValue;                                               
};

 
struct UGenericPartHitComponent_CloseBodyBulletCollision_Params
{
};

 
struct UGenericPartHitComponent_CalcHitBodyType_Params
{
	struct FVector                                     InHitPos;                                                  
	struct FVector                                     InProjvec;                                                 
	struct FVector                                     InCenterPos;                                               
	struct FBodyTypeDef                                InBodyDef;                                                 
	EAvatarDamagePosition                              ReturnValue;                                               
};

 
struct UStateReflectComp_OnRep_CurrentStates_Params
{
	struct FGameplayTagContainer                       OldStates;                                                 
};

 
struct UStateReflectComp_LeaveState_Params
{
	struct FGameplayTag                                State;                                                     
};

 
struct UStateReflectComp_HasState_Params
{
	struct FGameplayTag                                State;                                                     
	bool                                               bExact;                                                    
	bool                                               ReturnValue;                                               
};

 
struct UStateReflectComp_GetCurrentStates_Params
{
	struct FGameplayTagContainer                       ReturnValue;                                               
};

 
struct UStateReflectComp_EnterState_Params
{
	struct FGameplayTag                                State;                                                     
	bool                                               ReturnValue;                                               
};

 
struct UStateReflectComp_CanEnterState_Params
{
	struct FGameplayTag                                State;                                                     
	bool                                               ReturnValue;                                               
};

}

