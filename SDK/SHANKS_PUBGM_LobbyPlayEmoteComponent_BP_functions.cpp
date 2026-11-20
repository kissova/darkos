// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::OnEquipmentChange(int resID, bool bPutOn)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.OnEquipmentChange");

	ULobbyPlayEmoteComponent_BP_C_OnEquipmentChange_Params params;
	params.resID = resID;
	params.bPutOn = bPutOn;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ULobbyPlayEmoteComponent_BP_C::OnStartLevelSequence()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.OnStartLevelSequence");

	ULobbyPlayEmoteComponent_BP_C_OnStartLevelSequence_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::GetLobbyCamera(class ACameraActor** CameraActor)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.GetLobbyCamera");

	ULobbyPlayEmoteComponent_BP_C_GetLobbyCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (CameraActor != nullptr)
		*CameraActor = params.CameraActor;
}


 
 

void ULobbyPlayEmoteComponent_BP_C::OnStopLevelSequence()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.OnStopLevelSequence");

	ULobbyPlayEmoteComponent_BP_C_OnStopLevelSequence_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ULobbyPlayEmoteComponent_BP_C::ChangetoLevelSequenceCamera()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.ChangetoLevelSequenceCamera");

	ULobbyPlayEmoteComponent_BP_C_ChangetoLevelSequenceCamera_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::OnTrackEvent(const struct FString& EventData)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.OnTrackEvent");

	ULobbyPlayEmoteComponent_BP_C_OnTrackEvent_Params params;
	params.EventData = EventData;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::PlayCameraEmoteAnim(class ULevelSequence** CurrentCameraEmoteAnim)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.PlayCameraEmoteAnim");

	ULobbyPlayEmoteComponent_BP_C_PlayCameraEmoteAnim_Params params;
	params.CurrentCameraEmoteAnim = CurrentCameraEmoteAnim;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void ULobbyPlayEmoteComponent_BP_C::StopCameraEmoteAnim()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.StopCameraEmoteAnim");

	ULobbyPlayEmoteComponent_BP_C_StopCameraEmoteAnim_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::ShowAvatarForEmote(bool* Show, bool* Force)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.ShowAvatarForEmote");

	ULobbyPlayEmoteComponent_BP_C_ShowAvatarForEmote_Params params;
	params.Show = Show;
	params.Force = Force;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::BindEventToCameraSequence(class ULevelSequencePlayer** SeqPlayer)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.BindEventToCameraSequence");

	ULobbyPlayEmoteComponent_BP_C_BindEventToCameraSequence_Params params;
	params.SeqPlayer = SeqPlayer;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void ULobbyPlayEmoteComponent_BP_C::ExecuteUbergraph_LobbyPlayEmoteComponent_BP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C.ExecuteUbergraph_LobbyPlayEmoteComponent_BP");

	ULobbyPlayEmoteComponent_BP_C_ExecuteUbergraph_LobbyPlayEmoteComponent_BP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

