// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetEntityComponent_BP_C : public UPetEntityComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetEntityComponent_BP.PetEntityComponent_BP_C");
		return pStaticClass;
	}


	struct FPetAttachInfo GetAttachInfoFromTable(struct FFixPetAttachInfo* Info);
};


}

