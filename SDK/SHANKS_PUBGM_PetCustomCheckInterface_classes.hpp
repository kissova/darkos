// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetCustomCheckInterface_C : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetCustomCheckInterface.PetCustomCheckInterface_C");
		return pStaticClass;
	}


	void NotAllowAppear(bool* Out);
};


}

