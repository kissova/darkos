// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 

bool UPetOwnerAppearCheck_C::PerformConditionCheckAI(class AAIController** OwnerController, class APawn** ControlledPawn)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetOwnerAppearCheck.PetOwnerAppearCheck_C.PerformConditionCheckAI");

	UPetOwnerAppearCheck_C_PerformConditionCheckAI_Params params;
	params.OwnerController = OwnerController;
	params.ControlledPawn = ControlledPawn;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

