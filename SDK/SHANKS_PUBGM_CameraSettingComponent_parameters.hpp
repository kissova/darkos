// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UCameraSettingComponent_C_SaveCurCameraSetting_Params
{
	class USpringArmComponent*                         SprintArm;                                                 
};

 
struct UCameraSettingComponent_C_LerpCameraSettings_Params
{
	float                                              LerpAlpha;                                                 
	struct FSTR_CameraSetting                          CameraSettings;                                            
	class USpringArmComponent*                         SpringArm;                                                 
};

}

