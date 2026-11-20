// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class AMiniTv_Class_C : public ALuaActor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UCameraComponent*                            Camera;                                                    
	class UMinitvAvatarComponent_BP_C*                 MinitvAvatarComponent_BP;                                  
	class USkeletalMeshComponent*                      SkeletalMesh;                                              
	class UCapsuleComponent*                           Capsule;                                                   
	class USkeletalMeshComponent*                      PhoneMesh;                                                 

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass MiniTv_Class.MiniTv_Class_C");
		return pStaticClass;
	}


	void DestoryPhoneMesh();
	void PlayPhoneAnim();
	void TouchEnd(TEnumAsByte<ETouchIndex> Finger);
	void TouchStart(TEnumAsByte<ETouchIndex> Finger);
	void UserConstructionScript();
	void BndEvt__SkeletalMesh_K2Node_ComponentBoundEvent_0_ComponentOnInputTouchBeginSignature__DelegateSignature(TEnumAsByte<ETouchIndex> FingerIndex, class UPrimitiveComponent* TouchedComponent);
	void BndEvt__SkeletalMesh_K2Node_ComponentBoundEvent_1_ComponentOnInputTouchEndSignature__DelegateSignature(TEnumAsByte<ETouchIndex> FingerIndex, class UPrimitiveComponent* TouchedComponent);
	void ReceiveTick(float* DeltaSeconds);
	void ExecuteUbergraph_MiniTv_Class(int EntryPoint);
};


}

