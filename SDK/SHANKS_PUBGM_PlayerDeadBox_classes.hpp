// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class APlayerDeadBox_C : public APlayerTombBox
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UInteractiveComponent_C*                     InteractiveComponent;                                      
	class UBoxComponent*                               Box;                                                       
	class UParticleSystemComponent*                    TeammateParticleSystem;                                    
	class UParticleSystemComponent*                    DeadParticleSystem;                                        
	class USkeletalMeshComponent*                      SkeletalMesh;                                              
	class UDeadBoxAvatarComponent_BP_C*                DeadBoxAvatarComponent_BP;                                 
	class UAkComponent*                                AkComponent;                                               
	class USTScreenAppearanceComponent*                STScreenAppearance;                                        
	class UStaticMeshComponent*                        SM_plane_01;                                               
	class USplineComponent*                            Spline;                                                    
	class UCameraComponent*                            Camera;                                                    
	class UStaticMeshComponent*                        Survive_FMC_Chest1;                                        
	float                                              PitchTimeline_NewTrack_2_968FF7FD4B819605A16739A661556F94; 
	TEnumAsByte<ETimelineDirection>                    PitchTimeline__Direction_968FF7FD4B819605A16739A661556F94; 
	unsigned char                                      UnknownData00[0x3];                                        
	class UTimelineComponent*                          PitchTimeline;                                             
	float                                              MatParamTimeline_NewTrack_1_BC760681429EE06B831346878CD5F7A7; 
	TEnumAsByte<ETimelineDirection>                    MatParamTimeline__Direction_BC760681429EE06B831346878CD5F7A7; 
	unsigned char                                      UnknownData01[0x3];                                        
	class UTimelineComponent*                          MatParamTimeline;                                          
	float                                              CameraMove_NewTrack_0_D08AF709411B99835C3653A068B1A989;    
	TEnumAsByte<ETimelineDirection>                    CameraMove__Direction_D08AF709411B99835C3653A068B1A989;    
	unsigned char                                      UnknownData02[0x3];                                        
	class UTimelineComponent*                          CameraMove;                                                
	class UMaterialInstanceDynamic*                    DynamicMat;                                                
	bool                                               bIsPlayingAudio;                                           
	bool                                               bHasOpenAnim;                                              
	unsigned char                                      UnknownData03[0x6];                                        
	class UStaticMesh*                                 DefaultMesh;                                               
	struct FVector                                     CarryBoxScale;                                             
	struct FVector                                     DefaultBoxScale;                                           

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PlayerDeadBox.PlayerDeadBox_C");
		return pStaticClass;
	}


	void WarmodeEnterSpectating();
	void LuaCheckCanPlayAudio(bool* bCanPlayAudio);
	struct FVector GetGroundLocation();
	void UserConstructionScript();
	void CameraMove__FinishedFunc();
	void CameraMove__UpdateFunc();
	void MatParamTimeline__FinishedFunc();
	void MatParamTimeline__UpdateFunc();
	void PitchTimeline__FinishedFunc();
	void PitchTimeline__UpdateFunc();
	void ShowShine();
	void ShowNormal();
	void ReceiveBeginPlay();
	void SwitchToDeadTombBox();
	void HideDeadTombApparence();
	void OnRep_AvatarId();
	void OnAvatarLoadedDone();
	void ResetToDefaultMesh();
	void ExecuteUbergraph_PlayerDeadBox(int EntryPoint);
};


}

