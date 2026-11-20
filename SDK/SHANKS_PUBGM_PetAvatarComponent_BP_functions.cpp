// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 
 

int UPetAvatarComponent_BP_C::GetFakeAvatarHandleItem(int* InSlotID, int* InItemID, int* AdditionalItemID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetAvatarComponent_BP.PetAvatarComponent_BP_C.GetFakeAvatarHandleItem");

	UPetAvatarComponent_BP_C_GetFakeAvatarHandleItem_Params params;
	params.InSlotID = InSlotID;
	params.InItemID = InItemID;
	params.AdditionalItemID = AdditionalItemID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

void UPetAvatarComponent_BP_C::PetHasEquippedItem(int ID, bool* Out)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetAvatarComponent_BP.PetAvatarComponent_BP_C.PetHasEquippedItem");

	UPetAvatarComponent_BP_C_PetHasEquippedItem_Params params;
	params.ID = ID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Out != nullptr)
		*Out = params.Out;
}


 
 
 
 

void UPetAvatarComponent_BP_C::PetUnequipItemById(int ID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetAvatarComponent_BP.PetAvatarComponent_BP_C.PetUnequipItemById");

	UPetAvatarComponent_BP_C_PetUnequipItemById_Params params;
	params.ID = ID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UPetAvatarComponent_BP_C::PetEquipItemById(int ID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PetAvatarComponent_BP.PetAvatarComponent_BP_C.PetEquipItemById");

	UPetAvatarComponent_BP_C_PetEquipItemById_Params params;
	params.ID = ID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

