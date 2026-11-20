// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UFPPComponent_C::IsNeedChangeTexOpacity(bool* bNeedChange)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.IsNeedChangeTexOpacity");

	UFPPComponent_C_IsNeedChangeTexOpacity_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (bNeedChange != nullptr)
		*bNeedChange = params.bNeedChange;
}


 
 
 
 
 

void UFPPComponent_C::GetMateriaByString(const struct FString& Name, class UMaterialInterface** Material)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.GetMateriaByString");

	UFPPComponent_C_GetMateriaByString_Params params;
	params.Name = Name;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Material != nullptr)
		*Material = params.Material;
}


 
 

void UFPPComponent_C::ScopingAttachToHead()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ScopingAttachToHead");

	UFPPComponent_C_ScopingAttachToHead_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::ScopingAttachToGun()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ScopingAttachToGun");

	UFPPComponent_C_ScopingAttachToGun_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

class UMaterialInstance* UFPPComponent_C::GetScopeMaterialOverride(class ASTExtraShootWeapon** Weapon)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.GetScopeMaterialOverride");

	UFPPComponent_C_GetScopeMaterialOverride_Params params;
	params.Weapon = Weapon;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UFPPComponent_C::ResetScreenPercentage()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ResetScreenPercentage");

	UFPPComponent_C_ResetScreenPercentage_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::DownScreenPercentage()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.DownScreenPercentage");

	UFPPComponent_C_DownScreenPercentage_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UFPPComponent_C::ChangeScopeTPPGlassMat(class UMeshComponent* ScopeMeshComp, int ScopeID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ChangeScopeTPPGlassMat");

	UFPPComponent_C_ChangeScopeTPPGlassMat_Params params;
	params.ScopeMeshComp = ScopeMeshComp;
	params.ScopeID = ScopeID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void UFPPComponent_C::GetScopeMatTableKey(class ASTExtraPlayerController* PlayerController, class ASTExtraShootWeapon* Weapon, EWeaponAttachmentSocketType ScopeType, struct FString* Key)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.GetScopeMatTableKey");

	UFPPComponent_C_GetScopeMatTableKey_Params params;
	params.PlayerController = PlayerController;
	params.Weapon = Weapon;
	params.ScopeType = ScopeType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Key != nullptr)
		*Key = params.Key;
}


 
 
 
 
 
 
 

void UFPPComponent_C::IsScopeSpecialMatExist(class ASTExtraWeapon* Weapon, EWeaponAttachmentSocketType ScopeType, bool* exist, int* MatTableKey)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.IsScopeSpecialMatExist");

	UFPPComponent_C_IsScopeSpecialMatExist_Params params;
	params.Weapon = Weapon;
	params.ScopeType = ScopeType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (exist != nullptr)
		*exist = params.exist;
	if (MatTableKey != nullptr)
		*MatTableKey = params.MatTableKey;
}


 
 
 
 
 

float UFPPComponent_C::SwitchAngledSightConfigMaterial(bool* forceSwitch)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.SwitchAngledSightConfigMaterial");

	UFPPComponent_C_SwitchAngledSightConfigMaterial_Params params;
	params.forceSwitch = forceSwitch;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

float UFPPComponent_C::ShowAngledSightTPPMaterial(bool* forceADSState)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ShowAngledSightTPPMaterial");

	UFPPComponent_C_ShowAngledSightTPPMaterial_Params params;
	params.forceADSState = forceADSState;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

float UFPPComponent_C::SwitchSightConfigMaterial()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.SwitchSightConfigMaterial");

	UFPPComponent_C_SwitchSightConfigMaterial_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

float UFPPComponent_C::ShowReflectorSightTPPMaterial(bool* forceADSState)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ShowReflectorSightTPPMaterial");

	UFPPComponent_C_ShowReflectorSightTPPMaterial_Params params;
	params.forceADSState = forceADSState;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

float UFPPComponent_C::GetScopeFov(class ASTExtraWeapon** Weapon, bool* bIsAngled)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.GetScopeFov");

	UFPPComponent_C_GetScopeFov_Params params;
	params.Weapon = Weapon;
	params.bIsAngled = bIsAngled;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UFPPComponent_C::SetTagCullingBP(bool IsUse)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.SetTagCullingBP");

	UFPPComponent_C_SetTagCullingBP_Params params;
	params.IsUse = IsUse;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UFPPComponent_C::requestResourceGuarantee(int InOrOut, TEnumAsByte<ELoadMode> loadMode, TEnumAsByte<EApplyStatus> applyStatus)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.requestResourceGuarantee");

	UFPPComponent_C_requestResourceGuarantee_Params params;
	params.InOrOut = InOrOut;
	params.loadMode = loadMode;
	params.applyStatus = applyStatus;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UFPPComponent_C::ReceiveTick(float* DeltaSeconds)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ReceiveTick");

	UFPPComponent_C_ReceiveTick_Params params;
	params.DeltaSeconds = DeltaSeconds;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::ReloadEvent()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ReloadEvent");

	UFPPComponent_C_ReloadEvent_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UFPPComponent_C::SetTagCulling(bool* IsUse)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.SetTagCulling");

	UFPPComponent_C_SetTagCulling_Params params;
	params.IsUse = IsUse;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::PlayScopeInTimeline()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.PlayScopeInTimeline");

	UFPPComponent_C_PlayScopeInTimeline_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::ScopeInEnd()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ScopeInEnd");

	UFPPComponent_C_ScopeInEnd_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::ScopeOutEnd()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ScopeOutEnd");

	UFPPComponent_C_ScopeOutEnd_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::StopScopeIn()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.StopScopeIn");

	UFPPComponent_C_StopScopeIn_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::AttachToSight()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.AttachToSight");

	UFPPComponent_C_AttachToSight_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UFPPComponent_C::AttachTo(class USceneComponent* NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.AttachTo");

	UFPPComponent_C_AttachTo_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UFPPComponent_C::Detach(class USceneComponent* NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.Detach");

	UFPPComponent_C_Detach_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UFPPComponent_C::AutoReloadEvent(class ASTExtraShootWeapon* ShootWeapon)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.AutoReloadEvent");

	UFPPComponent_C_AutoReloadEvent_Params params;
	params.ShootWeapon = ShootWeapon;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UFPPComponent_C::AttachToSightKeepTransform()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.AttachToSightKeepTransform");

	UFPPComponent_C_AttachToSightKeepTransform_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UFPPComponent_C::ExecuteUbergraph_FPPComponent(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function FPPComponent.FPPComponent_C.ExecuteUbergraph_FPPComponent");

	UFPPComponent_C_ExecuteUbergraph_FPPComponent_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

