// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void UBP_TouchSelectComponent_C::RefreshViewportSize(const struct FVector2D& OldSize, const struct FVector2D& NewSize)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_TouchSelectComponent.BP_TouchSelectComponent_C.RefreshViewportSize");

	UBP_TouchSelectComponent_C_RefreshViewportSize_Params params;
	params.OldSize = OldSize;
	params.NewSize = NewSize;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

struct FVector2D UBP_TouchSelectComponent_C::ModifyTouchLoc(struct FGeometry* MyGeometry, struct FVector2D* TouchLoc)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_TouchSelectComponent.BP_TouchSelectComponent_C.ModifyTouchLoc");

	UBP_TouchSelectComponent_C_ModifyTouchLoc_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (MyGeometry != nullptr)
		*MyGeometry = params.MyGeometry;
	if (TouchLoc != nullptr)
		*TouchLoc = params.TouchLoc;

	return params.ReturnValue;
}


 
 

void UBP_TouchSelectComponent_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_TouchSelectComponent.BP_TouchSelectComponent_C.ReceiveBeginPlay");

	UBP_TouchSelectComponent_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_TouchSelectComponent_C::ExecuteUbergraph_BP_TouchSelectComponent(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_TouchSelectComponent.BP_TouchSelectComponent_C.ExecuteUbergraph_BP_TouchSelectComponent");

	UBP_TouchSelectComponent_C_ExecuteUbergraph_BP_TouchSelectComponent_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

