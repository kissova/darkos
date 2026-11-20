// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAITouchSelectComp_C : public USTTouchSelectComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FVector2D                                   ViewportLocalSize;                                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass AITouchSelectComp.AITouchSelectComp_C");
		return pStaticClass;
	}


	void UpdateViewportLocalSize();
	struct FVector2D ModifyTouchLoc(struct FGeometry* MyGeometry, struct FVector2D* TouchLoc);
	void ReceiveBeginPlay();
	void OnTouchSelect(class AActor* SelectActor, const struct FVector2D& TouchLoc);
	void OnViewPortChange(const struct FVector2D& OldViewportSize, const struct FVector2D& NewViewportSize);
	void ExecuteUbergraph_AITouchSelectComp(int EntryPoint);
};


}

