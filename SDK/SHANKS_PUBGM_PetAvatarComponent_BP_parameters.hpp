// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UPetAvatarComponent_BP_C_GetFakeAvatarHandleItem_Params
{
	int*                                               InSlotID;                                                  
	int*                                               InItemID;                                                  
	int*                                               AdditionalItemID;                                          
	int                                                ReturnValue;                                               
};

 
struct UPetAvatarComponent_BP_C_PetHasEquippedItem_Params
{
	int                                                ID;                                                        
	bool                                               Out;                                                       
};

 
struct UPetAvatarComponent_BP_C_PetUnequipItemById_Params
{
	int                                                ID;                                                        
};

 
struct UPetAvatarComponent_BP_C_PetEquipItemById_Params
{
	int                                                ID;                                                        
};

}

