// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UPetCustomCheckInterface_C::NotAllowAppear(bool* Out)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetCustomCheckInterface.PetCustomCheckInterface_C.NotAllowAppear");

	UPetCustomCheckInterface_C_NotAllowAppear_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Out != nullptr)
		*Out = params.Out;
}


}

