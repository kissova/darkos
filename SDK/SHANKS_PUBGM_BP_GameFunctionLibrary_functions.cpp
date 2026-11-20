// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UBP_GameFunctionLibrary_C::GetModeMaxTeammateNum(class UObject* __WorldContext, int* Result)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.GetModeMaxTeammateNum");

	UBP_GameFunctionLibrary_C_GetModeMaxTeammateNum_Params params;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Result != nullptr)
		*Result = params.Result;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::EditorGetGameModeID(class UObject* WorldCont, class UObject* __WorldContext, struct FString* ModeID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.EditorGetGameModeID");

	UBP_GameFunctionLibrary_C_EditorGetGameModeID_Params params;
	params.WorldCont = WorldCont;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (ModeID != nullptr)
		*ModeID = params.ModeID;
}


 
 
 
 
 
 
 

bool UBP_GameFunctionLibrary_C::IsInFloatRangeUpperBound(float Value, const struct FFloatRangeBound& FloatRangeBound, class UObject* __WorldContext)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.IsInFloatRangeUpperBound");

	UBP_GameFunctionLibrary_C_IsInFloatRangeUpperBound_Params params;
	params.Value = Value;
	params.FloatRangeBound = FloatRangeBound;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

bool UBP_GameFunctionLibrary_C::IsInFloatRangeLowerBound(float Value, const struct FFloatRangeBound& FloatRangeBound, class UObject* __WorldContext)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.IsInFloatRangeLowerBound");

	UBP_GameFunctionLibrary_C_IsInFloatRangeLowerBound_Params params;
	params.Value = Value;
	params.FloatRangeBound = FloatRangeBound;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 

bool UBP_GameFunctionLibrary_C::IsInFloatRange(float Value, const struct FFloatRange& FloatRange, class UObject* __WorldContext)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.IsInFloatRange");

	UBP_GameFunctionLibrary_C_IsInFloatRange_Params params;
	params.Value = Value;
	params.FloatRange = FloatRange;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::GetGuideTextStruct(int NewParam, class UObject* __WorldContext, struct FBP_STRUCT_GuideText_type* NewParam1)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.GetGuideTextStruct");

	UBP_GameFunctionLibrary_C_GetGuideTextStruct_Params params;
	params.NewParam = NewParam;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (NewParam1 != nullptr)
		*NewParam1 = params.NewParam1;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::GetMinimapPathByModeID(class UObject* WorldContext, class UObject* __WorldContext, struct FString* MinimapPath)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.GetMinimapPathByModeID");

	UBP_GameFunctionLibrary_C_GetMinimapPathByModeID_Params params;
	params.WorldContext = WorldContext;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (MinimapPath != nullptr)
		*MinimapPath = params.MinimapPath;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::GetCurLevelMinimapPath(class UObject* WorldContext, class UObject* __WorldContext, struct FString* MinimapPath)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.GetCurLevelMinimapPath");

	UBP_GameFunctionLibrary_C_GetCurLevelMinimapPath_Params params;
	params.WorldContext = WorldContext;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (MinimapPath != nullptr)
		*MinimapPath = params.MinimapPath;
}


 
 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::ClampStringLength(const struct FString& Source, int Length, class UObject* __WorldContext, struct FString* Result)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.ClampStringLength");

	UBP_GameFunctionLibrary_C_ClampStringLength_Params params;
	params.Source = Source;
	params.Length = Length;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Result != nullptr)
		*Result = params.Result;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::IsPlayerCanSeeWidget(class UWidget* NewParam, class UObject* __WorldContext, bool* cansee)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.IsPlayerCanSeeWidget");

	UBP_GameFunctionLibrary_C_IsPlayerCanSeeWidget_Params params;
	params.NewParam = NewParam;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (cansee != nullptr)
		*cansee = params.cansee;
}


 
 
 
 
 

void UBP_GameFunctionLibrary_C::GetCurLevelMapTexture(class UObject* __WorldContext, class UTexture2D** Texture)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.GetCurLevelMapTexture");

	UBP_GameFunctionLibrary_C_GetCurLevelMapTexture_Params params;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Texture != nullptr)
		*Texture = params.Texture;
}


 
 
 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::GetActorsByTag(const struct FName& Tag, class UObject* ContextObject, class UClass* ActorClass, class UObject* __WorldContext, TArray<class AActor*>* Targets)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.GetActorsByTag");

	UBP_GameFunctionLibrary_C_GetActorsByTag_Params params;
	params.Tag = Tag;
	params.ContextObject = ContextObject;
	params.ActorClass = ActorClass;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Targets != nullptr)
		*Targets = params.Targets;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::AddActorTag(class AActor* Target, const struct FName& TagInfo, class UObject* __WorldContext)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.AddActorTag");

	UBP_GameFunctionLibrary_C_AddActorTag_Params params;
	params.Target = Target;
	params.TagInfo = TagInfo;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UBP_GameFunctionLibrary_C::SetUpGamePostProcessEffectData(class APostProcessVolume* Volume, class UObject* ContextObject, class UObject* __WorldContext)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_GameFunctionLibrary.BP_GameFunctionLibrary_C.SetUpGamePostProcessEffectData");

	UBP_GameFunctionLibrary_C_SetUpGamePostProcessEffectData_Params params;
	params.Volume = Volume;
	params.ContextObject = ContextObject;
	params.__WorldContext = __WorldContext;

	auto flags = pFunc->FunctionFlags;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

