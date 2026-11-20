// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UBP_AvatarPattern_Base_C_GetPatternNumTexturePath_Params
{
	int*                                               InNumID;                                                   
	struct FSoftObjectPath                             OutTexture1;                                               
	struct FSoftObjectPath                             OutTexture2;                                               
};

 
struct UBP_AvatarPattern_Base_C_SetCustomPattern_Implementation_Params
{
	class UMaterialInterface*                          InMaterial;                                                
	struct FSlotToMatPattern                           InMatPattern;                                              
};

 
struct UBP_AvatarPattern_Base_C_SetCustomPatternNum_Implementation_Params
{
	class UMaterialInterface*                          InMaterial;                                                
	struct FSlotToMatPattern                           InMatPattern;                                              
};

 
struct UBP_AvatarPattern_Base_C_SetCustomPatternDeffered_Params
{
	class UMaterialInterface**                         InMaterial;                                                
	struct FSlotToMatPattern*                          InMatPattern;                                              
};

 
struct UBP_AvatarPattern_Base_C_ExecuteUbergraph_BP_AvatarPattern_Base_Params
{
	int                                                EntryPoint;                                                
};

}

