// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_STExtraWheeledVehicle_C_OnClientVehicleHealthStateChangedToDestory_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_CreateDMI_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_SetDMIParam_Params
{
	class UMaterialInstanceDynamic*                    Dim;                                                       
	struct FName                                       Name;                                                      
	float                                              Value;                                                     
};

 
struct ABP_STExtraWheeledVehicle_C_UpdateExhaustFx_Params
{
	struct FName                                       ExhaustName;                                               
};

 
struct ABP_STExtraWheeledVehicle_C_UserConstructionScript_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_OnEngineStart_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_OnEngineStop_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_ReceiveBeginPlay_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_OnSetTailLightValue_Params
{
	float*                                             LightValue;                                                
};

 
struct ABP_STExtraWheeledVehicle_C_OnBoostingChanged_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_VehicleMeshChanged_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_BPPlayOverlapDamageCameraShake_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_ReceiveActorBeginOverlap_Params
{
	class AActor**                                     OtherActor;                                                
};

 
struct ABP_STExtraWheeledVehicle_C_AdvanceVehicleMeshChanged_Params
{
};

 
struct ABP_STExtraWheeledVehicle_C_ExecuteUbergraph_BP_STExtraWheeledVehicle_Params
{
	int                                                EntryPoint;                                                
};

}

