// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UVault_Controller_C::JumpVault()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Vault_Controller.Vault_Controller_C.JumpVault");

	UVault_Controller_C_JumpVault_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 
 
 
 
 
 
 
 

void UVault_Controller_C::VaultServer(float dis, float Height, float Length, const struct FString& VaultKey, const struct FVector& StartPos, class AActor* checkActor, float crossblockMaxFall, float crossblockMaxDis, const struct FVector& HitPoint, class AActor* WindowActor, const struct FRotator& MoveDir)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Vault_Controller.Vault_Controller_C.VaultServer");

	UVault_Controller_C_VaultServer_Params params;
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


 
 
 
 
 
 
 
 
 
 
 
 
 

void UVault_Controller_C::vaultAll(float dis, float Height, float Length, const struct FString& VaultKey, const struct FVector& StartPos, class AActor* checkActor, float crossmaxFalling, float crossmaxDis, const struct FVector& HitPoint, const struct FRotator& MoveDir)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Vault_Controller.Vault_Controller_C.vaultAll");

	UVault_Controller_C_vaultAll_Params params;
	params.dis = dis;
	params.Height = Height;
	params.Length = Length;
	params.VaultKey = VaultKey;
	params.StartPos = StartPos;
	params.checkActor = checkActor;
	params.crossmaxFalling = crossmaxFalling;
	params.crossmaxDis = crossmaxDis;
	params.HitPoint = HitPoint;
	params.MoveDir = MoveDir;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UVault_Controller_C::StopVault()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Vault_Controller.Vault_Controller_C.StopVault");

	UVault_Controller_C_StopVault_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UVault_Controller_C::DsCheckStopVault()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Vault_Controller.Vault_Controller_C.DsCheckStopVault");

	UVault_Controller_C_DsCheckStopVault_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UVault_Controller_C::ExecuteUbergraph_Vault_Controller(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Vault_Controller.Vault_Controller_C.ExecuteUbergraph_Vault_Controller");

	UVault_Controller_C_ExecuteUbergraph_Vault_Controller_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

