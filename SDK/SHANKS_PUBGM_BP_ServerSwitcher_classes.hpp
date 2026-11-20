// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_ServerSwitcher_C : public UServerSwitchComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_ServerSwitcher.BP_ServerSwitcher_C");
		return pStaticClass;
	}


	void ReceiveBeginPlay();
	void CustomEvent_1(bool BoolValue);
	void ExecuteUbergraph_BP_ServerSwitcher(int EntryPoint);
};


}

