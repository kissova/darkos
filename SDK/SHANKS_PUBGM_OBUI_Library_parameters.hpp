// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UOBUI_Library_C_GetSyncOBDataActor_Params
{
	class UObject*                                     __WorldContext;                                            
	class ASyncOBDataActor*                            SyncOBDataActor;                                           
};

 
struct UOBUI_Library_C_GetPlayerNameLinearColorByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	struct FLinearColor                                NewParam1;                                                 
};

 
struct UOBUI_Library_C_GetPlayerLinearColorByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	struct FLinearColor                                NewParam;                                                  
};

 
struct UOBUI_Library_C_GetPlayerMakeupPicbyUID_Params
{
	struct FString                                     UID;                                                       
	class UObject*                                     __WorldContext;                                            
	bool                                               bFind;                                                     
	struct FString                                     logoPath;                                                  
	class UTexture2D*                                  LogoObject;                                                
};

 
struct UOBUI_Library_C_IsAllStarGame_Params
{
	class UObject*                                     WorldContextObj;                                           
	class UObject*                                     __WorldContext;                                            
	bool                                               bRes;                                                      
};

 
struct UOBUI_Library_C_GetCustomTeammatePicByName_Params
{
	TArray<struct FString>                             Resolution;                                                
	struct FString                                     PlayerName;                                                
	class UObject*                                     __WorldContext;                                            
	bool                                               bFind;                                                     
	struct FString                                     logoPath;                                                  
	class UTexture2D*                                  LogoObject;                                                
};

 
struct UOBUI_Library_C_GetCustomCornerMarkByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	bool                                               bFind;                                                     
	struct FString                                     CornerMark;                                                
};

 
struct UOBUI_Library_C_GetCustomKillInfoByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	bool                                               bFind;                                                     
	struct FString                                     logoPath;                                                  
	class UTexture2D*                                  LogoObject;                                                
};

 
struct UOBUI_Library_C_GetCustomTeamNameByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	bool                                               bFind;                                                     
	struct FString                                     TeamName;                                                  
};

 
struct UOBUI_Library_C_IsTeamMatch_Params
{
	class UObject*                                     __WorldContext;                                            
	bool                                               bRet;                                                      
};

 
struct UOBUI_Library_C_GetCustomTeamLogoByTeamID_Params
{
	int                                                TeamID;                                                    
	TArray<struct FString>                             Resolution;                                                
	class UObject*                                     __WorldContext;                                            
	bool                                               bFind;                                                     
	struct FString                                     logoPath;                                                  
	class UTexture2D*                                  LogoObject;                                                
};

 
struct UOBUI_Library_C_GetPlayerNameColorByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	struct FColor                                      PlayerNameColor;                                           
};

 
struct UOBUI_Library_C_GetPlayerColorByTeamID_Params
{
	int                                                TeamID;                                                    
	class UObject*                                     __WorldContext;                                            
	struct FColor                                      PlayerColor;                                               
};

}

