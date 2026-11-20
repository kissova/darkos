// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct URankSmall_Integral_UIBP_C_SetRankText_Params
{
	struct FSlateColor                                 Color;                                                     
	struct FSlateColor                                 ShadowColor;                                               
	struct FSlateFontInfo                              FontInfo;                                                  
};

 
struct URankSmall_Integral_UIBP_C_SetRankIntegral_Params
{
	struct FBP_STRUCT_RankIntegralLevel_type           RankIntegralLevel_Info;                                    
	bool                                               isStarOpen;                                                
};

 
struct URankSmall_Integral_UIBP_C_ExecuteUbergraph_RankSmall_Integral_UIBP_Params
{
	int                                                EntryPoint;                                                
};

}

