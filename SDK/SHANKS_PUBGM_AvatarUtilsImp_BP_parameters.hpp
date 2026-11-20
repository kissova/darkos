// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UAvatarUtilsImp_BP_C_GetAdjustWeaponBPID_Lobby_Params
{
	int*                                               WeaponId;                                                  
	int                                                ReturnValue;                                               
};

 
struct UAvatarUtilsImp_BP_C_GetVehicleDefaultStyleID_Params
{
	int*                                               InVehicleSkinID;                                           
	TArray<int>                                        OutStyleIDList;                                            
	bool                                               ReturnValue;                                               
};

 
struct UAvatarUtilsImp_BP_C_GetVehicleBPPathBySkinID_Params
{
	int*                                               InVehicleSkinID;                                           
	struct FString                                     ReturnValue;                                               
};

 
struct UAvatarUtilsImp_BP_C_GetVehicleShapeBySkinID_Params
{
	int*                                               InVehicleSkinID;                                           
	int                                                ReturnValue;                                               
};

 
struct UAvatarUtilsImp_BP_C_GetBPTableName_Params
{
	int                                                Type;                                                      
	int                                                TypeSpecificID;                                            
	struct FString                                     BPTableName;                                               
	int                                                SpecificID;                                                
};

 
struct UAvatarUtilsImp_BP_C_CreateAvatarHandle_Params
{
	struct FItemDefineID*                              DefineID;                                                  
	class UObject**                                    Outer;                                                     
	bool*                                              bLobby;                                                    
	class UItemHandleBase*                             ReturnValue;                                               
};

 
struct UAvatarUtilsImp_BP_C_GetAvatarHandlePath_Params
{
	struct FItemDefineID*                              DefineID;                                                  
	bool*                                              bLobby;                                                    
	struct FString                                     ReturnValue;                                               
};

}

