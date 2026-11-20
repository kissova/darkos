// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class USmartAssistant_RobotTips_UIBP_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UWidgetAnimation*                            Anim_TipsOut;                                              
	class UWidgetAnimation*                            Anim_TipsIn;                                               
	class UBorder*                                     Border_3;                                                  
	class UButton*                                     Button_5;                                                  
	class UHorizontalBox*                              HorizontalBox_1;                                           
	class USpineWidget*                                SpineWidget_1;                                             
	class UUTRichTextBlock*                            UTRichTextBlock_1;                                         
	class UWidgetSwitcher*                             WidgetSwitcher_1;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass SmartAssistant_RobotTips_UIBP.SmartAssistant_RobotTips_UIBP_C");
		return pStaticClass;
	}


	void Tick(struct FGeometry* MyGeometry, float* InDeltaTime);
	void ExecuteUbergraph_SmartAssistant_RobotTips_UIBP(int EntryPoint);
};


}

