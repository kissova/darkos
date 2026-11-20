// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class APlayerDeadInventoryBox_C : public APlayerTombBox
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UAkComponent*                                AkComponent;                                               
	class USTScreenAppearanceComponent*                STScreenAppearance;                                        
	class UStaticMeshComponent*                        SM_plane_01;                                               
	class USplineComponent*                            Spline;                                                    
	class UCameraComponent*                            Camera;                                                    
	class UStaticMeshComponent*                        Survive_FMC_Chest1;                                        
	class UMaterialInstanceDynamic*                    DynamicMat;                                                
	struct FVector                                     TeammateParticleLoc;                                       
	unsigned char                                      UnknownData00[0x4];                                        
	class UParticleSystem*                             TeammateParticle;                                          
	class UParticleSystem*                             DeadParticle;                                              
	struct FVector                                     DeadParticleLoc;                                           
	bool                                               bIsPlayingAudio;                                           
	bool                                               bHasOpenAnim;                                              

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PlayerDeadInventoryBox.PlayerDeadInventoryBox_C");
		return pStaticClass;
	}


	void LuaCheckCanPlayAudio(bool* bCanPlayAudio);
	struct FVector GetGroundLocation();
	void GetVector4(const struct FVector& Dest, float Ratio);
	void UserConstructionScript();
	void HideDeadTombApparence();
	void ReceiveTick(float* DeltaSeconds);
	void SwitchToDeadTombBox();
	void ReceiveBeginPlay();
	void ShowNormal();
	void ShowShine();
	void OpenListenUIEvent(bool* bOpen);
	void ExecuteUbergraph_PlayerDeadInventoryBox(int EntryPoint);
};


}

