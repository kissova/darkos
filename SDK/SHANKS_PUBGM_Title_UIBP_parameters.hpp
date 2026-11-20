// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UTitle_UIBP_C_SetAliasInfo_Params
{
	int                                                ID;                                                        
	struct FString                                     Title;                                                     
	struct FString                                     Nation;                                                    
	float                                              Available_len;                                             
	int                                                RankID;                                                    
};

 
struct UTitle_UIBP_C_PreConstruct_Params
{
	bool*                                              IsDesignTime;                                              
};

 
struct UTitle_UIBP_C_ExecuteUbergraph_Title_UIBP_Params
{
	int                                                EntryPoint;                                                
};

}

