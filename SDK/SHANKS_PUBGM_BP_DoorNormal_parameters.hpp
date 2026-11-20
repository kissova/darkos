// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ABP_DoorNormal_C_UserConstructionScript_Params
{
};

 
struct ABP_DoorNormal_C_ReceiveBeginPlay_Params
{
};

 
struct ABP_DoorNormal_C_ReceiveAnyDamage_Params
{
	float*                                             Damage;                                                    
	class UDamageType**                                DamageType;                                                
	class AController**                                InstigatedBy;                                              
	class AActor**                                     DamageCauser;                                              
};

 
struct ABP_DoorNormal_C_EventTimer_Params
{
};

 
struct ABP_DoorNormal_C_BndEvt__Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                       
	class AActor*                                      OtherActor;                                                
	class UPrimitiveComponent*                         OtherComp;                                                 
	int                                                OtherBodyIndex;                                            
	bool                                               bFromSweep;                                                
	struct FHitResult                                  SweepResult;                                               
};

 
struct ABP_DoorNormal_C_BndEvt__Box_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                       
	class AActor*                                      OtherActor;                                                
	class UPrimitiveComponent*                         OtherComp;                                                 
	int                                                OtherBodyIndex;                                            
};

 
struct ABP_DoorNormal_C_ActionDoorOnClient_Params
{
	int*                                               doorStateDst;                                              
	bool*                                              bExtraDoor;                                                
};

 
struct ABP_DoorNormal_C_BP_DoorBroken_Params
{
	bool*                                              isBeginPlay;                                               
	bool*                                              bExtraDoor;                                                
};

 
struct ABP_DoorNormal_C_ActionDoorImmediatly_Params
{
	int*                                               doorStateDst;                                              
	bool*                                              bExtraDoor;                                                
};

 
struct ABP_DoorNormal_C_OnBPRespawned_Params
{
};

 
struct ABP_DoorNormal_C_SetInnerBoxOverlap_Params
{
	bool*                                              bGenerateOverlap;                                          
};

 
struct ABP_DoorNormal_C_ExecuteUbergraph_BP_DoorNormal_Params
{
	int                                                EntryPoint;                                                
};

}

