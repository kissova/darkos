// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 

void USmartAssistant_RobotTips_UIBP_C::Tick(struct FGeometry* MyGeometry, float* InDeltaTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function SmartAssistant_RobotTips_UIBP.SmartAssistant_RobotTips_UIBP_C.Tick");

	USmartAssistant_RobotTips_UIBP_C_Tick_Params params;
	params.MyGeometry = MyGeometry;
	params.InDeltaTime = InDeltaTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void USmartAssistant_RobotTips_UIBP_C::ExecuteUbergraph_SmartAssistant_RobotTips_UIBP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function SmartAssistant_RobotTips_UIBP.SmartAssistant_RobotTips_UIBP_C.ExecuteUbergraph_SmartAssistant_RobotTips_UIBP");

	USmartAssistant_RobotTips_UIBP_C_ExecuteUbergraph_SmartAssistant_RobotTips_UIBP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

