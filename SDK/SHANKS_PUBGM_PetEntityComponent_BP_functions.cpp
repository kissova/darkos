// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

struct FPetAttachInfo UPetEntityComponent_BP_C::GetAttachInfoFromTable(struct FFixPetAttachInfo* Info)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetEntityComponent_BP.PetEntityComponent_BP_C.GetAttachInfoFromTable");

	UPetEntityComponent_BP_C_GetAttachInfoFromTable_Params params;
	params.Info = Info;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

