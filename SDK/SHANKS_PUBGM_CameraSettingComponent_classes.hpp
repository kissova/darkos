// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCameraSettingComponent_C : public UActorComponent
{
public:
	float                                              Current_Target_Arm_Length;                                 
	float                                              CurrentCameraLagSpeed;                                     
	struct FVector                                     CurrentSocketOffset;                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CameraSettingComponent.CameraSettingComponent_C");
		return pStaticClass;
	}


	void SaveCurCameraSetting(class USpringArmComponent* SprintArm);
	void LerpCameraSettings(float LerpAlpha, const struct FSTR_CameraSetting& CameraSettings, class USpringArmComponent* SpringArm);
};


}

