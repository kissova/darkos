// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 

void URankSmall_Interface_C::SetRankText(const struct FSlateColor& Color, const struct FSlateColor& ShadowColor, const struct FSlateFontInfo& FontInfo)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function RankSmall_Interface.RankSmall_Interface_C.SetRankText");

	URankSmall_Interface_C_SetRankText_Params params;
	params.Color = Color;
	params.ShadowColor = ShadowColor;
	params.FontInfo = FontInfo;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void URankSmall_Interface_C::SetRankIntegral(const struct FBP_STRUCT_RankIntegralLevel_type& RankIntegralLevel_Info, bool isStarOpen)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function RankSmall_Interface.RankSmall_Interface_C.SetRankIntegral");

	URankSmall_Interface_C_SetRankIntegral_Params params;
	params.RankIntegralLevel_Info = RankIntegralLevel_Info;
	params.isStarOpen = isStarOpen;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

