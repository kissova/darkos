// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 

void UCommon_KingMark_UIBP_2_C::Construct()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Common_KingMark_UIBP_3.Common_KingMark_UIBP_2_C.Construct");

	UCommon_KingMark_UIBP_2_C_Construct_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UCommon_KingMark_UIBP_2_C::Tick(struct FGeometry* MyGeometry, float* InDeltaTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Common_KingMark_UIBP_3.Common_KingMark_UIBP_2_C.Tick");

	UCommon_KingMark_UIBP_2_C_Tick_Params params;
	params.MyGeometry = MyGeometry;
	params.InDeltaTime = InDeltaTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UCommon_KingMark_UIBP_2_C::ExecuteUbergraph_Common_KingMark_UIBP_3(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function Common_KingMark_UIBP_3.Common_KingMark_UIBP_2_C.ExecuteUbergraph_Common_KingMark_UIBP_3");

	UCommon_KingMark_UIBP_2_C_ExecuteUbergraph_Common_KingMark_UIBP_3_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

