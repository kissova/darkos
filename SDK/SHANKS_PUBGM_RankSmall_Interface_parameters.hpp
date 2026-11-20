// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct URankSmall_Interface_C_SetRankText_Params
{
	struct FSlateColor                                 Color;                                                     
	struct FSlateColor                                 ShadowColor;                                               
	struct FSlateFontInfo                              FontInfo;                                                  
};

 
struct URankSmall_Interface_C_SetRankIntegral_Params
{
	struct FBP_STRUCT_RankIntegralLevel_type           RankIntegralLevel_Info;                                    
	bool                                               isStarOpen;                                                
};

}

