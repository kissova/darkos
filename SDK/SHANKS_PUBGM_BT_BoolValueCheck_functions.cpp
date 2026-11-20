// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

bool UBT_BoolValueCheck_C::PerformConditionCheck(class AActor** OwnerActor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BT_BoolValueCheck.BT_BoolValueCheck_C.PerformConditionCheck");

	UBT_BoolValueCheck_C_PerformConditionCheck_Params params;
	params.OwnerActor = OwnerActor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UBT_BoolValueCheck_C::ExecuteUbergraph_BT_BoolValueCheck(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BT_BoolValueCheck.BT_BoolValueCheck_C.ExecuteUbergraph_BT_BoolValueCheck");

	UBT_BoolValueCheck_C_ExecuteUbergraph_BT_BoolValueCheck_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

