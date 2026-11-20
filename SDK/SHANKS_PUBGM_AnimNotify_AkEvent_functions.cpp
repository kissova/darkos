// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UAnimNotify_AkEvent_C::TryGetOwnerPawn(class AActor* Owner, class APawn** Pawn)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AnimNotify_AkEvent.AnimNotify_AkEvent_C.TryGetOwnerPawn");

	UAnimNotify_AkEvent_C_TryGetOwnerPawn_Params params;
	params.Owner = Owner;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Pawn != nullptr)
		*Pawn = params.Pawn;
}


 
 
 
 
 

void UAnimNotify_AkEvent_C::GetEvent(class USkeletalMeshComponent* MeshComp, class UAkAudioEvent** OutEvent)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AnimNotify_AkEvent.AnimNotify_AkEvent_C.GetEvent");

	UAnimNotify_AkEvent_C_GetEvent_Params params;
	params.MeshComp = MeshComp;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutEvent != nullptr)
		*OutEvent = params.OutEvent;
}


 
 
 
 
 
 

bool UAnimNotify_AkEvent_C::Received_Notify(class USkeletalMeshComponent** MeshComp, class UAnimSequenceBase** Animation)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AnimNotify_AkEvent.AnimNotify_AkEvent_C.Received_Notify");

	UAnimNotify_AkEvent_C_Received_Notify_Params params;
	params.MeshComp = MeshComp;
	params.Animation = Animation;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

