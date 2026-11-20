// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UAITouchSelectComp_C::UpdateViewportLocalSize()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AITouchSelectComp.AITouchSelectComp_C.UpdateViewportLocalSize");

	UAITouchSelectComp_C_UpdateViewportLocalSize_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

struct FVector2D UAITouchSelectComp_C::ModifyTouchLoc(struct FGeometry* MyGeometry, struct FVector2D* TouchLoc)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AITouchSelectComp.AITouchSelectComp_C.ModifyTouchLoc");

	UAITouchSelectComp_C_ModifyTouchLoc_Params params;

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


 
 

void UAITouchSelectComp_C::ReceiveBeginPlay()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AITouchSelectComp.AITouchSelectComp_C.ReceiveBeginPlay");

	UAITouchSelectComp_C_ReceiveBeginPlay_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UAITouchSelectComp_C::OnTouchSelect(class AActor* SelectActor, const struct FVector2D& TouchLoc)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AITouchSelectComp.AITouchSelectComp_C.OnTouchSelect");

	UAITouchSelectComp_C_OnTouchSelect_Params params;
	params.SelectActor = SelectActor;
	params.TouchLoc = TouchLoc;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UAITouchSelectComp_C::OnViewPortChange(const struct FVector2D& OldViewportSize, const struct FVector2D& NewViewportSize)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AITouchSelectComp.AITouchSelectComp_C.OnViewPortChange");

	UAITouchSelectComp_C_OnViewPortChange_Params params;
	params.OldViewportSize = OldViewportSize;
	params.NewViewportSize = NewViewportSize;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UAITouchSelectComp_C::ExecuteUbergraph_AITouchSelectComp(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AITouchSelectComp.AITouchSelectComp_C.ExecuteUbergraph_AITouchSelectComp");

	UAITouchSelectComp_C_ExecuteUbergraph_AITouchSelectComp_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

