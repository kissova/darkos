// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ALobby_Main_int_C_RegistPersistLevelObjs_Params
{
	class UFrontendUtils*                              Utils;                                                     
};

 
struct ALobby_Main_int_C_InpActEvt_N_K2Node_InputKeyEvent_12_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ALobby_Main_int_C_InpActEvt_B_K2Node_InputKeyEvent_11_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ALobby_Main_int_C_InpActEvt_Android_Back_K2Node_InputKeyEvent_10_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ALobby_Main_int_C_InpActEvt_BackSpace_K2Node_InputKeyEvent_9_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ALobby_Main_int_C_InpActEvt_E_K2Node_InputKeyEvent_8_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ALobby_Main_int_C_InpActEvt_G_K2Node_InputKeyEvent_7_Params
{
	struct FKey                                        Key;                                                       
};

 
struct ALobby_Main_int_C_InpAxisKeyEvt_RotationRate_K2Node_InputVectorAxisEvent_1_Params
{
	struct FVector                                     AxisValue;                                                 
};

 
struct ALobby_Main_int_C_ReceiveTick_Params
{
	float*                                             DeltaSeconds;                                              
};

 
struct ALobby_Main_int_C_ReceiveBeginPlay_Params
{
};

 
struct ALobby_Main_int_C_ReceiveEndPlay_Params
{
	TEnumAsByte<EEndPlayReason>*                       EndPlayReason;                                             
};

 
struct ALobby_Main_int_C_OnViewportChanged_Params
{
	struct FVector2D                                   OldViewportSize;                                           
	struct FVector2D                                   NewViewportSize;                                           
};

 
struct ALobby_Main_int_C_ExecuteUbergraph_Lobby_Main_int_Params
{
	int                                                EntryPoint;                                                
};

 
struct ALobby_Main_int_C_Dispatcher_OpenBox__DelegateSignature_Params
{
	class ASkeletalMeshActor*                          NewParam;                                                  
};

}

