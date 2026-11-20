// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UAITouchSelectComp_C_UpdateViewportLocalSize_Params
{
};

 
struct UAITouchSelectComp_C_ModifyTouchLoc_Params
{
	struct FGeometry                                   MyGeometry;                                                
	struct FVector2D                                   TouchLoc;                                                  
	struct FVector2D                                   ReturnValue;                                               
};

 
struct UAITouchSelectComp_C_ReceiveBeginPlay_Params
{
};

 
struct UAITouchSelectComp_C_OnTouchSelect_Params
{
	class AActor*                                      SelectActor;                                               
	struct FVector2D                                   TouchLoc;                                                  
};

 
struct UAITouchSelectComp_C_OnViewPortChange_Params
{
	struct FVector2D                                   OldViewportSize;                                           
	struct FVector2D                                   NewViewportSize;                                           
};

 
struct UAITouchSelectComp_C_ExecuteUbergraph_AITouchSelectComp_Params
{
	int                                                EntryPoint;                                                
};

}

