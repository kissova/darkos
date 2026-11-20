// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAnimNotify_AkEvent_C : public UAnimNotify
{
public:
	struct FString                                     Attach_Name;                                               
	class UAkAudioEvent*                               Event;                                                     
	bool                                               Follow;                                                    
	unsigned char                                      UnknownData00[0x7];                                        
	struct FString                                     EventName;                                                 
	TEnumAsByte<EAnimNotifyLimit>                      NotifyLimit;                                               
	unsigned char                                      UnknownData01[0x7];                                        
	class UAkAudioEvent*                               OverrideEvent_Teammate;                                    
	class UAkAudioEvent*                               OverrideEvent_Enemy;                                       
	bool                                               bUseOwnersOwnerForPawnCheck;                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass AnimNotify_AkEvent.AnimNotify_AkEvent_C");
		return pStaticClass;
	}


	void TryGetOwnerPawn(class AActor* Owner, class APawn** Pawn);
	void GetEvent(class USkeletalMeshComponent* MeshComp, class UAkAudioEvent** OutEvent);
	bool Received_Notify(class USkeletalMeshComponent** MeshComp, class UAnimSequenceBase** Animation);
};


}

