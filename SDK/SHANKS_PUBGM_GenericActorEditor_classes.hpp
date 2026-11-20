// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UActorEditorActorComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x58];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorActorComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorAnimInstanceBase : public UAnimInstance
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorAnimInstanceBase");
		return pStaticClass;
	}


	void ClearAnimReferences();
};


 
 
class UActorEditorBoxComponent : public UBoxComponent
{
public:
	unsigned char                                      UnknownData00[0x68];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               
	unsigned char                                      UnknownData01[0x8];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorBoxComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorCameraComponent : public UCameraComponent
{
public:
	unsigned char                                      UnknownData00[0x60];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorCameraComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorCapsuleComponent : public UCapsuleComponent
{
public:
	unsigned char                                      UnknownData00[0x60];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorCapsuleComponent");
		return pStaticClass;
	}

};


 
 
class AActorEditorCharacter : public ALuaCharacter
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorCharacter");
		return pStaticClass;
	}

};


 
 
class UActorEditorCharacterMovementComponent : public UCharacterMovementComponent
{
public:
	unsigned char                                      UnknownData00[0x50];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FActorEditorCharacterMovementSyncData       CharacterMovementSyncData;                                 
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorCharacterMovementComponent");
		return pStaticClass;
	}


	void OnRep_CharacterMovementSyncData();
};


 
 
class UActorEditorComponentBlueprintLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorComponentBlueprintLibrary");
		return pStaticClass;
	}


	static void UnregisterComponent(class UActorComponent* InComponent);
	static void SetWidgetOpacityFromTexture(class UWidgetComponent* InComp, float Opacity);
	static void SetWidgetDrawAtDesiredSize(class UWidgetComponent* InComp, bool bDrawAtDesiredSize);
	static void SetParticleSystemAutoDestroy(class UParticleSystemComponent* InComp, bool bAutoDestroy);
	static void SetMobility(class USceneComponent* InSceneComp, TEnumAsByte<EComponentMobility> NewMobility);
	static void SetComponentAutoActivate(class UActorComponent* InComponent, bool bAutoActivate);
	static bool SetActorRootComponent(class AActor* InActor, class USceneComponent* NewRootComponent);
	static void ReregisterComponent(class UActorComponent* InComponent);
	static void RegisterComponent(class UActorComponent* InComponent);
	static bool IsSimulatingPhysics(class UPrimitiveComponent* InComp);
	static bool IsComponentRegistered(class UActorComponent* InComponent);
	static bool GetParticleSystemAutoDestroy(class UParticleSystemComponent* InComp);
	static float GetFloatParameter(class UParticleSystemComponent* InComp, const struct FName& InName);
	static void GetComponentBounds(class USceneComponent* InSceneComp, struct FVector* Origin, struct FVector* BoxExtent, float* SphereRadius);
	static TEnumAsByte<ECollisionTraceFlag> GetCollisionTraceFlag(class UPrimitiveComponent* InComp);
	static struct FTransform GetBoneTransform(class USkinnedMeshComponent* InComp, int BoneIdx, const struct FTransform& LocalToWorld);
	static struct FVector GetBoneLocation(class USkinnedMeshComponent* InComp, const struct FName& BoneName, TEnumAsByte<EBoneSpaces> Space);
	static class USceneComponent* GetActorRootComponent(class AActor* InActor);
	static bool ChangeRootComponent(class AActor* InActor, class USceneComponent* NewRootComponent);
};


 
 
class AActorEditorDecoratorActor : public ADecoratorActor
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorDecoratorActor");
		return pStaticClass;
	}

};


 
 
class UActorEditorDisableTransformReplicationInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorDisableTransformReplicationInterface");
		return pStaticClass;
	}


	void SetDisableTransformReplication(bool bInDisable);
};


 
 
class UActorEditorMovementComponent : public UMovementComponent
{
public:
	unsigned char                                      UnknownData00[0x58];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorMovementComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorParticleSystemComponent : public UParticleSystemComponent
{
public:
	unsigned char                                      UnknownData00[0x68];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               
	unsigned char                                      UnknownData01[0x8];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorParticleSystemComponent");
		return pStaticClass;
	}


	int GetEmitterInstanceNum();
};


 
 
class AActorEditorPawn : public ALuaPawn
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorPawn");
		return pStaticClass;
	}

};


 
 
class UActorEditorSceneComponent : public USceneComponent
{
public:
	unsigned char                                      UnknownData00[0x58];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               
	unsigned char                                      UnknownData01[0x8];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorSceneComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorSkeletalMeshComponent : public USkeletalMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x60];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorSkeletalMeshComponent");
		return pStaticClass;
	}


	void SetSkeletalModelPreset(const struct FString& ModePresetIDStr);
	void PlaySkeletalAnimationPreset(const struct FString& AnimationPresetIDStr);
};


 
 
class UActorEditorSphereComponent : public USphereComponent
{
public:
	unsigned char                                      UnknownData00[0x60];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorSphereComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorSplineComponent : public USplineComponent
{
public:
	unsigned char                                      UnknownData00[0x68];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               
	unsigned char                                      UnknownData01[0x8];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorSplineComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorSpringArmComponent : public USpringArmComponent
{
public:
	unsigned char                                      UnknownData00[0x60];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorSpringArmComponent");
		return pStaticClass;
	}

};


 
 
class UActorEditorStaticMeshComponent : public UStaticMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x60];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	struct FString                                     LuaFilePath;                                               
	struct FString                                     StaticMeshPath;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorStaticMeshComponent");
		return pStaticClass;
	}


	bool SetStaticMeshPath(const struct FString& InMeshPath);
	void OnRep_StaticMeshPath(const struct FString& OldPath);
};


 
 
class UActorEditorWidgetComponent : public UWidgetComponent
{
public:
	unsigned char                                      UnknownData00[0x68];                                       
	struct FLuaNetSerialization                        LuaNetSerialization;                                       
	bool                                               bFaceCamera;                                               
	unsigned char                                      UnknownData01[0x7];                                        
	struct FString                                     LuaFilePath;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GenericActorEditor.ActorEditorWidgetComponent");
		return pStaticClass;
	}

};


}

