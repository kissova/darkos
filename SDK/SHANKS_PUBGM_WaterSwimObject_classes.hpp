// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class AWaterSwimObject_C : public AWaterSwimActor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UGameEventListener*                          GameEventListener;                                         
	class UParticleSystemComponent*                    P_Water_down_01;                                           
	class UAkComponent*                                Ak;                                                        
	class UPostProcessComponent*                       PostProcess;                                               
	class UBoxComponent*                               PostSceneBox;                                              
	class UStaticMeshComponent*                        watermesh;                                                 
	class USceneComponent*                             DefaultSceneRoot;                                          
	float                                              Gamma;                                                     
	unsigned char                                      UnknownData00[0xC];                                        
	struct FPostProcessSettings                        NewVar_1;                                                  
	TArray<class ASTExtraBaseCharacter*>               playerList;                                                
	TEnumAsByte<ESTEPoseState>                         NewVar_2;                                                  
	unsigned char                                      UnknownData01[0x3];                                        
	float                                              FogDensity;                                                
	class AExponentialHeightFog*                       HeightFog;                                                 
	class UMaterialInstanceDynamic*                    NoHDRWater;                                                
	class UMaterialInstanceDynamic*                    HDROcean;                                                  
	class UMaterialInstanceDynamic*                    HDRSwamp;                                                  
	class UMaterialInterface*                          HDROceanMaterial;                                          
	class UMaterialInterface*                          SUPHDROceanMaterial;                                       
	class UMaterialInterface*                          HDRSwampMaterial;                                          
	class UMaterialInterface*                          SUPHDRSwampMaterial;                                       
	class UMaterialInterface*                          NoHDRWaterMaterial;                                        
	int                                                CurrentMaterialIndex;                                      
	unsigned char                                      UnknownData02[0x4];                                        
	TArray<class UMaterialInterface*>                  MaterialList;                                              
	bool                                               IsSetSwamp;                                                
	unsigned char                                      UnknownData03[0x7];                                        
	unsigned char                                      UnknownData04[0x50];                                       
	class UMaterialInterface*                          WaterMaterial_SUP_HDR;                                     
	class UMaterialInterface*                          WaterMaterial_HDR;                                         
	class UMaterialInterface*                          WaterMaterial_Normal;                                      
	bool                                               IsIphoneNewWater;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass WaterSwimObject.WaterSwimObject_C");
		return pStaticClass;
	}


	void SetWaterMaterialByGamePawnEvent(TEnumAsByte<EGamePawnEvent> Event);
	void SetWaterMaterial(int NewParam);
	void RefreshWaterMaterial();
	void DoTrySetWaterMaterial(int NewParam);
	void TrySetWaterMaterial(int NewParam);
	void IsSupportIndex(int NewParam, bool* NewParam1);
	void IsNewIphone(bool* IsNewIphone);
	void SetWateMaterial(bool bHDR);
	void HideUnderWaterEffect(class UStaticMeshComponent* WaterPlane, class UExponentialHeightFogComponent* CamFog);
	void ShowUnderWaterEffect(class UStaticMeshComponent* WaterPlane, class UExponentialHeightFogComponent* CamFog);
	bool IsCapsult(class UObject* PlayerPawn, class UActorComponent* comp);
	void UserConstructionScript();
	void BndEvt__PostSceneBox_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void BndEvt__PostSceneBox_K2Node_ComponentBoundEvent_0_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex);
	void ReceiveBeginPlay();
	void CustomEvent_2(int UserQualitySettingLevel);
	void ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason);
	void CustomEvent_3(bool UserMsaaSetting);
	void CustomEvent_4(bool bOpenWaterReflection);
	void ExecuteUbergraph_WaterSwimObject(int EntryPoint);
};


}

