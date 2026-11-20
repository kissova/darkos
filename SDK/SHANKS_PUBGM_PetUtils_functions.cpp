// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 

void UPetUtils_C::GetPetLevelCfg(const struct FGameModePlayerPetInfo& PetInfo, class UObject* __WorldContext, struct FBP_STRUCT_PetLevelTable_type* Out_Row)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetUtils.PetUtils_C.GetPetLevelCfg");

	UPetUtils_C_GetPetLevelCfg_Params params;
	params.PetInfo = PetInfo;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Out_Row != nullptr)
		*Out_Row = params.Out_Row;
}


}

