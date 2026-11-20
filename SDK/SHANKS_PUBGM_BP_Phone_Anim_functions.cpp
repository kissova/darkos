// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UBP_Phone_Anim_C::AnimNotify_ShowPhone()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Phone_Anim.BP_Phone_Anim_C.AnimNotify_ShowPhone");

	UBP_Phone_Anim_C_AnimNotify_ShowPhone_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_Phone_Anim_C::ExecuteUbergraph_BP_Phone_Anim(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_Phone_Anim.BP_Phone_Anim_C.ExecuteUbergraph_BP_Phone_Anim");

	UBP_Phone_Anim_C_ExecuteUbergraph_BP_Phone_Anim_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

