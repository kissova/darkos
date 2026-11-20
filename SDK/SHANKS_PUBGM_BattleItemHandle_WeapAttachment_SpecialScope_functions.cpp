// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UBattleItemHandle_WeapAttachment_SpecialScope_C::GetFov(float* FOV)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BattleItemHandle_WeapAttachment_SpecialScope.BattleItemHandle_WeapAttachment_SpecialScope_C.GetFov");

	UBattleItemHandle_WeapAttachment_SpecialScope_C_GetFov_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (FOV != nullptr)
		*FOV = params.FOV;
}


}

