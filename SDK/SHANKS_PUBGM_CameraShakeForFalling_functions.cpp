// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UCameraShakeForFalling_C::ReceivePlayShake(float* Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CameraShakeForFalling.CameraShakeForFalling_C.ReceivePlayShake");

	UCameraShakeForFalling_C_ReceivePlayShake_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCameraShakeForFalling_C::ExecuteUbergraph_CameraShakeForFalling(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CameraShakeForFalling.CameraShakeForFalling_C.ExecuteUbergraph_CameraShakeForFalling");

	UCameraShakeForFalling_C_ExecuteUbergraph_CameraShakeForFalling_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

