// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UFPPComponent_C_IsNeedChangeTexOpacity_Params
{
	bool                                               bNeedChange;                                               
};

 
struct UFPPComponent_C_GetMateriaByString_Params
{
	struct FString                                     Name;                                                      
	class UMaterialInterface*                          Material;                                                  
};

 
struct UFPPComponent_C_ScopingAttachToHead_Params
{
};

 
struct UFPPComponent_C_ScopingAttachToGun_Params
{
};

 
struct UFPPComponent_C_GetScopeMaterialOverride_Params
{
	class ASTExtraShootWeapon**                        Weapon;                                                    
	class UMaterialInstance*                           ReturnValue;                                               
};

 
struct UFPPComponent_C_ResetScreenPercentage_Params
{
};

 
struct UFPPComponent_C_DownScreenPercentage_Params
{
};

 
struct UFPPComponent_C_ChangeScopeTPPGlassMat_Params
{
	class UMeshComponent*                              ScopeMeshComp;                                             
	int                                                ScopeID;                                                   
};

 
struct UFPPComponent_C_GetScopeMatTableKey_Params
{
	class ASTExtraPlayerController*                    PlayerController;                                          
	class ASTExtraShootWeapon*                         Weapon;                                                    
	EWeaponAttachmentSocketType                        ScopeType;                                                 
	struct FString                                     Key;                                                       
};

 
struct UFPPComponent_C_IsScopeSpecialMatExist_Params
{
	class ASTExtraWeapon*                              Weapon;                                                    
	EWeaponAttachmentSocketType                        ScopeType;                                                 
	bool                                               exist;                                                     
	int                                                MatTableKey;                                               
};

 
struct UFPPComponent_C_SwitchAngledSightConfigMaterial_Params
{
	bool*                                              forceSwitch;                                               
	float                                              ReturnValue;                                               
};

 
struct UFPPComponent_C_ShowAngledSightTPPMaterial_Params
{
	bool*                                              forceADSState;                                             
	float                                              ReturnValue;                                               
};

 
struct UFPPComponent_C_SwitchSightConfigMaterial_Params
{
	float                                              ReturnValue;                                               
};

 
struct UFPPComponent_C_ShowReflectorSightTPPMaterial_Params
{
	bool*                                              forceADSState;                                             
	float                                              ReturnValue;                                               
};

 
struct UFPPComponent_C_GetScopeFov_Params
{
	class ASTExtraWeapon**                             Weapon;                                                    
	bool*                                              bIsAngled;                                                 
	float                                              ReturnValue;                                               
};

 
struct UFPPComponent_C_SetTagCullingBP_Params
{
	bool                                               IsUse;                                                     
};

 
struct UFPPComponent_C_requestResourceGuarantee_Params
{
	int                                                InOrOut;                                                   
	TEnumAsByte<ELoadMode>                             loadMode;                                                  
	TEnumAsByte<EApplyStatus>                          applyStatus;                                               
};

 
struct UFPPComponent_C_ReceiveTick_Params
{
	float*                                             DeltaSeconds;                                              
};

 
struct UFPPComponent_C_ReloadEvent_Params
{
};

 
struct UFPPComponent_C_SetTagCulling_Params
{
	bool*                                              IsUse;                                                     
};

 
struct UFPPComponent_C_PlayScopeInTimeline_Params
{
};

 
struct UFPPComponent_C_ScopeInEnd_Params
{
};

 
struct UFPPComponent_C_ScopeOutEnd_Params
{
};

 
struct UFPPComponent_C_StopScopeIn_Params
{
};

 
struct UFPPComponent_C_AttachToSight_Params
{
};

 
struct UFPPComponent_C_AttachTo_Params
{
	class USceneComponent*                             NewParam;                                                  
};

 
struct UFPPComponent_C_Detach_Params
{
	class USceneComponent*                             NewParam;                                                  
};

 
struct UFPPComponent_C_AutoReloadEvent_Params
{
	class ASTExtraShootWeapon*                         ShootWeapon;                                               
};

 
struct UFPPComponent_C_AttachToSightKeepTransform_Params
{
};

 
struct UFPPComponent_C_ExecuteUbergraph_FPPComponent_Params
{
	int                                                EntryPoint;                                                
};

}

