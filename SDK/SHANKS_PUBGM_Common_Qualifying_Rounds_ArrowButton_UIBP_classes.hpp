// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Qualifying_Rounds_ArrowButton_UIBP_C : public UUserWidget
{
public:
	class UButton*                                     Button_ArrowTips;                                          
	class UImage*                                      Image_Arrow_Effects;                                       
	class UImage*                                      Image_Arrow_Normal;                                        
	class UWidgetSwitcher*                             WidgetSwitcher_1;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Qualifying_Rounds_ArrowButton_UIBP.Common_Qualifying_Rounds_ArrowButton_UIBP_C");
		return pStaticClass;
	}

};


}

