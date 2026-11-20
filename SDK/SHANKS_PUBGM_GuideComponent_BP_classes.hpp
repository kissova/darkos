// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UGuideComponent_BP_C : public UGuideComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	int                                                guideStep;                                                 
	bool                                               Enabled;                                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass GuideComponent_BP.GuideComponent_BP_C");
		return pStaticClass;
	}


	void ShowGuideByStep();
	void AddUIGuide(class UWidget* Widget1, int guildUI1, const struct FVector2D& offset1, const struct FVector2D& size1, int childData1);
	void InitUIGuide();
	void CreateGuideUI();
	void ExecuteUbergraph_GuideComponent_BP(int EntryPoint);
};


}

