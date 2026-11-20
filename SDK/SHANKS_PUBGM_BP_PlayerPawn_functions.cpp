// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void ABP_PlayerPawn_C::ShowScreenDamage(float Damage, TEnumAsByte<EDamageType> DamageEventType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ShowScreenDamage");

	ABP_PlayerPawn_C_ShowScreenDamage_Params params;
	params.Damage = Damage;
	params.DamageEventType = DamageEventType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::GetBattleItemHandlePath(int ItemId, struct FString* EmotePath)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetBattleItemHandlePath");

	ABP_PlayerPawn_C_GetBattleItemHandlePath_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (EmotePath != nullptr)
		*EmotePath = params.EmotePath;
}


 
 

void ABP_PlayerPawn_C::RefreshWeaponSight()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.RefreshWeaponSight");

	ABP_PlayerPawn_C_RefreshWeaponSight_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::HandleOnLandedSetAutoSprint()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.HandleOnLandedSetAutoSprint");

	ABP_PlayerPawn_C_HandleOnLandedSetAutoSprint_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::ChangeParticleEffect(class UParticleSystemComponent* Particle, const struct FVector& _3DScale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ChangeParticleEffect");

	ABP_PlayerPawn_C_ChangeParticleEffect_Params params;
	params.Particle = Particle;
	params._3DScale = _3DScale;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void ABP_PlayerPawn_C::SpawnEmitterEffect(const struct FVector& RelativeLocation, class UParticleSystem* PSRef, class USceneComponent* AttachParent, const struct FVector& RelativeScale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SpawnEmitterEffect");

	ABP_PlayerPawn_C_SpawnEmitterEffect_Params params;
	params.RelativeLocation = RelativeLocation;
	params.PSRef = PSRef;
	params.AttachParent = AttachParent;
	params.RelativeScale = RelativeScale;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

struct FString ABP_PlayerPawn_C::GetEmoteHandlePath(int* ItemId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetEmoteHandlePath");

	ABP_PlayerPawn_C_GetEmoteHandlePath_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void ABP_PlayerPawn_C::Replay_IsEnemyFrameUIExisted(bool* bIsExisted)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.Replay_IsEnemyFrameUIExisted");

	ABP_PlayerPawn_C_Replay_IsEnemyFrameUIExisted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (bIsExisted != nullptr)
		*bIsExisted = params.bIsExisted;
}


 
 
 
 

void ABP_PlayerPawn_C::HandleOnLanded(float ForceLandTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.HandleOnLanded");

	ABP_PlayerPawn_C_HandleOnLanded_Params params;
	params.ForceLandTime = ForceLandTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::GetGameModeState(struct FName* CurModeState)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetGameModeState");

	ABP_PlayerPawn_C_GetGameModeState_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (CurModeState != nullptr)
		*CurModeState = params.CurModeState;
}


 
 
 
 

void ABP_PlayerPawn_C::SetTpCameraFov(float FOV)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SetTpCameraFov");

	ABP_PlayerPawn_C_SetTpCameraFov_Params params;
	params.FOV = FOV;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::SetCapsuleParentBounds(bool UseParentBounds)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SetCapsuleParentBounds");

	ABP_PlayerPawn_C_SetCapsuleParentBounds_Params params;
	params.UseParentBounds = UseParentBounds;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ClearDecalBakingRTCache()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ClearDecalBakingRTCache");

	ABP_PlayerPawn_C_ClearDecalBakingRTCache_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

bool ABP_PlayerPawn_C::IsAngledSightAvailable()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.IsAngledSightAvailable");

	ABP_PlayerPawn_C_IsAngledSightAvailable_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

void ABP_PlayerPawn_C::RefreshAngledSightUI(bool HaveAngledSight, bool IsAngledSight)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.RefreshAngledSightUI");

	ABP_PlayerPawn_C_RefreshAngledSightUI_Params params;
	params.HaveAngledSight = HaveAngledSight;
	params.IsAngledSight = IsAngledSight;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::ShowAngledSightState(bool IsAngled)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ShowAngledSightState");

	ABP_PlayerPawn_C_ShowAngledSightState_Params params;
	params.IsAngled = IsAngled;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::GetAngledSightRotator(class ASTExtraShootWeapon* NewParam, struct FRotator* NewParam1)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetAngledSightRotator");

	ABP_PlayerPawn_C_GetAngledSightRotator_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (NewParam1 != nullptr)
		*NewParam1 = params.NewParam1;
}


 
 
 
 

void ABP_PlayerPawn_C::AngledSightAnimLogic(TEnumAsByte<EAngledSightType> Selection)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.AngledSightAnimLogic");

	ABP_PlayerPawn_C_AngledSightAnimLogic_Params params;
	params.Selection = Selection;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::AngledSightAnimUpdate(float InputPin, bool bIsOnlyTurn)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.AngledSightAnimUpdate");

	ABP_PlayerPawn_C_AngledSightAnimUpdate_Params params;
	params.InputPin = InputPin;
	params.bIsOnlyTurn = bIsOnlyTurn;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::Replay_CreateEnemyFrameUI(bool isPlayingCompletePlayback, bool is_enemy)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.Replay_CreateEnemyFrameUI");

	ABP_PlayerPawn_C_Replay_CreateEnemyFrameUI_Params params;
	params.isPlayingCompletePlayback = isPlayingCompletePlayback;
	params.is_enemy = is_enemy;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::Replay_SetVisiableOfFrameUI(bool is_Visiable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.Replay_SetVisiableOfFrameUI");

	ABP_PlayerPawn_C_Replay_SetVisiableOfFrameUI_Params params;
	params.is_Visiable = is_Visiable;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::UpdateEmoteWeaponIdInfo(int ID, bool* Ret)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.UpdateEmoteWeaponIdInfo");

	ABP_PlayerPawn_C_UpdateEmoteWeaponIdInfo_Params params;
	params.ID = ID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Ret != nullptr)
		*Ret = params.Ret;
}


 
 
 
 

void ABP_PlayerPawn_C::AllowWater(bool* bCanEnter)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.AllowWater");

	ABP_PlayerPawn_C_AllowWater_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (bCanEnter != nullptr)
		*bCanEnter = params.bCanEnter;
}


 
 
 
 

bool ABP_PlayerPawn_C::ShouldRedBlood()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ShouldRedBlood");

	ABP_PlayerPawn_C_ShouldRedBlood_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

void ABP_PlayerPawn_C::CheckHasVehicleAvatar(class ASTExtraVehicleBase* InVehicle, class ASTExtraBaseCharacter* PlayerCharacter, int* InItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.CheckHasVehicleAvatar");

	ABP_PlayerPawn_C_CheckHasVehicleAvatar_Params params;
	params.InVehicle = InVehicle;
	params.PlayerCharacter = PlayerCharacter;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (InItemID != nullptr)
		*InItemID = params.InItemID;
}


 
 
 
 

void ABP_PlayerPawn_C::ChangeCurVehicleAvatar(class ASTExtraVehicleBase* InVehicle)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ChangeCurVehicleAvatar");

	ABP_PlayerPawn_C_ChangeCurVehicleAvatar_Params params;
	params.InVehicle = InVehicle;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::HandleOnChangedVehicleSeat()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.HandleOnChangedVehicleSeat");

	ABP_PlayerPawn_C_HandleOnChangedVehicleSeat_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::GetMasterBoneComponent(class UMeshComponent** MasterBoneComponent)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetMasterBoneComponent");

	ABP_PlayerPawn_C_GetMasterBoneComponent_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (MasterBoneComponent != nullptr)
		*MasterBoneComponent = params.MasterBoneComponent;
}


 
 
 
 
 
 

void ABP_PlayerPawn_C::InitDefaultAvatarByResID(int AGender, int Head, int hair)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.InitDefaultAvatarByResID");

	ABP_PlayerPawn_C_InitDefaultAvatarByResID_Params params;
	params.AGender = AGender;
	params.Head = Head;
	params.hair = hair;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::GetGrenadeCameraShakeByDir(const struct FVector& ImpulseDir, class UClass** RetVar)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetGrenadeCameraShakeByDir");

	ABP_PlayerPawn_C_GetGrenadeCameraShakeByDir_Params params;
	params.ImpulseDir = ImpulseDir;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (RetVar != nullptr)
		*RetVar = params.RetVar;
}


 
 
 
 
 

class UBackpackEmoteHandle* ABP_PlayerPawn_C::GetEmoteHandle(int* ItemId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetEmoteHandle");

	ABP_PlayerPawn_C_GetEmoteHandle_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FString ABP_PlayerPawn_C::GetShootWeaponNameByWeapon(int* ItemDefineID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetShootWeaponNameByWeapon");

	ABP_PlayerPawn_C_GetShootWeaponNameByWeapon_Params params;
	params.ItemDefineID = ItemDefineID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UCameraComponent* ABP_PlayerPawn_C::GetThirdPersonCamera()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetThirdPersonCamera");

	ABP_PlayerPawn_C_GetThirdPersonCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class USpringArmComponent* ABP_PlayerPawn_C::GetThirdPersonSpringArm()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetThirdPersonSpringArm");

	ABP_PlayerPawn_C_GetThirdPersonSpringArm_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UCameraComponent* ABP_PlayerPawn_C::GetFPPCamera()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetFPPCamera");

	ABP_PlayerPawn_C_GetFPPCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class USpringArmComponent* ABP_PlayerPawn_C::GetFPPSpringArm()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetFPPSpringArm");

	ABP_PlayerPawn_C_GetFPPSpringArm_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UCameraComponent* ABP_PlayerPawn_C::GetFirstPersonCamera()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetFirstPersonCamera");

	ABP_PlayerPawn_C_GetFirstPersonCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class USpringArmComponent* ABP_PlayerPawn_C::GetFirstPersonSpringArm()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetFirstPersonSpringArm");

	ABP_PlayerPawn_C_GetFirstPersonSpringArm_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UCameraComponent* ABP_PlayerPawn_C::GetScopeCamera()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetScopeCamera");

	ABP_PlayerPawn_C_GetScopeCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class USpringArmComponent* ABP_PlayerPawn_C::GetScopeSpringArm()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetScopeSpringArm");

	ABP_PlayerPawn_C_GetScopeSpringArm_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

bool ABP_PlayerPawn_C::ShouldAutoScopeWhenPeek()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ShouldAutoScopeWhenPeek");

	ABP_PlayerPawn_C_ShouldAutoScopeWhenPeek_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void ABP_PlayerPawn_C::GetControllerViewCamera(class UCameraComponent** Camera)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetControllerViewCamera");

	ABP_PlayerPawn_C_GetControllerViewCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Camera != nullptr)
		*Camera = params.Camera;
}


 
 
 
 

void ABP_PlayerPawn_C::HandleOnDetachedVehicle(class ASTExtraVehicleBase* NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.HandleOnDetachedVehicle");

	ABP_PlayerPawn_C_HandleOnDetachedVehicle_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::HandleOnAttachedVehicle(class ASTExtraVehicleBase* InVehicle)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.HandleOnAttachedVehicle");

	ABP_PlayerPawn_C_HandleOnAttachedVehicle_Params params;
	params.InVehicle = InVehicle;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

class USpringArmComponent* ABP_PlayerPawn_C::GetActiveSpringArm()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetActiveSpringArm");

	ABP_PlayerPawn_C_GetActiveSpringArm_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void ABP_PlayerPawn_C::AimInterupted()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.AimInterupted");

	ABP_PlayerPawn_C_AimInterupted_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void ABP_PlayerPawn_C::GetWeapon(struct FVector* NewParam, struct FRotator* NewParam1, bool* bHaveWeapon)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.GetWeapon");

	ABP_PlayerPawn_C_GetWeapon_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (NewParam != nullptr)
		*NewParam = params.NewParam;
	if (NewParam1 != nullptr)
		*NewParam1 = params.NewParam1;
	if (bHaveWeapon != nullptr)
		*bHaveWeapon = params.bHaveWeapon;
}


 
 

void ABP_PlayerPawn_C::ResetBPCameraSetting()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ResetBPCameraSetting");

	ABP_PlayerPawn_C_ResetBPCameraSetting_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void ABP_PlayerPawn_C::ShowDebugArrow(class USceneComponent* self2, const struct FRotator& InRot, const struct FLinearColor& Color)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ShowDebugArrow");

	ABP_PlayerPawn_C_ShowDebugArrow_Params params;
	params.self2 = self2;
	params.InRot = InRot;
	params.Color = Color;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::IsAutonomous(bool* NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.IsAutonomous");

	ABP_PlayerPawn_C_IsAutonomous_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (NewParam != nullptr)
		*NewParam = params.NewParam;
}


 
 
 
 

void ABP_PlayerPawn_C::PickUp(class APickUpWrapperActor* NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.PickUp");

	ABP_PlayerPawn_C_PickUp_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::DoPickUpTarget()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.DoPickUpTarget");

	ABP_PlayerPawn_C_DoPickUpTarget_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::RotateMesh(const struct FRotator& NewParam)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.RotateMesh");

	ABP_PlayerPawn_C_RotateMesh_Params params;
	params.NewParam = NewParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::SetAllCollisionEnabled(bool bEnable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SetAllCollisionEnabled");

	ABP_PlayerPawn_C_SetAllCollisionEnabled_Params params;
	params.bEnable = bEnable;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::MoveOutScope()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.MoveOutScope");

	ABP_PlayerPawn_C_MoveOutScope_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::MoveInScope()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.MoveInScope");

	ABP_PlayerPawn_C_MoveInScope_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::Reload()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.Reload");

	ABP_PlayerPawn_C_Reload_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::SwitchCrouch(TEnumAsByte<ESTEPoseState> NewParam, TEnumAsByte<ESTEPoseState> preState)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SwitchCrouch");

	ABP_PlayerPawn_C_SwitchCrouch_Params params;
	params.NewParam = NewParam;
	params.preState = preState;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::UserConstructionScript()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.UserConstructionScript");

	ABP_PlayerPawn_C_UserConstructionScript_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ScopeTimeline__FinishedFunc()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ScopeTimeline__FinishedFunc");

	ABP_PlayerPawn_C_ScopeTimeline__FinishedFunc_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ScopeTimeline__UpdateFunc()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ScopeTimeline__UpdateFunc");

	ABP_PlayerPawn_C_ScopeTimeline__UpdateFunc_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnPetOwnerPossessed()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnPetOwnerPossessed");

	ABP_PlayerPawn_C_OnPetOwnerPossessed_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ReceiveBeginPlay");

	ABP_PlayerPawn_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 

void ABP_PlayerPawn_C::BPNotifyStartDying(class AController** Killer, class AActor** DamageCauser, struct FHitResult* KillingHitInfo, struct FVector* KillingHitImpulseDir, class UClass** KillingHitDamageType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.BPNotifyStartDying");

	ABP_PlayerPawn_C_BPNotifyStartDying_Params params;
	params.Killer = Killer;
	params.DamageCauser = DamageCauser;
	params.KillingHitInfo = KillingHitInfo;
	params.KillingHitImpulseDir = KillingHitImpulseDir;
	params.KillingHitDamageType = KillingHitDamageType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ReloadEvent()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ReloadEvent");

	ABP_PlayerPawn_C_ReloadEvent_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::OnEquipWeapon(TEnumAsByte<ESurviveWeaponPropSlot>* Slot)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnEquipWeapon");

	ABP_PlayerPawn_C_OnEquipWeapon_Params params;
	params.Slot = Slot;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnNotifyHurt()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnNotifyHurt");

	ABP_PlayerPawn_C_OnNotifyHurt_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::OnLanded(struct FHitResult* Hit)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnLanded");

	ABP_PlayerPawn_C_OnLanded_Params params;
	params.Hit = Hit;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::OnPoseStateChange(TEnumAsByte<ESTEPoseState>* LastState, TEnumAsByte<ESTEPoseState>* CurState)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnPoseStateChange");

	ABP_PlayerPawn_C_OnPoseStateChange_Params params;
	params.LastState = LastState;
	params.CurState = CurState;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 

void ABP_PlayerPawn_C::BPReceiveDamage(float* Damage, class UDamageType** DamageType, class AController** InstigatedBy, class AActor** DamageCauser, TEnumAsByte<EDamageType>* DamageEventType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.BPReceiveDamage");

	ABP_PlayerPawn_C_BPReceiveDamage_Params params;
	params.Damage = Damage;
	params.DamageType = DamageType;
	params.InstigatedBy = InstigatedBy;
	params.DamageCauser = DamageCauser;
	params.DamageEventType = DamageEventType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ParachuteOnWater()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ParachuteOnWater");

	ABP_PlayerPawn_C_ParachuteOnWater_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnUnEquipWeapon()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnUnEquipWeapon");

	ABP_PlayerPawn_C_OnUnEquipWeapon_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 
 
 
 
 
 
 

void ABP_PlayerPawn_C::PawnVaultServerBluePrint(float* dis, float* Height, float* Length, struct FString* VaultKey, struct FVector* StartPos, class AActor** checkActor, float* crossblockMaxFall, float* crossblockMaxDis, struct FVector* HitPoint, class AActor** WindowActor, struct FRotator* MoveDir)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.PawnVaultServerBluePrint");

	ABP_PlayerPawn_C_PawnVaultServerBluePrint_Params params;
	params.dis = dis;
	params.Height = Height;
	params.Length = Length;
	params.VaultKey = VaultKey;
	params.StartPos = StartPos;
	params.checkActor = checkActor;
	params.crossblockMaxFall = crossblockMaxFall;
	params.crossblockMaxDis = crossblockMaxDis;
	params.HitPoint = HitPoint;
	params.WindowActor = WindowActor;
	params.MoveDir = MoveDir;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 
 
 
 
 
 

void ABP_PlayerPawn_C::PawnVaultAllBluePrint(float* dis, float* Height, float* Length, struct FString* VaultKey, struct FVector* StartPos, class AActor** checkActor, float* crossblockMaxFall, float* crossblockMaxDis, struct FVector* HitPoint, struct FRotator* MoveDir)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.PawnVaultAllBluePrint");

	ABP_PlayerPawn_C_PawnVaultAllBluePrint_Params params;
	params.dis = dis;
	params.Height = Height;
	params.Length = Length;
	params.VaultKey = VaultKey;
	params.StartPos = StartPos;
	params.checkActor = checkActor;
	params.crossblockMaxFall = crossblockMaxFall;
	params.crossblockMaxDis = crossblockMaxDis;
	params.HitPoint = HitPoint;
	params.MoveDir = MoveDir;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ScopeInStop()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ScopeInStop");

	ABP_PlayerPawn_C_ScopeInStop_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::PlayScopeInTimeline(float Rate)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.PlayScopeInTimeline");

	ABP_PlayerPawn_C_PlayScopeInTimeline_Params params;
	params.Rate = Rate;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 
 
 
 
 

void ABP_PlayerPawn_C::BPReceiveRadialDamage(float* DamageReceived, class UDamageType** DamageType, struct FVector* Origin, float* Radius, struct FHitResult* HitInfo, class AController** InstigatedBy, class AActor** DamageCauser, struct FVector* ImpulseDir, float* CamerShakeScale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.BPReceiveRadialDamage");

	ABP_PlayerPawn_C_BPReceiveRadialDamage_Params params;
	params.DamageReceived = DamageReceived;
	params.DamageType = DamageType;
	params.Origin = Origin;
	params.Radius = Radius;
	params.HitInfo = HitInfo;
	params.InstigatedBy = InstigatedBy;
	params.DamageCauser = DamageCauser;
	params.ImpulseDir = ImpulseDir;
	params.CamerShakeScale = CamerShakeScale;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::ReceivePossessed(class AController** NewController)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ReceivePossessed");

	ABP_PlayerPawn_C_ReceivePossessed_Params params;
	params.NewController = NewController;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::ParachutePlaySound(class UAkAudioEvent** LocalAkEvent, class UAkAudioEvent** RemoteAkEvent)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ParachutePlaySound");

	ABP_PlayerPawn_C_ParachutePlaySound_Params params;
	params.LocalAkEvent = LocalAkEvent;
	params.RemoteAkEvent = RemoteAkEvent;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnWeaponEquipmentUpdate()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnWeaponEquipmentUpdate");

	ABP_PlayerPawn_C_OnWeaponEquipmentUpdate_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::BindAndExecStateChanged()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.BindAndExecStateChanged");

	ABP_PlayerPawn_C_BindAndExecStateChanged_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::StateEnterHandler_Event_1(EPawnState State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.StateEnterHandler_Event_1");

	ABP_PlayerPawn_C_StateEnterHandler_Event_1_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnHitByCake()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnHitByCake");

	ABP_PlayerPawn_C_OnHitByCake_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::EnablePet(bool* Enable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.EnablePet");

	ABP_PlayerPawn_C_EnablePet_Params params;
	params.Enable = Enable;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::OnEnterStateForBp(EPawnState* State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnEnterStateForBp");

	ABP_PlayerPawn_C_OnEnterStateForBp_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::OnLeaveStateForBp(EPawnState* State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnLeaveStateForBp");

	ABP_PlayerPawn_C_OnLeaveStateForBp_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::ReceiveDestroyed()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ReceiveDestroyed");

	ABP_PlayerPawn_C_ReceiveDestroyed_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::PawnVaultServerStopCheckBluePrint()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.PawnVaultServerStopCheckBluePrint");

	ABP_PlayerPawn_C_PawnVaultServerStopCheckBluePrint_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::PawnVaultStopBluePrint()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.PawnVaultStopBluePrint");

	ABP_PlayerPawn_C_PawnVaultStopBluePrint_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ABP_PlayerPawn_C::SwitchSightAngledLocal(TEnumAsByte<EAngledSightType>* Type, bool* IsOnlyTurn)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SwitchSightAngledLocal");

	ABP_PlayerPawn_C_SwitchSightAngledLocal_Params params;
	params.Type = Type;
	params.IsOnlyTurn = IsOnlyTurn;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::DoAngledSight(bool IsPush)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.DoAngledSight");

	ABP_PlayerPawn_C_DoAngledSight_Params params;
	params.IsPush = IsPush;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::DoNormalSight(bool IsPush)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.DoNormalSight");

	ABP_PlayerPawn_C_DoNormalSight_Params params;
	params.IsPush = IsPush;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::StopSwitchAngledSight()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.StopSwitchAngledSight");

	ABP_PlayerPawn_C_StopSwitchAngledSight_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void ABP_PlayerPawn_C::CustomEvent_4(class ASTExtraShootWeapon* Weapon, EWeaponAttachmentSocketType Type, bool bEquip)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.CustomEvent_4");

	ABP_PlayerPawn_C_CustomEvent_4_Params params;
	params.Weapon = Weapon;
	params.Type = Type;
	params.bEquip = bEquip;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::CustomEvent_1(bool bIsBegin)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.CustomEvent_1");

	ABP_PlayerPawn_C_CustomEvent_1_Params params;
	params.bIsBegin = bIsBegin;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnVehicleStateChange()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnVehicleStateChange");

	ABP_PlayerPawn_C_OnVehicleStateChange_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::OnBPStateCheckIn()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnBPStateCheckIn");

	ABP_PlayerPawn_C_OnBPStateCheckIn_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::LuaReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.LuaReceiveBeginPlay");

	ABP_PlayerPawn_C_LuaReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void ABP_PlayerPawn_C::SwitchRearSight(int PrevIndex, int NewIndex, const struct FRotator& AngleRotator)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SwitchRearSight");

	ABP_PlayerPawn_C_SwitchRearSight_Params params;
	params.PrevIndex = PrevIndex;
	params.NewIndex = NewIndex;
	params.AngleRotator = AngleRotator;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::BPOnRespawned()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.BPOnRespawned");

	ABP_PlayerPawn_C_BPOnRespawned_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::RemoveRemainingCameraBlood(int SeatType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.RemoveRemainingCameraBlood");

	ABP_PlayerPawn_C_RemoveRemainingCameraBlood_Params params;
	params.SeatType = SeatType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::DoWeaponSight()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.DoWeaponSight");

	ABP_PlayerPawn_C_DoWeaponSight_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::SetWeaponSightStateLocal(bool* IsOpenWeaponSight)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.SetWeaponSightStateLocal");

	ABP_PlayerPawn_C_SetWeaponSightStateLocal_Params params;
	params.IsOpenWeaponSight = IsOpenWeaponSight;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::RearSightTimeLineUpdate(float* Alpha)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.RearSightTimeLineUpdate");

	ABP_PlayerPawn_C_RearSightTimeLineUpdate_Params params;
	params.Alpha = Alpha;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::RearSightTimeLineFinish(int* InRearSightNewIndex)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.RearSightTimeLineFinish");

	ABP_PlayerPawn_C_RearSightTimeLineFinish_Params params;
	params.InRearSightNewIndex = InRearSightNewIndex;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::AngleSightTimeLineUpdate(float* Alpha)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.AngleSightTimeLineUpdate");

	ABP_PlayerPawn_C_AngleSightTimeLineUpdate_Params params;
	params.Alpha = Alpha;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ABP_PlayerPawn_C::AngleSightTimeLineFinish()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.AngleSightTimeLineFinish");

	ABP_PlayerPawn_C_AngleSightTimeLineFinish_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::DoAutoReloadCurrentWeapon(class ASTExtraShootWeapon** ShootWeapon)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.DoAutoReloadCurrentWeapon");

	ABP_PlayerPawn_C_DoAutoReloadCurrentWeapon_Params params;
	params.ShootWeapon = ShootWeapon;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::ExecuteUbergraph_BP_PlayerPawn(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.ExecuteUbergraph_BP_PlayerPawn");

	ABP_PlayerPawn_C_ExecuteUbergraph_BP_PlayerPawn_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ABP_PlayerPawn_C::OnCakePlacement__DelegateSignature(bool Success)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_PlayerPawn.BP_PlayerPawn_C.OnCakePlacement__DelegateSignature");

	ABP_PlayerPawn_C_OnCakePlacement__DelegateSignature_Params params;
	params.Success = Success;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

