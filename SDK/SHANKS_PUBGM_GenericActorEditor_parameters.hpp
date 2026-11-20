// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UActorEditorAnimInstanceBase_ClearAnimReferences_Params
{
};

 
struct UActorEditorCharacterMovementComponent_OnRep_CharacterMovementSyncData_Params
{
};

 
struct UActorEditorComponentBlueprintLibrary_UnregisterComponent_Params
{
	class UActorComponent*                             InComponent;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_SetWidgetOpacityFromTexture_Params
{
	class UWidgetComponent*                            InComp;                                                    
	float                                              Opacity;                                                   
};

 
struct UActorEditorComponentBlueprintLibrary_SetWidgetDrawAtDesiredSize_Params
{
	class UWidgetComponent*                            InComp;                                                    
	bool                                               bDrawAtDesiredSize;                                        
};

 
struct UActorEditorComponentBlueprintLibrary_SetParticleSystemAutoDestroy_Params
{
	class UParticleSystemComponent*                    InComp;                                                    
	bool                                               bAutoDestroy;                                              
};

 
struct UActorEditorComponentBlueprintLibrary_SetMobility_Params
{
	class USceneComponent*                             InSceneComp;                                               
	TEnumAsByte<EComponentMobility>                    NewMobility;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_SetComponentAutoActivate_Params
{
	class UActorComponent*                             InComponent;                                               
	bool                                               bAutoActivate;                                             
};

 
struct UActorEditorComponentBlueprintLibrary_SetActorRootComponent_Params
{
	class AActor*                                      InActor;                                                   
	class USceneComponent*                             NewRootComponent;                                          
	bool                                               ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_ReregisterComponent_Params
{
	class UActorComponent*                             InComponent;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_RegisterComponent_Params
{
	class UActorComponent*                             InComponent;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_IsSimulatingPhysics_Params
{
	class UPrimitiveComponent*                         InComp;                                                    
	bool                                               ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_IsComponentRegistered_Params
{
	class UActorComponent*                             InComponent;                                               
	bool                                               ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_GetParticleSystemAutoDestroy_Params
{
	class UParticleSystemComponent*                    InComp;                                                    
	bool                                               ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_GetFloatParameter_Params
{
	class UParticleSystemComponent*                    InComp;                                                    
	struct FName                                       InName;                                                    
	float                                              ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_GetComponentBounds_Params
{
	class USceneComponent*                             InSceneComp;                                               
	struct FVector                                     Origin;                                                    
	struct FVector                                     BoxExtent;                                                 
	float                                              SphereRadius;                                              
};

 
struct UActorEditorComponentBlueprintLibrary_GetCollisionTraceFlag_Params
{
	class UPrimitiveComponent*                         InComp;                                                    
	TEnumAsByte<ECollisionTraceFlag>                   ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_GetBoneTransform_Params
{
	class USkinnedMeshComponent*                       InComp;                                                    
	int                                                BoneIdx;                                                   
	struct FTransform                                  LocalToWorld;                                              
	struct FTransform                                  ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_GetBoneLocation_Params
{
	class USkinnedMeshComponent*                       InComp;                                                    
	struct FName                                       BoneName;                                                  
	TEnumAsByte<EBoneSpaces>                           Space;                                                     
	struct FVector                                     ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_GetActorRootComponent_Params
{
	class AActor*                                      InActor;                                                   
	class USceneComponent*                             ReturnValue;                                               
};

 
struct UActorEditorComponentBlueprintLibrary_ChangeRootComponent_Params
{
	class AActor*                                      InActor;                                                   
	class USceneComponent*                             NewRootComponent;                                          
	bool                                               ReturnValue;                                               
};

 
struct UActorEditorDisableTransformReplicationInterface_SetDisableTransformReplication_Params
{
	bool                                               bInDisable;                                                
};

 
struct UActorEditorParticleSystemComponent_GetEmitterInstanceNum_Params
{
	int                                                ReturnValue;                                               
};

 
struct UActorEditorSkeletalMeshComponent_SetSkeletalModelPreset_Params
{
	struct FString                                     ModePresetIDStr;                                           
};

 
struct UActorEditorSkeletalMeshComponent_PlaySkeletalAnimationPreset_Params
{
	struct FString                                     AnimationPresetIDStr;                                      
};

 
struct UActorEditorStaticMeshComponent_SetStaticMeshPath_Params
{
	struct FString                                     InMeshPath;                                                
	bool                                               ReturnValue;                                               
};

 
struct UActorEditorStaticMeshComponent_OnRep_StaticMeshPath_Params
{
	struct FString                                     OldPath;                                                   
};

}

