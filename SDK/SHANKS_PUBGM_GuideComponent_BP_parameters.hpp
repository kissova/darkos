// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UGuideComponent_BP_C_ShowGuideByStep_Params
{
};

 
struct UGuideComponent_BP_C_AddUIGuide_Params
{
	class UWidget*                                     Widget1;                                                   
	int                                                guildUI1;                                                  
	struct FVector2D                                   offset1;                                                   
	struct FVector2D                                   size1;                                                     
	int                                                childData1;                                                
};

 
struct UGuideComponent_BP_C_InitUIGuide_Params
{
};

 
struct UGuideComponent_BP_C_CreateGuideUI_Params
{
};

 
struct UGuideComponent_BP_C_ExecuteUbergraph_GuideComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

}

