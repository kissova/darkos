// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 
 
 

void UTitle_UIBP_C::SetAliasInfo(int ID, const struct FString& Title, const struct FString& Nation, float Available_len, int RankID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Title_UIBP.Title_UIBP_C.SetAliasInfo");

	UTitle_UIBP_C_SetAliasInfo_Params params;
	params.ID = ID;
	params.Title = Title;
	params.Nation = Nation;
	params.Available_len = Available_len;
	params.RankID = RankID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UTitle_UIBP_C::PreConstruct(bool* IsDesignTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Title_UIBP.Title_UIBP_C.PreConstruct");

	UTitle_UIBP_C_PreConstruct_Params params;
	params.IsDesignTime = IsDesignTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UTitle_UIBP_C::ExecuteUbergraph_Title_UIBP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Title_UIBP.Title_UIBP_C.ExecuteUbergraph_Title_UIBP");

	UTitle_UIBP_C_ExecuteUbergraph_Title_UIBP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

