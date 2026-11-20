// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetAvatarComponent_BP_C : public UPetAvatarComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetAvatarComponent_BP.PetAvatarComponent_BP_C");
		return pStaticClass;
	}


	int GetFakeAvatarHandleItem(int* InSlotID, int* InItemID, int* AdditionalItemID);
	void PetHasEquippedItem(int ID, bool* Out);
	void PetUnequipItemById(int ID);
	void PetEquipItemById(int ID);
};


}

