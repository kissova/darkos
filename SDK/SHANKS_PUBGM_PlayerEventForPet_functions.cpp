// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UPlayerEventForPet_C::PlayerStateChange(EPawnState State, TEnumAsByte<EPawnStateChangeType> ChangeType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PlayerEventForPet.PlayerEventForPet_C.PlayerStateChange");

	UPlayerEventForPet_C_PlayerStateChange_Params params;
	params.State = State;
	params.ChangeType = ChangeType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

