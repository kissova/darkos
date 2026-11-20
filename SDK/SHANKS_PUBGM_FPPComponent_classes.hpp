// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UFPPComponent_C : public UBaseFPPComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class ABP_PlayerPawn_C*                            PawnBP;                                                    
	float                                              DeltaTime;                                                 
	unsigned char                                      UnknownData00[0x4];                                        
	class USkeletalMeshComponent*                      NewVar_1;                                                  
	class UStaticMesh*                                 SightLens;                                                 
	TArray<class UMaterialInstance*>                   ScopeMaterialOverride;                                     
	TArray<int>                                        Scope4XType1;                                              
	TArray<int>                                        Scope4XType2;                                              
	TMap<struct FString, struct FLinearColor>          ScopeColorMap;                                             
	TMap<struct FString, class UMaterialInterface*>    MaterialCahceMap;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass FPPComponent.FPPComponent_C");
		return pStaticClass;
	}


	void IsNeedChangeTexOpacity(bool* bNeedChange);
	void GetMateriaByString(const struct FString& Name, class UMaterialInterface** Material);
	void ScopingAttachToHead();
	void ScopingAttachToGun();
	class UMaterialInstance* GetScopeMaterialOverride(class ASTExtraShootWeapon** Weapon);
	void ResetScreenPercentage();
	void DownScreenPercentage();
	void ChangeScopeTPPGlassMat(class UMeshComponent* ScopeMeshComp, int ScopeID);
	void GetScopeMatTableKey(class ASTExtraPlayerController* PlayerController, class ASTExtraShootWeapon* Weapon, EWeaponAttachmentSocketType ScopeType, struct FString* Key);
	void IsScopeSpecialMatExist(class ASTExtraWeapon* Weapon, EWeaponAttachmentSocketType ScopeType, bool* exist, int* MatTableKey);
	float SwitchAngledSightConfigMaterial(bool* forceSwitch);
	float ShowAngledSightTPPMaterial(bool* forceADSState);
	float SwitchSightConfigMaterial();
	float ShowReflectorSightTPPMaterial(bool* forceADSState);
	float GetScopeFov(class ASTExtraWeapon** Weapon, bool* bIsAngled);
	void SetTagCullingBP(bool IsUse);
	void requestResourceGuarantee(int InOrOut, TEnumAsByte<ELoadMode> loadMode, TEnumAsByte<EApplyStatus> applyStatus);
	void ReceiveTick(float* DeltaSeconds);
	void ReloadEvent();
	void SetTagCulling(bool* IsUse);
	void PlayScopeInTimeline();
	void ScopeInEnd();
	void ScopeOutEnd();
	void StopScopeIn();
	void AttachToSight();
	void AttachTo(class USceneComponent* NewParam);
	void Detach(class USceneComponent* NewParam);
	void AutoReloadEvent(class ASTExtraShootWeapon* ShootWeapon);
	void AttachToSightKeepTransform();
	void ExecuteUbergraph_FPPComponent(int EntryPoint);
};


}

