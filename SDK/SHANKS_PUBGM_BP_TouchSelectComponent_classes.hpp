// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_TouchSelectComponent_C : public USTTouchSelectComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FVector2D                                   ViewportLocalSize;                                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_TouchSelectComponent.BP_TouchSelectComponent_C");
		return pStaticClass;
	}


	void RefreshViewportSize(const struct FVector2D& OldSize, const struct FVector2D& NewSize);
	struct FVector2D ModifyTouchLoc(struct FGeometry* MyGeometry, struct FVector2D* TouchLoc);
	void ReceiveBeginPlay();
	void ExecuteUbergraph_BP_TouchSelectComponent(int EntryPoint);
};


}

