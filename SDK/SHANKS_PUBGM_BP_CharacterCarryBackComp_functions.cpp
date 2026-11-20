// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 
 

void UBP_CharacterCarryBackComp_C::FindFreedomLocationAndRotation(class ACharacter* Character, bool* bValid, struct FVector* Location, struct FRotator* Rotation)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_CharacterCarryBackComp.BP_CharacterCarryBackComp_C.FindFreedomLocationAndRotation");

	UBP_CharacterCarryBackComp_C_FindFreedomLocationAndRotation_Params params;
	params.Character = Character;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (bValid != nullptr)
		*bValid = params.bValid;
	if (Location != nullptr)
		*Location = params.Location;
	if (Rotation != nullptr)
		*Rotation = params.Rotation;
}


}

