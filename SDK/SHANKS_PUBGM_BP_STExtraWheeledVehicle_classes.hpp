// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_STExtraWheeledVehicle_C : public ASTExtraWheeledVehicle
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UBP_VehicleMusic_C*                          BP_VehicleMusic;                                           
	class UWheeledVehicleProtectionComponent*          VehicleProtection;                                         
	class UBP_VehicleShowFrameComp_C*                  BP_VehicleShowFrameComp;                                   
	class UVehicleAvatarComponent_BP_C*                VehicleAvatarComponent_BP;                                 
	class UCameraComponent*                            Camera;                                                    
	class UVehicleSpringArmComponent*                  vehicleSpringArm;                                          
	bool                                               IsPlayingEngineAk;                                         
	unsigned char                                      UnknownData00[0x7];                                        
	struct FName                                       TailLightParamName;                                        
	struct FName                                       FrontLightParamName;                                       
	struct FName                                       FPPBoostLightParamName;                                    
	bool                                               bEngineStarted;                                            
	unsigned char                                      UnknownData01[0x3];                                        
	float                                              LastOverlapShakeTime;                                      
	float                                              OverlapShakeInterval;                                      
	bool                                               bLobbyShow;                                                
	bool                                               bInvincibleProtect;                                        
	bool                                               EnableLightEffect;                                         
	bool                                               bEnableUpdateExhuastEffectBP;                              

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_STExtraWheeledVehicle.BP_STExtraWheeledVehicle_C");
		return pStaticClass;
	}


	void OnClientVehicleHealthStateChangedToDestory();
	void CreateDMI();
	void SetDMIParam(class UMaterialInstanceDynamic* Dim, const struct FName& Name, float Value);
	void UpdateExhaustFx(const struct FName& ExhaustName);
	void UserConstructionScript();
	void OnEngineStart();
	void OnEngineStop();
	void ReceiveBeginPlay();
	void OnSetTailLightValue(float* LightValue);
	void OnBoostingChanged();
	void VehicleMeshChanged();
	void BPPlayOverlapDamageCameraShake();
	void ReceiveActorBeginOverlap(class AActor** OtherActor);
	void AdvanceVehicleMeshChanged();
	void ExecuteUbergraph_BP_STExtraWheeledVehicle(int EntryPoint);
};


}

