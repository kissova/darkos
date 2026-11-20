// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UQuickSignComponent_BP_C::SetBoxMarkText(const struct FString& InputParam, struct FString* FinalText)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.SetBoxMarkText");

	UQuickSignComponent_BP_C_SetBoxMarkText_Params params;
	params.InputParam = InputParam;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (FinalText != nullptr)
		*FinalText = params.FinalText;
}


 
 
 
 
 
 

void UQuickSignComponent_BP_C::GetMarkTextShowedInChatBox(const struct FString& PlayerKey, int OldTextID, struct FString* Text)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.GetMarkTextShowedInChatBox");

	UQuickSignComponent_BP_C_GetMarkTextShowedInChatBox_Params params;
	params.PlayerKey = PlayerKey;
	params.OldTextID = OldTextID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Text != nullptr)
		*Text = params.Text;
}


 
 
 
 
 
 

void UQuickSignComponent_BP_C::SpectatorActorMark(class AActor** Actor, struct FQuickSignMsg* OriMarkInfo, struct FQuickSignMsg* MarkInfo)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.SpectatorActorMark");

	UQuickSignComponent_BP_C_SpectatorActorMark_Params params;
	params.Actor = Actor;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OriMarkInfo != nullptr)
		*OriMarkInfo = params.OriMarkInfo;
	if (MarkInfo != nullptr)
		*MarkInfo = params.MarkInfo;
}


 
 
 
 
 

void UQuickSignComponent_BP_C::SetDistanceText(const struct FVector& HidPosition, EQuickSignSubType MsgType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.SetDistanceText");

	UQuickSignComponent_BP_C_SetDistanceText_Params params;
	params.HidPosition = HidPosition;
	params.MsgType = MsgType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void UQuickSignComponent_BP_C::GetAudioEventAndBank(int audioID, int actorid, struct FString* OutBankName, struct FString* OutEventName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.GetAudioEventAndBank");

	UQuickSignComponent_BP_C_GetAudioEventAndBank_Params params;
	params.audioID = audioID;
	params.actorid = actorid;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutBankName != nullptr)
		*OutBankName = params.OutBankName;
	if (OutEventName != nullptr)
		*OutEventName = params.OutEventName;
}


 
 
 
 
 

int UQuickSignComponent_BP_C::GetVoiceAudioID(int* MsgType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.GetVoiceAudioID");

	UQuickSignComponent_BP_C_GetVoiceAudioID_Params params;
	params.MsgType = MsgType;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

void UQuickSignComponent_BP_C::PickupWrapperActorHandle(const struct FString& Param, struct FQuickSignMark* MarkInfo)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.PickupWrapperActorHandle");

	UQuickSignComponent_BP_C_PickupWrapperActorHandle_Params params;
	params.Param = Param;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (MarkInfo != nullptr)
		*MarkInfo = params.MarkInfo;
}


 
 
 
 
 
 

bool UQuickSignComponent_BP_C::GenerateMarkInfo(struct FQuickSignMsg* MsgItem, struct FQuickSignMark* MarkInfo)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.GenerateMarkInfo");

	UQuickSignComponent_BP_C_GenerateMarkInfo_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (MsgItem != nullptr)
		*MsgItem = params.MsgItem;
	if (MarkInfo != nullptr)
		*MarkInfo = params.MarkInfo;

	return params.ReturnValue;
}


 
 

void UQuickSignComponent_BP_C::LoadConfig()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.LoadConfig");

	UQuickSignComponent_BP_C_LoadConfig_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UQuickSignComponent_BP_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.ReceiveBeginPlay");

	UQuickSignComponent_BP_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UQuickSignComponent_BP_C::ShowMsgTipsVoice(struct FQuickSignMsg* MsgItem, bool* IsSelf, struct FString* PlayerKey)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.ShowMsgTipsVoice");

	UQuickSignComponent_BP_C_ShowMsgTipsVoice_Params params;
	params.MsgItem = MsgItem;
	params.IsSelf = IsSelf;
	params.PlayerKey = PlayerKey;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UQuickSignComponent_BP_C::PlayVoiceCD(float Duration)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.PlayVoiceCD");

	UQuickSignComponent_BP_C_PlayVoiceCD_Params params;
	params.Duration = Duration;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UQuickSignComponent_BP_C::ReportQuickSign(struct FQuickSignMsg* MsgItem)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.ReportQuickSign");

	UQuickSignComponent_BP_C_ReportQuickSign_Params params;
	params.MsgItem = MsgItem;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UQuickSignComponent_BP_C::ExecuteUbergraph_QuickSignComponent_BP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function QuickSignComponent_BP.QuickSignComponent_BP_C.ExecuteUbergraph_QuickSignComponent_BP");

	UQuickSignComponent_BP_C_ExecuteUbergraph_QuickSignComponent_BP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

