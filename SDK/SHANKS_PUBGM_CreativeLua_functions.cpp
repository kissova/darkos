// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UCreativeBridgeLuaVM::UGCLuaError(int ErrCode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.UGCLuaError");

	UCreativeBridgeLuaVM_UGCLuaError_Params params;
	params.ErrCode = ErrCode;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCreativeBridgeLuaVM::SetUGCSuspendStateFix(bool bEnable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.SetUGCSuspendStateFix");

	UCreativeBridgeLuaVM_SetUGCSuspendStateFix_Params params;
	params.bEnable = bEnable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCreativeBridgeLuaVM::RegisterSluaCallUgcluaEventHandler()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.RegisterSluaCallUgcluaEventHandler");

	UCreativeBridgeLuaVM_RegisterSluaCallUgcluaEventHandler_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCreativeBridgeLuaVM::PostInit()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.PostInit");

	UCreativeBridgeLuaVM_PostInit_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

bool UCreativeBridgeLuaVM::GetUGCSuspendStateFix()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.GetUGCSuspendStateFix");

	UCreativeBridgeLuaVM_GetUGCSuspendStateFix_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

class UCreativeEnvLuaVM* UCreativeEnvLuaVMFactory::CreateCreativeEnvLuaVM(const struct FString& InLuaFilePath, class UObject* WorldContextObject)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeEnvLuaVMFactory.CreateCreativeEnvLuaVM");

	UCreativeEnvLuaVMFactory_CreateCreativeEnvLuaVM_Params params;
	params.InLuaFilePath = InLuaFilePath;
	params.WorldContextObject = WorldContextObject;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

