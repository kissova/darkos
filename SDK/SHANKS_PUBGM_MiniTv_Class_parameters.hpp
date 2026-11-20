// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct AMiniTv_Class_C_DestoryPhoneMesh_Params
{
};

 
struct AMiniTv_Class_C_PlayPhoneAnim_Params
{
};

 
struct AMiniTv_Class_C_TouchEnd_Params
{
	TEnumAsByte<ETouchIndex>                           Finger;                                                    
};

 
struct AMiniTv_Class_C_TouchStart_Params
{
	TEnumAsByte<ETouchIndex>                           Finger;                                                    
};

 
struct AMiniTv_Class_C_UserConstructionScript_Params
{
};

 
struct AMiniTv_Class_C_BndEvt__SkeletalMesh_K2Node_ComponentBoundEvent_0_ComponentOnInputTouchBeginSignature__DelegateSignature_Params
{
	TEnumAsByte<ETouchIndex>                           FingerIndex;                                               
	class UPrimitiveComponent*                         TouchedComponent;                                          
};

 
struct AMiniTv_Class_C_BndEvt__SkeletalMesh_K2Node_ComponentBoundEvent_1_ComponentOnInputTouchEndSignature__DelegateSignature_Params
{
	TEnumAsByte<ETouchIndex>                           FingerIndex;                                               
	class UPrimitiveComponent*                         TouchedComponent;                                          
};

 
struct AMiniTv_Class_C_ReceiveTick_Params
{
	float*                                             DeltaSeconds;                                              
};

 
struct AMiniTv_Class_C_ExecuteUbergraph_MiniTv_Class_Params
{
	int                                                EntryPoint;                                                
};

}

