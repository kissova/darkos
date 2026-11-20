// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UPetSwimInterface_C::ISetLeaveSwimMode()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetSwimInterface.PetSwimInterface_C.ISetLeaveSwimMode");

	UPetSwimInterface_C_ISetLeaveSwimMode_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UPetSwimInterface_C::ISetEnterSwimMode(float WaterSurface)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetSwimInterface.PetSwimInterface_C.ISetEnterSwimMode");

	UPetSwimInterface_C_ISetEnterSwimMode_Params params;
	params.WaterSurface = WaterSurface;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

