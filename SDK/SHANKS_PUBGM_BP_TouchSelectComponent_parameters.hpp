// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_TouchSelectComponent_C_RefreshViewportSize_Params
{
	struct FVector2D                                   OldSize;                                                   
	struct FVector2D                                   NewSize;                                                   
};

 
struct UBP_TouchSelectComponent_C_ModifyTouchLoc_Params
{
	struct FGeometry                                   MyGeometry;                                                
	struct FVector2D                                   TouchLoc;                                                  
	struct FVector2D                                   ReturnValue;                                               
};

 
struct UBP_TouchSelectComponent_C_ReceiveBeginPlay_Params
{
};

 
struct UBP_TouchSelectComponent_C_ExecuteUbergraph_BP_TouchSelectComponent_Params
{
	int                                                EntryPoint;                                                
};

}

