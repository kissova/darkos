// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_AutoNav_C_CheckObstacle_Params
{
	struct FVector                                     StartLocation;                                             
	struct FVector                                     EndLoc;                                                    
	bool                                               bRet;                                                      
};

 
struct UBP_AutoNav_C_IsArrivalDesc_Ex_Params
{
	struct FVector                                     ActorLocation;                                             
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoNav_C_IsPartialPathFinding_Params
{
	bool                                               bRet;                                                      
};

 
struct UBP_AutoNav_C_IsSwim_Params
{
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoNav_C_GetLastMinDistance_Params
{
	float                                              Distance;                                                  
};

 
struct UBP_AutoNav_C_CheckCharacterPoseState_Params
{
	class ASTExtraPlayerController**                   PC;                                                        
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoNav_C_StopPlayerAutoSprint_Params
{
};

 
struct UBP_AutoNav_C_ShowStopMoveResult_Params
{
	EPlayerAutoNavResult                               Result;                                                    
};

 
struct UBP_AutoNav_C_ShowTips_Params
{
	int                                                ID;                                                        
};

 
struct UBP_AutoNav_C_CallSetPlayerAutoSprint_Params
{
	class ASTExtraPlayerController*                    Target;                                                    
	class ASTExtraBaseCharacter*                       Character;                                                 
};

 
struct UBP_AutoNav_C_IsAutoSpint_Params
{
	bool                                               bAutoSprint;                                               
};

 
struct UBP_AutoNav_C_GetRotatorToDesc_Params
{
	struct FVector                                     ActorLocation;                                             
	struct FRotator                                    ReturnValue;                                               
};

 
struct UBP_AutoNav_C_ResetMinDistanceToDesc_Params
{
	struct FVector                                     ActorLocation;                                             
};

 
struct UBP_AutoNav_C_GetDescDistance_Params
{
	struct FVector                                     ActorLocation;                                             
	float                                              ReturnValue;                                               
};

 
struct UBP_AutoNav_C_IsLastPoint_Params
{
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoNav_C_GotoNextPoint_Params
{
};

 
struct UBP_AutoNav_C_IsArrivalDesc_Params
{
	struct FVector                                     ActorLocation;                                             
	bool                                               ReturnValue;                                               
};

 
struct UBP_AutoNav_C_GetDesc_Params
{
	struct FVector                                     Desc;                                                      
};

 
struct UBP_AutoNav_C_TickCloseToTarget_Params
{
	class ASTExtraPlayerController**                   PC;                                                        
	float*                                             DeltaTime;                                                 
};

 
struct UBP_AutoNav_C_OnStartAutoMove_Params
{
	class ASTExtraPlayerController**                   PC;                                                        
};

 
struct UBP_AutoNav_C_ReceiveBeginPlay_Params
{
};

 
struct UBP_AutoNav_C_CustomEvent_Params
{
	EPlayerAutoNavFindResult                           FindResult;                                                
};

 
struct UBP_AutoNav_C_StopMove_Params
{
};

 
struct UBP_AutoNav_C_OnRepPlayerState_Params
{
};

 
struct UBP_AutoNav_C_BPOnRequestMove_Params
{
	EPlayerAutoNavMode*                                CurMode;                                                   
	struct FString*                                    TargetParam;                                               
	struct FVector*                                    TargetLoc;                                                 
};

 
struct UBP_AutoNav_C_ExecuteUbergraph_BP_AutoNav_Params
{
	int                                                EntryPoint;                                                
};

}

