// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void ULobbyAvatarFunctionLibrary_C::OnPlayerRotate(class UCharacterAvatarComp2_BP_C* AvatarComp, class UObject* __WorldContext)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyAvatarFunctionLibrary.LobbyAvatarFunctionLibrary_C.OnPlayerRotate");

	ULobbyAvatarFunctionLibrary_C_OnPlayerRotate_Params params;
	params.AvatarComp = AvatarComp;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

