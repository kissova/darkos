// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

bool UAnimNotify_SelfAkEvent_C::PlayAkEvent(class USkeletalMeshComponent* MeshComp)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AnimNotify_SelfAkEvent.AnimNotify_SelfAkEvent_C.PlayAkEvent");

	UAnimNotify_SelfAkEvent_C_PlayAkEvent_Params params;
	params.MeshComp = MeshComp;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

bool UAnimNotify_SelfAkEvent_C::Received_Notify(class USkeletalMeshComponent** MeshComp, class UAnimSequenceBase** Animation)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AnimNotify_SelfAkEvent.AnimNotify_SelfAkEvent_C.Received_Notify");

	UAnimNotify_SelfAkEvent_C_Received_Notify_Params params;
	params.MeshComp = MeshComp;
	params.Animation = Animation;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

