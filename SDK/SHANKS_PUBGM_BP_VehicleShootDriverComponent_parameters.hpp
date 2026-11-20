// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_VehicleShootDriverComponent_C_ReceiveBeginPlay_Params
{
};

 
struct UBP_VehicleShootDriverComponent_C_ReceiveEndPlay_Params
{
	TEnumAsByte<EEndPlayReason>*                       EndPlayReason;                                             
};

 
struct UBP_VehicleShootDriverComponent_C_ExecuteUbergraph_BP_VehicleShootDriverComponent_Params
{
	int                                                EntryPoint;                                                
};

}

