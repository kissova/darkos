// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UTeamUp_Member_Menu_UIBP_C::Construct()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function TeamUp_Member_Menu_UIBP.TeamUp_Member_Menu_UIBP_C.Construct");

	UTeamUp_Member_Menu_UIBP_C_Construct_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UTeamUp_Member_Menu_UIBP_C::ExecuteUbergraph_TeamUp_Member_Menu_UIBP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function TeamUp_Member_Menu_UIBP.TeamUp_Member_Menu_UIBP_C.ExecuteUbergraph_TeamUp_Member_Menu_UIBP");

	UTeamUp_Member_Menu_UIBP_C_ExecuteUbergraph_TeamUp_Member_Menu_UIBP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

