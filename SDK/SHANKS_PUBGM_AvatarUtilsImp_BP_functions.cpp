// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

int UAvatarUtilsImp_BP_C::GetAdjustWeaponBPID_Lobby(int* WeaponId)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.GetAdjustWeaponBPID_Lobby");

	UAvatarUtilsImp_BP_C_GetAdjustWeaponBPID_Lobby_Params params;
	params.WeaponId = WeaponId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

bool UAvatarUtilsImp_BP_C::GetVehicleDefaultStyleID(int* InVehicleSkinID, TArray<int>* OutStyleIDList)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.GetVehicleDefaultStyleID");

	UAvatarUtilsImp_BP_C_GetVehicleDefaultStyleID_Params params;
	params.InVehicleSkinID = InVehicleSkinID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutStyleIDList != nullptr)
		*OutStyleIDList = params.OutStyleIDList;

	return params.ReturnValue;
}


 
 
 
 
 

struct FString UAvatarUtilsImp_BP_C::GetVehicleBPPathBySkinID(int* InVehicleSkinID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.GetVehicleBPPathBySkinID");

	UAvatarUtilsImp_BP_C_GetVehicleBPPathBySkinID_Params params;
	params.InVehicleSkinID = InVehicleSkinID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

int UAvatarUtilsImp_BP_C::GetVehicleShapeBySkinID(int* InVehicleSkinID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.GetVehicleShapeBySkinID");

	UAvatarUtilsImp_BP_C_GetVehicleShapeBySkinID_Params params;
	params.InVehicleSkinID = InVehicleSkinID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

void UAvatarUtilsImp_BP_C::GetBPTableName(int Type, int TypeSpecificID, struct FString* BPTableName, int* SpecificID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.GetBPTableName");

	UAvatarUtilsImp_BP_C_GetBPTableName_Params params;
	params.Type = Type;
	params.TypeSpecificID = TypeSpecificID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (BPTableName != nullptr)
		*BPTableName = params.BPTableName;
	if (SpecificID != nullptr)
		*SpecificID = params.SpecificID;
}


 
 
 
 
 
 
 

class UItemHandleBase* UAvatarUtilsImp_BP_C::CreateAvatarHandle(struct FItemDefineID* DefineID, class UObject** Outer, bool* bLobby)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.CreateAvatarHandle");

	UAvatarUtilsImp_BP_C_CreateAvatarHandle_Params params;
	params.DefineID = DefineID;
	params.Outer = Outer;
	params.bLobby = bLobby;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

struct FString UAvatarUtilsImp_BP_C::GetAvatarHandlePath(struct FItemDefineID* DefineID, bool* bLobby)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AvatarUtilsImp_BP.AvatarUtilsImp_BP_C.GetAvatarHandlePath");

	UAvatarUtilsImp_BP_C_GetAvatarHandlePath_Params params;
	params.DefineID = DefineID;
	params.bLobby = bLobby;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

