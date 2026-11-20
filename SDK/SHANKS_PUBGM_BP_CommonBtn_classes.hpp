// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_CommonBtn_C : public UCommonBtnComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	int                                                OpenMode;                                                  
	TEnumAsByte<ECommonBtn>                            BtnType;                                                   
	bool                                               bShow;                                                     
	bool                                               bOpen;                                                     

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_CommonBtn.BP_CommonBtn_C");
		return pStaticClass;
	}


	void OnChangeOpenDoorMode(int OpenMode);
	void UnRegistShowDoorButton();
	void OnShowDoorButton(TEnumAsByte<ECommonBtn> Type, int OpenParam);
	void RegistShowDoorButton();
	void ShowDoorButton(bool Show, bool Open, int OpenMode);
	void GetPlayerController(class ABP_STExtraPlayerController_C** PlayerController);
	void ReceiveBeginPlay();
	void CharacterStatusChanged(bool IsNearDeath, bool IsRescueingOther);
	void PlayerControllerReconnectedDelegate_Event_1();
	void UI_Click(bool bSimulateExtraDoor, int OpenParam);
	void ToogleDoor();
	void BP_ShowDoorBtn(bool* bShow, bool* bOpen, int* doorOpenMode);
	void AutoOpenDoor(bool BoolValue);
	void BP_SimulateUIClick(bool* bExtraDoor);
	void ExecuteUbergraph_BP_CommonBtn(int EntryPoint);
};


}

