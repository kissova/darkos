// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_VehicleUser_C : public UVehicleUserComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	bool                                               AxisMoveForwardFreezed;                                    
	bool                                               AxisMoveRightFreezed;                                      
	unsigned char                                      UnknownData00[0x2];                                        
	float                                              Fuel;                                                      
	float                                              FuelMax;                                                   
	float                                              HP;                                                        
	float                                              HPMax;                                                     
	float                                              RawSpeed;                                                  
	ESTExtraVehicleSeatType                            SeatType;                                                  
	TEnumAsByte<ESurviveWeaponPropSlot>                LastWeaponSlot;                                            
	unsigned char                                      UnknownData01[0x2];                                        
	float                                              UnmanedFuel;                                               
	float                                              UnmanedFuelMax;                                            
	float                                              UnmanedHP;                                                 
	float                                              UnmanedHPMax;                                              
	float                                              UnmanedCallBackTime;                                       
	bool                                               bShowUnmanedLowPowerTips;                                  

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_VehicleUser.BP_VehicleUser_C");
		return pStaticClass;
	}


	void EditorAxisMoveFreezed();
	void SetUAVSpeedPercent(float SpeedPercent);
	void SetUAVCameraMode(bool FreeCamera);
	void OnUnmanedVehicleFuelChanged(float Fuel, float MacFuel);
	void SendUIMsgWhenChangeSeatCompleted();
	void SendUIMsgWhenEnterVehicleCompleted();
	void SendUIMsgWhenExitVehicleCompleted();
	void GetVehicleGoStraight(float* VehicleGoStraight);
	void SetHelicopterCameraMode(bool IsFreeCamera);
	void HandleCharacterUnequipWeapon(class ASTExtraWeapon* NewParam);
	void HandleCharacterEquipWeapon(class ASTExtraWeapon* NewWeapon, TEnumAsByte<ESurviveWeaponPropSlot> Slot);
	void SwitchToLastWeapon();
	void CacheLastUseWeaponSlot();
	void SetDrivingViewMode(int int_mode);
	void ResetInputs();
	void OnMotorcycleContactChanged();
	void FixGoStraight(float InMoveRightRate, float GoStraightThreshold, float* OutMoveRightRate);
	void GetPlayerController(class ABP_STExtraPlayerController_C** PlayerController);
	void ExitVehicle();
	void EnterVehicle(bool IsDriver);
	void OnEnterVehicleCompleted(ESTExtraVehicleSeatType* SeatType);
	void OnExitVehicleCompleted();
	void ReceiveBeginPlay();
	void OnChangeVehicleSeatCompleted(ESTExtraVehicleSeatType* SeatType);
	void OnCurrrentClosestVehicleChanged();
	void EventSetDrivingViewMode(int IntValue);
	void OnInputAxisMoveForward(float* Rate);
	void OnInputAxisMoveRight(float* Rate);
	void EventSetCarMusicSwitch(bool BoolValue);
	void EventSetHelicopterFreeCamera(bool BoolValue);
	void OnShutDownUnmannedVehicleCompleted(float* cdTime);
	void OnLaunchUnmannedVehicleCompleted();
	void OnPauseUnmannedVehicleCompleted();
	void EventSetUAVFreeCamera(bool BoolValue);
	void EventSetSpeedPercent(float FloatValue);
	void EventUAVSingleOperate(bool BoolValue);
	void ExecuteUbergraph_BP_VehicleUser(int EntryPoint);
};


}

