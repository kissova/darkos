// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetSpecifiedAnim_C : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FName                                       AnimationID;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetSpecifiedAnim.PetSpecifiedAnim_C");
		return pStaticClass;
	}


	void ReceiveExecuteAI(class AAIController** OwnerController, class APawn** ControlledPawn);
	void ExecuteUbergraph_PetSpecifiedAnim(int EntryPoint);
};


}

