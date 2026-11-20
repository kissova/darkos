// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_AutoAimingComponent_C_CheckInAngle_Params
{
	class AActor**                                     EnemeyActor;                                               
	float*                                             MaxAngle;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoAimingComponent_C_CheckSmoke_Params
{
	struct FVector                                     StartPoint;                                                
	struct FVector                                     EndPoint;                                                  
	class AActor**                                     EnemeyActor;                                               
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoAimingComponent_C_CanEnemeyRaycastReach_Params
{
	struct FVector                                     StartPoint;                                                
	struct FVector                                     EndPoint;                                                  
	class AActor**                                     EnemeyActor;                                               
	struct FName                                       OutHitBoneName;                                            
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoAimingComponent_C_BPDrawDebugInfo_Params
{
	TArray<float>*                                     AutoAimParams;                                             
};

 
struct UBP_AutoAimingComponent_C_ExecuteUbergraph_BP_AutoAimingComponent_Params
{
	int                                                EntryPoint;                                                
};

}

