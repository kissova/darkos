// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_VehicleUser_C_EditorAxisMoveFreezed_Params
{
};

 
struct UBP_VehicleUser_C_SetUAVSpeedPercent_Params
{
	float                                              SpeedPercent;                                              
};

 
struct UBP_VehicleUser_C_SetUAVCameraMode_Params
{
	bool                                               FreeCamera;                                                
};

 
struct UBP_VehicleUser_C_OnUnmanedVehicleFuelChanged_Params
{
	float                                              Fuel;                                                      
	float                                              MacFuel;                                                   
};

 
struct UBP_VehicleUser_C_SendUIMsgWhenChangeSeatCompleted_Params
{
};

 
struct UBP_VehicleUser_C_SendUIMsgWhenEnterVehicleCompleted_Params
{
};

 
struct UBP_VehicleUser_C_SendUIMsgWhenExitVehicleCompleted_Params
{
};

 
struct UBP_VehicleUser_C_GetVehicleGoStraight_Params
{
	float                                              VehicleGoStraight;                                         
};

 
struct UBP_VehicleUser_C_SetHelicopterCameraMode_Params
{
	bool                                               IsFreeCamera;                                              
};

 
struct UBP_VehicleUser_C_HandleCharacterUnequipWeapon_Params
{
	class ASTExtraWeapon*                              NewParam;                                                  
};

 
struct UBP_VehicleUser_C_HandleCharacterEquipWeapon_Params
{
	class ASTExtraWeapon*                              NewWeapon;                                                 
	TEnumAsByte<ESurviveWeaponPropSlot>                Slot;                                                      
};

 
struct UBP_VehicleUser_C_SwitchToLastWeapon_Params
{
};

 
struct UBP_VehicleUser_C_CacheLastUseWeaponSlot_Params
{
};

 
struct UBP_VehicleUser_C_SetDrivingViewMode_Params
{
	int                                                int_mode;                                                  
};

 
struct UBP_VehicleUser_C_ResetInputs_Params
{
};

 
struct UBP_VehicleUser_C_OnMotorcycleContactChanged_Params
{
};

 
struct UBP_VehicleUser_C_FixGoStraight_Params
{
	float                                              InMoveRightRate;                                           
	float                                              GoStraightThreshold;                                       
	float                                              OutMoveRightRate;                                          
};

 
struct UBP_VehicleUser_C_GetPlayerController_Params
{
	class ABP_STExtraPlayerController_C*               PlayerController;                                          
};

 
struct UBP_VehicleUser_C_ExitVehicle_Params
{
};

 
struct UBP_VehicleUser_C_EnterVehicle_Params
{
	bool                                               IsDriver;                                                  
};

 
struct UBP_VehicleUser_C_OnEnterVehicleCompleted_Params
{
	ESTExtraVehicleSeatType*                           SeatType;                                                  
};

 
struct UBP_VehicleUser_C_OnExitVehicleCompleted_Params
{
};

 
struct UBP_VehicleUser_C_ReceiveBeginPlay_Params
{
};

 
struct UBP_VehicleUser_C_OnChangeVehicleSeatCompleted_Params
{
	ESTExtraVehicleSeatType*                           SeatType;                                                  
};

 
struct UBP_VehicleUser_C_OnCurrrentClosestVehicleChanged_Params
{
};

 
struct UBP_VehicleUser_C_EventSetDrivingViewMode_Params
{
	int                                                IntValue;                                                  
};

 
struct UBP_VehicleUser_C_OnInputAxisMoveForward_Params
{
	float*                                             Rate;                                                      
};

 
struct UBP_VehicleUser_C_OnInputAxisMoveRight_Params
{
	float*                                             Rate;                                                      
};

 
struct UBP_VehicleUser_C_EventSetCarMusicSwitch_Params
{
	bool                                               BoolValue;                                                 
};

 
struct UBP_VehicleUser_C_EventSetHelicopterFreeCamera_Params
{
	bool                                               BoolValue;                                                 
};

 
struct UBP_VehicleUser_C_OnShutDownUnmannedVehicleCompleted_Params
{
	float*                                             cdTime;                                                    
};

 
struct UBP_VehicleUser_C_OnLaunchUnmannedVehicleCompleted_Params
{
};

 
struct UBP_VehicleUser_C_OnPauseUnmannedVehicleCompleted_Params
{
};

 
struct UBP_VehicleUser_C_EventSetUAVFreeCamera_Params
{
	bool                                               BoolValue;                                                 
};

 
struct UBP_VehicleUser_C_EventSetSpeedPercent_Params
{
	float                                              FloatValue;                                                
};

 
struct UBP_VehicleUser_C_EventUAVSingleOperate_Params
{
	bool                                               BoolValue;                                                 
};

 
struct UBP_VehicleUser_C_ExecuteUbergraph_BP_VehicleUser_Params
{
	int                                                EntryPoint;                                                
};

}

