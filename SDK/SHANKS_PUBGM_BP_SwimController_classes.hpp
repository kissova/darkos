// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_SwimController_C : public UPlayerSwimComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_SwimController.BP_SwimController_C");
		return pStaticClass;
	}


	void EnterWater_BluePrint();
	void BP_UnderWaterStateChanged(bool* bEnterWater);
	void ExecuteUbergraph_BP_SwimController(int EntryPoint);
};


}

