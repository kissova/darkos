// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_GameFunctionLibrary_C_GetModeMaxTeammateNum_Params
{
	class UObject*                                     __WorldContext;                                            
	int                                                Result;                                                    
};

 
struct UBP_GameFunctionLibrary_C_EditorGetGameModeID_Params
{
	class UObject*                                     WorldCont;                                                 
	class UObject*                                     __WorldContext;                                            
	struct FString                                     ModeID;                                                    
};

 
struct UBP_GameFunctionLibrary_C_IsInFloatRangeUpperBound_Params
{
	float                                              Value;                                                     
	struct FFloatRangeBound                            FloatRangeBound;                                           
	class UObject*                                     __WorldContext;                                            
	bool                                               ReturnValue;                                               
};

 
struct UBP_GameFunctionLibrary_C_IsInFloatRangeLowerBound_Params
{
	float                                              Value;                                                     
	struct FFloatRangeBound                            FloatRangeBound;                                           
	class UObject*                                     __WorldContext;                                            
	bool                                               ReturnValue;                                               
};

 
struct UBP_GameFunctionLibrary_C_IsInFloatRange_Params
{
	float                                              Value;                                                     
	struct FFloatRange                                 FloatRange;                                                
	class UObject*                                     __WorldContext;                                            
	bool                                               ReturnValue;                                               
};

 
struct UBP_GameFunctionLibrary_C_GetGuideTextStruct_Params
{
	int                                                NewParam;                                                  
	class UObject*                                     __WorldContext;                                            
	struct FBP_STRUCT_GuideText_type                   NewParam1;                                                 
};

 
struct UBP_GameFunctionLibrary_C_GetMinimapPathByModeID_Params
{
	class UObject*                                     WorldContext;                                              
	class UObject*                                     __WorldContext;                                            
	struct FString                                     MinimapPath;                                               
};

 
struct UBP_GameFunctionLibrary_C_GetCurLevelMinimapPath_Params
{
	class UObject*                                     WorldContext;                                              
	class UObject*                                     __WorldContext;                                            
	struct FString                                     MinimapPath;                                               
};

 
struct UBP_GameFunctionLibrary_C_ClampStringLength_Params
{
	struct FString                                     Source;                                                    
	int                                                Length;                                                    
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Result;                                                    
};

 
struct UBP_GameFunctionLibrary_C_IsPlayerCanSeeWidget_Params
{
	class UWidget*                                     NewParam;                                                  
	class UObject*                                     __WorldContext;                                            
	bool                                               cansee;                                                    
};

 
struct UBP_GameFunctionLibrary_C_GetCurLevelMapTexture_Params
{
	class UObject*                                     __WorldContext;                                            
	class UTexture2D*                                  Texture;                                                   
};

 
struct UBP_GameFunctionLibrary_C_GetActorsByTag_Params
{
	struct FName                                       Tag;                                                       
	class UObject*                                     ContextObject;                                             
	class UClass*                                      ActorClass;                                                
	class UObject*                                     __WorldContext;                                            
	TArray<class AActor*>                              Targets;                                                   
};

 
struct UBP_GameFunctionLibrary_C_AddActorTag_Params
{
	class AActor*                                      Target;                                                    
	struct FName                                       TagInfo;                                                   
	class UObject*                                     __WorldContext;                                            
};

 
struct UBP_GameFunctionLibrary_C_SetUpGamePostProcessEffectData_Params
{
	class APostProcessVolume*                          Volume;                                                    
	class UObject*                                     ContextObject;                                             
	class UObject*                                     __WorldContext;                                            
};

}

