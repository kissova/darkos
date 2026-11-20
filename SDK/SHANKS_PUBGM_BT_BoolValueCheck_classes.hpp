// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBT_BoolValueCheck_C : public UBTDecorator_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FBlackboardKeySelector                      BoolKey;                                                   
	bool                                               TargetValue;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BT_BoolValueCheck.BT_BoolValueCheck_C");
		return pStaticClass;
	}


	bool PerformConditionCheck(class AActor** OwnerActor);
	void ExecuteUbergraph_BT_BoolValueCheck(int EntryPoint);
};


}

