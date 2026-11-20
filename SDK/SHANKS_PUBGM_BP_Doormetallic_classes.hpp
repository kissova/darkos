// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_DoorMetallic_C : public APUBGDoor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UBoxComponent*                               InterForce;                                                
	class UBoxComponent*                               Interaction;                                               
	class USceneComponent*                             Scene;                                                     
	class UBoxComponent*                               Box;                                                       
	class UStaticMeshComponent*                        StaticMesh;                                                
	float                                              Timeline_0_DoorNormalCurve_3AD59F7245D2BF58B24C7D8879A0FBEE; 
	TEnumAsByte<ETimelineDirection>                    Timeline_0__Direction_3AD59F7245D2BF58B24C7D8879A0FBEE;    
	unsigned char                                      UnknownData00[0x3];                                        
	class UTimelineComponent*                          Timeline_1;                                                
	float                                              From;                                                      
	float                                              To;                                                        
	int                                                FromState;                                                 
	int                                                ToState;                                                   
	class UAkAudioEvent*                               OpenDoorAudio;                                             
	class UAkAudioEvent*                               CloseDoorAudio;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_Doormetallic.BP_DoorMetallic_C");
		return pStaticClass;
	}


	void UserConstructionScript();
	void Timeline_0__FinishedFunc();
	void Timeline_0__UpdateFunc();
	void ActionDoorOnClient(int* doorStateDst, bool* bExtraDoor);
	void BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex);
	void ActionDoorImmediatly(int* doorStateDst, bool* bExtraDoor);
	void ReceiveBeginPlay();
	void OnBPRespawned();
	void ExecuteUbergraph_BP_DoorMetallic(int EntryPoint);
};


}

