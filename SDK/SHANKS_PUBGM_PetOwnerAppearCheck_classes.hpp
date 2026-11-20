// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetOwnerAppearCheck_C : public UBTDecorator_BlueprintBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetOwnerAppearCheck.PetOwnerAppearCheck_C");
		return pStaticClass;
	}


	bool PerformConditionCheckAI(class AAIController** OwnerController, class APawn** ControlledPawn);
};


}

