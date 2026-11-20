// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_DoorMetallic_C_UserConstructionScript_Params
{
};

 
struct ABP_DoorMetallic_C_Timeline_0__FinishedFunc_Params
{
};

 
struct ABP_DoorMetallic_C_Timeline_0__UpdateFunc_Params
{
};

 
struct ABP_DoorMetallic_C_ActionDoorOnClient_Params
{
	int*                                               doorStateDst;                                              
	bool*                                              bExtraDoor;                                                
};

 
struct ABP_DoorMetallic_C_BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                       
	class AActor*                                      OtherActor;                                                
	class UPrimitiveComponent*                         OtherComp;                                                 
	int                                                OtherBodyIndex;                                            
	bool                                               bFromSweep;                                                
	struct FHitResult                                  SweepResult;                                               
};

 
struct ABP_DoorMetallic_C_BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                       
	class AActor*                                      OtherActor;                                                
	class UPrimitiveComponent*                         OtherComp;                                                 
	int                                                OtherBodyIndex;                                            
};

 
struct ABP_DoorMetallic_C_ActionDoorImmediatly_Params
{
	int*                                               doorStateDst;                                              
	bool*                                              bExtraDoor;                                                
};

 
struct ABP_DoorMetallic_C_ReceiveBeginPlay_Params
{
};

 
struct ABP_DoorMetallic_C_OnBPRespawned_Params
{
};

 
struct ABP_DoorMetallic_C_ExecuteUbergraph_BP_DoorMetallic_Params
{
	int                                                EntryPoint;                                                
};

}

