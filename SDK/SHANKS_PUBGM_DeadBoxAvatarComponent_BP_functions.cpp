// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UDeadBoxAvatarComponent_BP_C::GetVehicleDiedPath(int ItemId, struct FString* Path)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function DeadBoxAvatarComponent_BP.DeadBoxAvatarComponent_BP_C.GetVehicleDiedPath");

	UDeadBoxAvatarComponent_BP_C_GetVehicleDiedPath_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Path != nullptr)
		*Path = params.Path;
}


 
 
 
 
 

void UDeadBoxAvatarComponent_BP_C::IsVehicleAvatarID(int ItemId, bool* IsVehicleAvatarID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function DeadBoxAvatarComponent_BP.DeadBoxAvatarComponent_BP_C.IsVehicleAvatarID");

	UDeadBoxAvatarComponent_BP_C_IsVehicleAvatarID_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (IsVehicleAvatarID != nullptr)
		*IsVehicleAvatarID = params.IsVehicleAvatarID;
}


 
 
 
 
 

struct FString UDeadBoxAvatarComponent_BP_C::GetItemAvatarHandlePath(int* ItemId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function DeadBoxAvatarComponent_BP.DeadBoxAvatarComponent_BP_C.GetItemAvatarHandlePath");

	UDeadBoxAvatarComponent_BP_C_GetItemAvatarHandlePath_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

class UBackpackCommonAvatarHandle* UDeadBoxAvatarComponent_BP_C::GetItemAvatarHandle(int* ItemId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function DeadBoxAvatarComponent_BP.DeadBoxAvatarComponent_BP_C.GetItemAvatarHandle");

	UDeadBoxAvatarComponent_BP_C_GetItemAvatarHandle_Params params;
	params.ItemId = ItemId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

