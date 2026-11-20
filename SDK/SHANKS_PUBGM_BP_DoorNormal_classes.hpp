// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_DoorNormal_C : public APUBGDoor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UBoxComponent*                               InterForce;                                                
	class UBoxComponent*                               Interaction;                                               
	class USceneComponent*                             Scene;                                                     
	class UBoxComponent*                               Box;                                                       
	class UStaticMeshComponent*                        StaticMesh;                                                
	class UStaticMesh*                                 BrokenMesh;                                                
	float                                              HP;                                                        
	float                                              HPTimer;                                                   
	float                                              To;                                                        
	float                                              From;                                                      
	float                                              HPDummy;                                                   
	unsigned char                                      UnknownData00[0x4];                                        
	struct FTimerHandle                                DummyTimerHandler;                                         
	float                                              GrenadeDamageRatio;                                        
	int                                                FromState;                                                 
	int                                                ToState;                                                   
	unsigned char                                      UnknownData01[0x4];                                        
	class UAkAudioEvent*                               CloseDoorAudio;                                            
	class UAkAudioEvent*                               OpenDoorAudio;                                             

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_DoorNormal.BP_DoorNormal_C");
		return pStaticClass;
	}


	void UserConstructionScript();
	void ReceiveBeginPlay();
	void ReceiveAnyDamage(float* Damage, class UDamageType** DamageType, class AController** InstigatedBy, class AActor** DamageCauser);
	void EventTimer();
	void BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex);
	void ActionDoorOnClient(int* doorStateDst, bool* bExtraDoor);
	void BP_DoorBroken(bool* isBeginPlay, bool* bExtraDoor);
	void ActionDoorImmediatly(int* doorStateDst, bool* bExtraDoor);
	void OnBPRespawned();
	void SetInnerBoxOverlap(bool* bGenerateOverlap);
	void ExecuteUbergraph_BP_DoorNormal(int EntryPoint);
};


}

