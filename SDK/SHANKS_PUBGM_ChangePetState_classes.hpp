// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UChangePetState_C : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	TEnumAsByte<EPetState>                             State;                                                     
	TEnumAsByte<EPawnStateChangeType>                  ChangeType;                                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass ChangePetState.ChangePetState_C");
		return pStaticClass;
	}


	void ReceiveExecuteAI(class AAIController** OwnerController, class APawn** ControlledPawn);
	void ExecuteUbergraph_ChangePetState(int EntryPoint);
};


}

