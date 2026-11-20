// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct AWaterSwimObject_C_SetWaterMaterialByGamePawnEvent_Params
{
	TEnumAsByte<EGamePawnEvent>                        Event;                                                     
};

 
struct AWaterSwimObject_C_SetWaterMaterial_Params
{
	int                                                NewParam;                                                  
};

 
struct AWaterSwimObject_C_RefreshWaterMaterial_Params
{
};

 
struct AWaterSwimObject_C_DoTrySetWaterMaterial_Params
{
	int                                                NewParam;                                                  
};

 
struct AWaterSwimObject_C_TrySetWaterMaterial_Params
{
	int                                                NewParam;                                                  
};

 
struct AWaterSwimObject_C_IsSupportIndex_Params
{
	int                                                NewParam;                                                  
	bool                                               NewParam1;                                                 
};

 
struct AWaterSwimObject_C_IsNewIphone_Params
{
	bool                                               IsNewIphone;                                               
};

 
struct AWaterSwimObject_C_SetWateMaterial_Params
{
	bool                                               bHDR;                                                      
};

 
struct AWaterSwimObject_C_HideUnderWaterEffect_Params
{
	class UStaticMeshComponent*                        WaterPlane;                                                
	class UExponentialHeightFogComponent*              CamFog;                                                    
};

 
struct AWaterSwimObject_C_ShowUnderWaterEffect_Params
{
	class UStaticMeshComponent*                        WaterPlane;                                                
	class UExponentialHeightFogComponent*              CamFog;                                                    
};

 
struct AWaterSwimObject_C_IsCapsult_Params
{
	class UObject*                                     PlayerPawn;                                                
	class UActorComponent*                             comp;                                                      
	bool                                               ReturnValue;                                               
};

 
struct AWaterSwimObject_C_UserConstructionScript_Params
{
};

 
struct AWaterSwimObject_C_BndEvt__PostSceneBox_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                       
	class AActor*                                      OtherActor;                                                
	class UPrimitiveComponent*                         OtherComp;                                                 
	int                                                OtherBodyIndex;                                            
	bool                                               bFromSweep;                                                
	struct FHitResult                                  SweepResult;                                               
};

 
struct AWaterSwimObject_C_BndEvt__PostSceneBox_K2Node_ComponentBoundEvent_0_ComponentEndOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                       
	class AActor*                                      OtherActor;                                                
	class UPrimitiveComponent*                         OtherComp;                                                 
	int                                                OtherBodyIndex;                                            
};

 
struct AWaterSwimObject_C_ReceiveBeginPlay_Params
{
};

 
struct AWaterSwimObject_C_CustomEvent_2_Params
{
	int                                                UserQualitySettingLevel;                                   
};

 
struct AWaterSwimObject_C_ReceiveEndPlay_Params
{
	TEnumAsByte<EEndPlayReason>*                       EndPlayReason;                                             
};

 
struct AWaterSwimObject_C_CustomEvent_3_Params
{
	bool                                               UserMsaaSetting;                                           
};

 
struct AWaterSwimObject_C_CustomEvent_4_Params
{
	bool                                               bOpenWaterReflection;                                      
};

 
struct AWaterSwimObject_C_ExecuteUbergraph_WaterSwimObject_Params
{
	int                                                EntryPoint;                                                
};

}

