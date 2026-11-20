// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetSwimInterface_C : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetSwimInterface.PetSwimInterface_C");
		return pStaticClass;
	}


	void ISetLeaveSwimMode();
	void ISetEnterSwimMode(float WaterSurface);
};


}

