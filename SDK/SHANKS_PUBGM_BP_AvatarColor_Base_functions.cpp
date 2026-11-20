// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UBP_AvatarColor_Base_C::SetCustomColorDeffered(class UMaterialInterface** InMaterial, struct FSlotToMatColor* InMatColor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarColor_Base.BP_AvatarColor_Base_C.SetCustomColorDeffered");

	UBP_AvatarColor_Base_C_SetCustomColorDeffered_Params params;
	params.InMaterial = InMaterial;
	params.InMatColor = InMatColor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_AvatarColor_Base_C::ExecuteUbergraph_BP_AvatarColor_Base(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarColor_Base.BP_AvatarColor_Base_C.ExecuteUbergraph_BP_AvatarColor_Base");

	UBP_AvatarColor_Base_C_ExecuteUbergraph_BP_AvatarColor_Base_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

