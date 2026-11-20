// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void ULobby_RoleInfo_IntimacyItem_UIBP_C::PreConstruct(bool* IsDesignTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Lobby_RoleInfo_IntimacyItem_UIBP.Lobby_RoleInfo_IntimacyItem_UIBP_C.PreConstruct");

	ULobby_RoleInfo_IntimacyItem_UIBP_C_PreConstruct_Params params;
	params.IsDesignTime = IsDesignTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ULobby_RoleInfo_IntimacyItem_UIBP_C::ExecuteUbergraph_Lobby_RoleInfo_IntimacyItem_UIBP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Lobby_RoleInfo_IntimacyItem_UIBP.Lobby_RoleInfo_IntimacyItem_UIBP_C.ExecuteUbergraph_Lobby_RoleInfo_IntimacyItem_UIBP");

	ULobby_RoleInfo_IntimacyItem_UIBP_C_ExecuteUbergraph_Lobby_RoleInfo_IntimacyItem_UIBP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

