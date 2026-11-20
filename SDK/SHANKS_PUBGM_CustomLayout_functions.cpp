// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

void UCustomizePanel::SetScale(float Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetScale");

	UCustomizePanel_SetScale_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetPosition(const struct FVector2D& Position)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetPosition");

	UCustomizePanel_SetPosition_Params params;
	params.Position = Position;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UCustomizePanel::SetOpacityWithClamp(float InOpacity, float MinOpacity, float MaxOpacity)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetOpacityWithClamp");

	UCustomizePanel_SetOpacityWithClamp_Params params;
	params.InOpacity = InOpacity;
	params.MinOpacity = MinOpacity;
	params.MaxOpacity = MaxOpacity;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetOpacity(float InOpacity)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetOpacity");

	UCustomizePanel_SetOpacity_Params params;
	params.InOpacity = InOpacity;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetMovable(bool bInMovable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetMovable");

	UCustomizePanel_SetMovable_Params params;
	params.bInMovable = bInMovable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetMaxScale(float Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetMaxScale");

	UCustomizePanel_SetMaxScale_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetInvalid(bool Invalid)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetInvalid");

	UCustomizePanel_SetInvalid_Params params;
	params.Invalid = Invalid;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetInterceptChildInput(bool bInIntercept)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetInterceptChildInput");

	UCustomizePanel_SetInterceptChildInput_Params params;
	params.bInIntercept = bInIntercept;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetDrawMargin(bool bDraw)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDrawMargin");

	UCustomizePanel_SetDrawMargin_Params params;
	params.bDraw = bDraw;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetDetectMargin(const struct FMargin& InMargin)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDetectMargin");

	UCustomizePanel_SetDetectMargin_Params params;
	params.InMargin = InMargin;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetDesireScale(float Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDesireScale");

	UCustomizePanel_SetDesireScale_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetDesirePosition(const struct FVector2D& Position)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDesirePosition");

	UCustomizePanel_SetDesirePosition_Params params;
	params.Position = Position;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetDefaultLayoutCode(const struct FCustomLayoutBlueprintCode& InCode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDefaultLayoutCode");

	UCustomizePanel_SetDefaultLayoutCode_Params params;
	params.InCode = InCode;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UCustomizePanel::SetDefaultLayoutByPositionAndAnchors(const struct FVector2D& InPosition, const struct FAnchors& InAnchors)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDefaultLayoutByPositionAndAnchors");

	UCustomizePanel_SetDefaultLayoutByPositionAndAnchors_Params params;
	params.InPosition = InPosition;
	params.InAnchors = InAnchors;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::SetCustomType(int NewType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetCustomType");

	UCustomizePanel_SetCustomType_Params params;
	params.NewType = NewType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCustomizePanel::RestoreInBound()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.RestoreInBound");

	UCustomizePanel_RestoreInBound_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCustomizePanel::ResetMaxScale()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ResetMaxScale");

	UCustomizePanel_ResetMaxScale_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

bool UCustomizePanel::IsOutOfBound(float InvisibleCheckOffset)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.IsOutOfBound");

	UCustomizePanel_IsOutOfBound_Params params;
	params.InvisibleCheckOffset = InvisibleCheckOffset;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UCustomizePanel::InitDefaultLayoutData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.InitDefaultLayoutData");

	UCustomizePanel_InitDefaultLayoutData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

float UCustomizePanel::GetScale()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetScale");

	UCustomizePanel_GetScale_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FVector2D UCustomizePanel::GetPosition()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetPosition");

	UCustomizePanel_GetPosition_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

float UCustomizePanel::GetOpacity()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetOpacity");

	UCustomizePanel_GetOpacity_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

bool UCustomizePanel::GetMovable()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetMovable");

	UCustomizePanel_GetMovable_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

float UCustomizePanel::GetMaxScale()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetMaxScale");

	UCustomizePanel_GetMaxScale_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FUIElemLayoutDetail UCustomizePanel::GetLayoutData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetLayoutData");

	UCustomizePanel_GetLayoutData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FCustomLayoutBlueprintCode UCustomizePanel::GetLayoutCode()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetLayoutCode");

	UCustomizePanel_GetLayoutCode_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

bool UCustomizePanel::GetInvalid()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetInvalid");

	UCustomizePanel_GetInvalid_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FUIElemLayoutDetail UCustomizePanel::GetDefaultLayoutData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetDefaultLayoutData");

	UCustomizePanel_GetDefaultLayoutData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

int UCustomizePanel::GetCustomType()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetCustomType");

	UCustomizePanel_GetCustomType_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FVector2D UCustomizePanel::ClampPosition(const struct FVector2D& DesiredPos)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ClampPosition");

	UCustomizePanel_ClampPosition_Params params;
	params.DesiredPos = DesiredPos;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UCustomizePanel::ApplyLayoutData(const struct FUIElemLayoutDetail& LayoutDetail)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ApplyLayoutData");

	UCustomizePanel_ApplyLayoutData_Params params;
	params.LayoutDetail = LayoutDetail;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomizePanel::ApplyLayoutCode(const struct FCustomLayoutBlueprintCode& InCode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ApplyLayoutCode");

	UCustomizePanel_ApplyLayoutCode_Params params;
	params.InCode = InCode;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCustomizePanel::ApplyDefaultLayout()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ApplyDefaultLayout");

	UCustomizePanel_ApplyDefaultLayout_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

struct FUIElemLayoutDetail UCustomLayoutBlueprintLibrary::MakeLayoutDetail(int Type, EAnchorsType AnchorType, const struct FVector2D& Offset)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.MakeLayoutDetail");

	UCustomLayoutBlueprintLibrary_MakeLayoutDetail_Params params;
	params.Type = Type;
	params.AnchorType = AnchorType;
	params.Offset = Offset;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FAnchors UCustomLayoutBlueprintLibrary::Conv_TypeToAnchors(EAnchorsType InType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_TypeToAnchors");

	UCustomLayoutBlueprintLibrary_Conv_TypeToAnchors_Params params;
	params.InType = InType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

uint64_t UCustomLayoutBlueprintLibrary::Conv_TouchStatInfoToLong(const struct FTouchStatInfo& Info)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_TouchStatInfoToLong");

	UCustomLayoutBlueprintLibrary_Conv_TouchStatInfoToLong_Params params;
	params.Info = Info;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FTouchStatInfo UCustomLayoutBlueprintLibrary::Conv_LongToTouchStatInfo(uint64_t Num)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_LongToTouchStatInfo");

	UCustomLayoutBlueprintLibrary_Conv_LongToTouchStatInfo_Params params;
	params.Num = Num;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FCustomLayoutBlueprintCode UCustomLayoutBlueprintLibrary::Conv_LayoutDetailToCode(const struct FUIElemLayoutDetail& InDetail)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_LayoutDetailToCode");

	UCustomLayoutBlueprintLibrary_Conv_LayoutDetailToCode_Params params;
	params.InDetail = InDetail;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

struct FUIElemLayoutDetail UCustomLayoutBlueprintLibrary::Conv_CodeToLayoutDetail(const struct FCustomLayoutBlueprintCode& InCode, int Type)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_CodeToLayoutDetail");

	UCustomLayoutBlueprintLibrary_Conv_CodeToLayoutDetail_Params params;
	params.InCode = InCode;
	params.Type = Type;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EAnchorsType UCustomLayoutBlueprintLibrary::Conv_AnchorsToType(const struct FAnchors& InAnchors)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_AnchorsToType");

	UCustomLayoutBlueprintLibrary_Conv_AnchorsToType_Params params;
	params.InAnchors = InAnchors;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UCustomLayoutSubsystem::UnregisterCustomPanel(class UCustomPanel* InCustomizePanel)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.UnregisterCustomPanel");

	UCustomLayoutSubsystem_UnregisterCustomPanel_Params params;
	params.InCustomizePanel = InCustomizePanel;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutSubsystem::SetScreenPadding(const struct FMargin& InOffset)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.SetScreenPadding");

	UCustomLayoutSubsystem_SetScreenPadding_Params params;
	params.InOffset = InOffset;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutSubsystem::SetEditMode(bool bEnable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.SetEditMode");

	UCustomLayoutSubsystem_SetEditMode_Params params;
	params.bEnable = bEnable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutSubsystem::RemoveUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.RemoveUserSettingSlot");

	UCustomLayoutSubsystem_RemoveUserSettingSlot_Params params;
	params.InUserSetting = InUserSetting;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutSubsystem::RegisterCustomPanel(class UCustomPanel* InCustomizePanel)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.RegisterCustomPanel");

	UCustomLayoutSubsystem_RegisterCustomPanel_Params params;
	params.InCustomizePanel = InCustomizePanel;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UCustomLayoutSubsystem::InsertUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting, int Index)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.InsertUserSettingSlot");

	UCustomLayoutSubsystem_InsertUserSettingSlot_Params params;
	params.InUserSetting = InUserSetting;
	params.Index = Index;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

class UCustomLayoutUserSetting* UCustomLayoutSubsystem::GetUserSettingInSlot(const struct FString& Name)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.GetUserSettingInSlot");

	UCustomLayoutSubsystem_GetUserSettingInSlot_Params params;
	params.Name = Name;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

class UCustomPanel* UCustomLayoutSubsystem::GetRegisteredPanel(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.GetRegisteredPanel");

	UCustomLayoutSubsystem_GetRegisteredPanel_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UCustomLayoutSubsystem::FlushRegisteredPanelMap()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.FlushRegisteredPanelMap");

	UCustomLayoutSubsystem_FlushRegisteredPanelMap_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

bool UCustomLayoutSubsystem::FindLayoutDetail(int InCustomType, struct FUIElemLayoutDetail* OutDetail)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.FindLayoutDetail");

	UCustomLayoutSubsystem_FindLayoutDetail_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutDetail != nullptr)
		*OutDetail = params.OutDetail;

	return params.ReturnValue;
}


 
 

void UCustomLayoutSubsystem::ClearUserSettingSlots()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.ClearUserSettingSlots");

	UCustomLayoutSubsystem_ClearUserSettingSlots_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCustomLayoutSubsystem::ClearRegisteredPanelMap()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.ClearRegisteredPanelMap");

	UCustomLayoutSubsystem_ClearRegisteredPanelMap_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutSubsystem::BroadcastCustomLayoutChange(TArray<int> InCustomTypeList)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.BroadcastCustomLayoutChange");

	UCustomLayoutSubsystem_BroadcastCustomLayoutChange_Params params;
	params.InCustomTypeList = InCustomTypeList;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutSubsystem::AddUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.AddUserSettingSlot");

	UCustomLayoutSubsystem_AddUserSettingSlot_Params params;
	params.InUserSetting = InUserSetting;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UCustomLayoutUserSetting::UpdateTimeTag()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.UpdateTimeTag");

	UCustomLayoutUserSetting_UpdateTimeTag_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutUserSetting::SetTimeTagFromUnixTimestamp(int64_t InUnixTimestamp)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.SetTimeTagFromUnixTimestamp");

	UCustomLayoutUserSetting_SetTimeTagFromUnixTimestamp_Params params;
	params.InUnixTimestamp = InUnixTimestamp;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UCustomLayoutUserSetting::SetDataByLayoutDetail(int InCustomType, const struct FUIElemLayoutDetail& InData)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.SetDataByLayoutDetail");

	UCustomLayoutUserSetting_SetDataByLayoutDetail_Params params;
	params.InCustomType = InCustomType;
	params.InData = InData;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomLayoutUserSetting::RemoveData(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.RemoveData");

	UCustomLayoutUserSetting_RemoveData_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

int64_t UCustomLayoutUserSetting::GetTimeTagAsUnixTimestamp()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetTimeTagAsUnixTimestamp");

	UCustomLayoutUserSetting_GetTimeTagAsUnixTimestamp_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

uint64_t UCustomLayoutUserSetting::GetLayoutCodeCheckSum()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetLayoutCodeCheckSum");

	UCustomLayoutUserSetting_GetLayoutCodeCheckSum_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FUIElemLayoutDetail UCustomLayoutUserSetting::GetDataAsLayoutDetail(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetDataAsLayoutDetail");

	UCustomLayoutUserSetting_GetDataAsLayoutDetail_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UCustomLayoutUserSetting::GetCustomTypeList(TArray<int>* OutKeys)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetCustomTypeList");

	UCustomLayoutUserSetting_GetCustomTypeList_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutKeys != nullptr)
		*OutKeys = params.OutKeys;
}


 
 
 
 
 

bool UCustomLayoutUserSetting::Contains(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.Contains");

	UCustomLayoutUserSetting_Contains_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UCustomPanel::UpdateCustomLayout()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomPanel.UpdateCustomLayout");

	UCustomPanel_UpdateCustomLayout_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCustomPanel::SetEditable(bool bEditable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomPanel.SetEditable");

	UCustomPanel_SetEditable_Params params;
	params.bEditable = bEditable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

class UDynamicCustomIndexer* UDynamicCustomIndexer::GetIndexer(const struct FString& Path)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.DynamicCustomIndexer.GetIndexer");

	UDynamicCustomIndexer_GetIndexer_Params params;
	params.Path = Path;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FCustomLayoutBlueprintCode UDynamicCustomIndexer::GetDefaultLayoutCode(int CustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.DynamicCustomIndexer.GetDefaultLayoutCode");

	UDynamicCustomIndexer_GetDefaultLayoutCode_Params params;
	params.CustomType = CustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 
 
 

TMap<int, class UCustomizePanel*> UDynamicCustomIndexer::CreateDynamicCustomWidgets(TArray<int> InCustomTypeList, class UCanvasPanel* Container, bool bIgnoreDPIScale, TMap<int, class UCustomizePanel*>* CustomPanelMap)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.DynamicCustomIndexer.CreateDynamicCustomWidgets");

	UDynamicCustomIndexer_CreateDynamicCustomWidgets_Params params;
	params.InCustomTypeList = InCustomTypeList;
	params.Container = Container;
	params.bIgnoreDPIScale = bIgnoreDPIScale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (CustomPanelMap != nullptr)
		*CustomPanelMap = params.CustomPanelMap;

	return params.ReturnValue;
}


 
 
 
 

void UPinchDragWidget::SetPinchEnabled(bool bEnabled)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.SetPinchEnabled");

	UPinchDragWidget_SetPinchEnabled_Params params;
	params.bEnabled = bEnabled;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UPinchDragWidget::SetDragEnabled(bool bEnabled)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.SetDragEnabled");

	UPinchDragWidget_SetDragEnabled_Params params;
	params.bEnabled = bEnabled;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

struct FVector2D UPinchDragWidget::ScreenDeltaToParentLocal(class UWidget* Widget, const struct FVector2D& ScreenDelta)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.ScreenDeltaToParentLocal");

	UPinchDragWidget_ScreenDeltaToParentLocal_Params params;
	params.Widget = Widget;
	params.ScreenDelta = ScreenDelta;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void UPinchDragWidget::Reset()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.Reset");

	UPinchDragWidget_Reset_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

bool UPinchDragWidget::IsPinchEnabled()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.IsPinchEnabled");

	UPinchDragWidget_IsPinchEnabled_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool UPinchDragWidget::IsFirstPointIndex(const struct FPointerEvent& InPointerEvent)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.IsFirstPointIndex");

	UPinchDragWidget_IsFirstPointIndex_Params params;
	params.InPointerEvent = InPointerEvent;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

bool UPinchDragWidget::IsDragEnabled()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.IsDragEnabled");

	UPinchDragWidget_IsDragEnabled_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 

void USettingCustomPanel::SetSelectedImageOriginEffect()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.SetSelectedImageOriginEffect");

	USettingCustomPanel_SetSelectedImageOriginEffect_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void USettingCustomPanel::SetSelectedImageFlashEffect()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.SetSelectedImageFlashEffect");

	USettingCustomPanel_SetSelectedImageFlashEffect_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void USettingCustomPanel::SetDisplayState(ESCPDisplayState State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.SetDisplayState");

	USettingCustomPanel_SetDisplayState_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void USettingCustomPanel::OnTouchPreview()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.OnTouchPreview");

	USettingCustomPanel_OnTouchPreview_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

bool USettingCustomPanel::IsSquareFlashEffectAssetName(const struct FString& InAssetName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.IsSquareFlashEffectAssetName");

	USettingCustomPanel_IsSquareFlashEffectAssetName_Params params;
	params.InAssetName = InAssetName;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

bool USettingCustomPanel::IsCircleFlashEffectAssetName(const struct FString& InAssetName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.IsCircleFlashEffectAssetName");

	USettingCustomPanel_IsCircleFlashEffectAssetName_Params params;
	params.InAssetName = InAssetName;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

class UWidget* USettingCustomPanel::GetWidgetByType(class UWidget* RootWidget, class UClass* WidgetType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetWidgetByType");

	USettingCustomPanel_GetWidgetByType_Params params;
	params.RootWidget = RootWidget;
	params.WidgetType = WidgetType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UImage* USettingCustomPanel::GetSelectedImage()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetSelectedImage");

	USettingCustomPanel_GetSelectedImage_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UWidget* USettingCustomPanel::GetParentWidget()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetParentWidget");

	USettingCustomPanel_GetParentWidget_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

class UWidget* USettingCustomPanel::GetNamedWidgetFromOwner(const struct FString& Prefix)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetNamedWidgetFromOwner");

	USettingCustomPanel_GetNamedWidgetFromOwner_Params params;
	params.Prefix = Prefix;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

class UImage* USettingCustomPanel::GetInvalidImage()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetInvalidImage");

	USettingCustomPanel_GetInvalidImage_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FVector2D USettingCustomPanel::GetCenterPositionInScreenSpace(class UWidget* FullScreenWidget)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetCenterPositionInScreenSpace");

	USettingCustomPanel_GetCenterPositionInScreenSpace_Params params;
	params.FullScreenWidget = FullScreenWidget;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void USettingCustomPanel::FlashHighlight(float Seconds)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.FlashHighlight");

	USettingCustomPanel_FlashHighlight_Params params;
	params.Seconds = Seconds;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

struct FVector2D USettingCustomPanel::ConvertCenterPositionFromScreenSpace(class UWidget* FullScreenWidget, const struct FVector2D& SSPosition)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.ConvertCenterPositionFromScreenSpace");

	USettingCustomPanel_ConvertCenterPositionFromScreenSpace_Params params;
	params.FullScreenWidget = FullScreenWidget;
	params.SSPosition = SSPosition;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

