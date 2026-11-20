// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_CommonBtn_C_OnChangeOpenDoorMode_Params
{
	int                                                OpenMode;                                                  
};

 
struct UBP_CommonBtn_C_UnRegistShowDoorButton_Params
{
};

 
struct UBP_CommonBtn_C_OnShowDoorButton_Params
{
	TEnumAsByte<ECommonBtn>                            Type;                                                      
	int                                                OpenParam;                                                 
};

 
struct UBP_CommonBtn_C_RegistShowDoorButton_Params
{
};

 
struct UBP_CommonBtn_C_ShowDoorButton_Params
{
	bool                                               Show;                                                      
	bool                                               Open;                                                      
	int                                                OpenMode;                                                  
};

 
struct UBP_CommonBtn_C_GetPlayerController_Params
{
	class ABP_STExtraPlayerController_C*               PlayerController;                                          
};

 
struct UBP_CommonBtn_C_ReceiveBeginPlay_Params
{
};

 
struct UBP_CommonBtn_C_CharacterStatusChanged_Params
{
	bool                                               IsNearDeath;                                               
	bool                                               IsRescueingOther;                                          
};

 
struct UBP_CommonBtn_C_PlayerControllerReconnectedDelegate_Event_1_Params
{
};

 
struct UBP_CommonBtn_C_UI_Click_Params
{
	bool                                               bSimulateExtraDoor;                                        
	int                                                OpenParam;                                                 
};

 
struct UBP_CommonBtn_C_ToogleDoor_Params
{
};

 
struct UBP_CommonBtn_C_BP_ShowDoorBtn_Params
{
	bool*                                              bShow;                                                     
	bool*                                              bOpen;                                                     
	int*                                               doorOpenMode;                                              
};

 
struct UBP_CommonBtn_C_AutoOpenDoor_Params
{
	bool                                               BoolValue;                                                 
};

 
struct UBP_CommonBtn_C_BP_SimulateUIClick_Params
{
	bool*                                              bExtraDoor;                                                
};

 
struct UBP_CommonBtn_C_ExecuteUbergraph_BP_CommonBtn_Params
{
	int                                                EntryPoint;                                                
};

}

