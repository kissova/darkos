// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAnimNotify_SelfAkEvent_C : public UAnimNotify_AkEvent_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass AnimNotify_SelfAkEvent.AnimNotify_SelfAkEvent_C");
		return pStaticClass;
	}


	bool PlayAkEvent(class USkeletalMeshComponent* MeshComp);
	bool Received_Notify(class USkeletalMeshComponent** MeshComp, class UAnimSequenceBase** Animation);
};


}

