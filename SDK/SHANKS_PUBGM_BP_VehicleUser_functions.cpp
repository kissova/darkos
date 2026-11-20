// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UBP_VehicleUser_C::EditorAxisMoveFreezed()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EditorAxisMoveFreezed");

	UBP_VehicleUser_C_EditorAxisMoveFreezed_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::SetUAVSpeedPercent(float SpeedPercent)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SetUAVSpeedPercent");

	UBP_VehicleUser_C_SetUAVSpeedPercent_Params params;
	params.SpeedPercent = SpeedPercent;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::SetUAVCameraMode(bool FreeCamera)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SetUAVCameraMode");

	UBP_VehicleUser_C_SetUAVCameraMode_Params params;
	params.FreeCamera = FreeCamera;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UBP_VehicleUser_C::OnUnmanedVehicleFuelChanged(float Fuel, float MacFuel)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnUnmanedVehicleFuelChanged");

	UBP_VehicleUser_C_OnUnmanedVehicleFuelChanged_Params params;
	params.Fuel = Fuel;
	params.MacFuel = MacFuel;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::SendUIMsgWhenChangeSeatCompleted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SendUIMsgWhenChangeSeatCompleted");

	UBP_VehicleUser_C_SendUIMsgWhenChangeSeatCompleted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::SendUIMsgWhenEnterVehicleCompleted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SendUIMsgWhenEnterVehicleCompleted");

	UBP_VehicleUser_C_SendUIMsgWhenEnterVehicleCompleted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::SendUIMsgWhenExitVehicleCompleted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SendUIMsgWhenExitVehicleCompleted");

	UBP_VehicleUser_C_SendUIMsgWhenExitVehicleCompleted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::GetVehicleGoStraight(float* VehicleGoStraight)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.GetVehicleGoStraight");

	UBP_VehicleUser_C_GetVehicleGoStraight_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (VehicleGoStraight != nullptr)
		*VehicleGoStraight = params.VehicleGoStraight;
}


 
 
 
 

void UBP_VehicleUser_C::SetHelicopterCameraMode(bool IsFreeCamera)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SetHelicopterCameraMode");

	UBP_VehicleUser_C_SetHelicopterCameraMode_Params params;
	params.IsFreeCamera = IsFreeCamera;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::HandleCharacterUnequipWeapon(class ASTExtraWeapon* NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.HandleCharacterUnequipWeapon");

	UBP_VehicleUser_C_HandleCharacterUnequipWeapon_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UBP_VehicleUser_C::HandleCharacterEquipWeapon(class ASTExtraWeapon* NewWeapon, TEnumAsByte<ESurviveWeaponPropSlot> Slot)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.HandleCharacterEquipWeapon");

	UBP_VehicleUser_C_HandleCharacterEquipWeapon_Params params;
	params.NewWeapon = NewWeapon;
	params.Slot = Slot;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::SwitchToLastWeapon()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SwitchToLastWeapon");

	UBP_VehicleUser_C_SwitchToLastWeapon_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::CacheLastUseWeaponSlot()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.CacheLastUseWeaponSlot");

	UBP_VehicleUser_C_CacheLastUseWeaponSlot_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::SetDrivingViewMode(int int_mode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.SetDrivingViewMode");

	UBP_VehicleUser_C_SetDrivingViewMode_Params params;
	params.int_mode = int_mode;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::ResetInputs()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.ResetInputs");

	UBP_VehicleUser_C_ResetInputs_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::OnMotorcycleContactChanged()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnMotorcycleContactChanged");

	UBP_VehicleUser_C_OnMotorcycleContactChanged_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UBP_VehicleUser_C::FixGoStraight(float InMoveRightRate, float GoStraightThreshold, float* OutMoveRightRate)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.FixGoStraight");

	UBP_VehicleUser_C_FixGoStraight_Params params;
	params.InMoveRightRate = InMoveRightRate;
	params.GoStraightThreshold = GoStraightThreshold;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutMoveRightRate != nullptr)
		*OutMoveRightRate = params.OutMoveRightRate;
}


 
 
 
 

void UBP_VehicleUser_C::GetPlayerController(class ABP_STExtraPlayerController_C** PlayerController)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.GetPlayerController");

	UBP_VehicleUser_C_GetPlayerController_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (PlayerController != nullptr)
		*PlayerController = params.PlayerController;
}


 
 

void UBP_VehicleUser_C::ExitVehicle()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.ExitVehicle");

	UBP_VehicleUser_C_ExitVehicle_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EnterVehicle(bool IsDriver)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EnterVehicle");

	UBP_VehicleUser_C_EnterVehicle_Params params;
	params.IsDriver = IsDriver;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::OnEnterVehicleCompleted(ESTExtraVehicleSeatType* SeatType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnEnterVehicleCompleted");

	UBP_VehicleUser_C_OnEnterVehicleCompleted_Params params;
	params.SeatType = SeatType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::OnExitVehicleCompleted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnExitVehicleCompleted");

	UBP_VehicleUser_C_OnExitVehicleCompleted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.ReceiveBeginPlay");

	UBP_VehicleUser_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::OnChangeVehicleSeatCompleted(ESTExtraVehicleSeatType* SeatType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnChangeVehicleSeatCompleted");

	UBP_VehicleUser_C_OnChangeVehicleSeatCompleted_Params params;
	params.SeatType = SeatType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::OnCurrrentClosestVehicleChanged()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnCurrrentClosestVehicleChanged");

	UBP_VehicleUser_C_OnCurrrentClosestVehicleChanged_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EventSetDrivingViewMode(int IntValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EventSetDrivingViewMode");

	UBP_VehicleUser_C_EventSetDrivingViewMode_Params params;
	params.IntValue = IntValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::OnInputAxisMoveForward(float* Rate)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnInputAxisMoveForward");

	UBP_VehicleUser_C_OnInputAxisMoveForward_Params params;
	params.Rate = Rate;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::OnInputAxisMoveRight(float* Rate)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnInputAxisMoveRight");

	UBP_VehicleUser_C_OnInputAxisMoveRight_Params params;
	params.Rate = Rate;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EventSetCarMusicSwitch(bool BoolValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EventSetCarMusicSwitch");

	UBP_VehicleUser_C_EventSetCarMusicSwitch_Params params;
	params.BoolValue = BoolValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EventSetHelicopterFreeCamera(bool BoolValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EventSetHelicopterFreeCamera");

	UBP_VehicleUser_C_EventSetHelicopterFreeCamera_Params params;
	params.BoolValue = BoolValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::OnShutDownUnmannedVehicleCompleted(float* cdTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnShutDownUnmannedVehicleCompleted");

	UBP_VehicleUser_C_OnShutDownUnmannedVehicleCompleted_Params params;
	params.cdTime = cdTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::OnLaunchUnmannedVehicleCompleted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnLaunchUnmannedVehicleCompleted");

	UBP_VehicleUser_C_OnLaunchUnmannedVehicleCompleted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UBP_VehicleUser_C::OnPauseUnmannedVehicleCompleted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.OnPauseUnmannedVehicleCompleted");

	UBP_VehicleUser_C_OnPauseUnmannedVehicleCompleted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EventSetUAVFreeCamera(bool BoolValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EventSetUAVFreeCamera");

	UBP_VehicleUser_C_EventSetUAVFreeCamera_Params params;
	params.BoolValue = BoolValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EventSetSpeedPercent(float FloatValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EventSetSpeedPercent");

	UBP_VehicleUser_C_EventSetSpeedPercent_Params params;
	params.FloatValue = FloatValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::EventUAVSingleOperate(bool BoolValue)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.EventUAVSingleOperate");

	UBP_VehicleUser_C_EventUAVSingleOperate_Params params;
	params.BoolValue = BoolValue;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_VehicleUser_C::ExecuteUbergraph_BP_VehicleUser(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_VehicleUser.BP_VehicleUser_C.ExecuteUbergraph_BP_VehicleUser");

	UBP_VehicleUser_C_ExecuteUbergraph_BP_VehicleUser_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

