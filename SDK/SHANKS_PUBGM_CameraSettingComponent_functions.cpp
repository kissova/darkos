// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UCameraSettingComponent_C::SaveCurCameraSetting(class USpringArmComponent* SprintArm)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CameraSettingComponent.CameraSettingComponent_C.SaveCurCameraSetting");

	UCameraSettingComponent_C_SaveCurCameraSetting_Params params;
	params.SprintArm = SprintArm;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UCameraSettingComponent_C::LerpCameraSettings(float LerpAlpha, const struct FSTR_CameraSetting& CameraSettings, class USpringArmComponent* SpringArm)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CameraSettingComponent.CameraSettingComponent_C.LerpCameraSettings");

	UCameraSettingComponent_C_LerpCameraSettings_Params params;
	params.LerpAlpha = LerpAlpha;
	params.CameraSettings = CameraSettings;
	params.SpringArm = SpringArm;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

