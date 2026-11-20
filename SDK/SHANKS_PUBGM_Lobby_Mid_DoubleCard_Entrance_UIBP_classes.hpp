// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_DoubleCard_Entrance_UIBP_C : public UUAEUserWidget
{
public:
	class UWidgetAnimation*                            Animation_DisAppear;                                       
	class UWidgetAnimation*                            Animation_Appear;                                          
	class UButton*                                     Button_1;                                                  
	class UButton*                                     Button_DoubleCardShowTips;                                 
	class UButton*                                     Button_Gift;                                               
	class UButton*                                     Button_Qualifying;                                         
	class UButton*                                     Button_Veteran;                                            
	class UCanvasPanel*                                Canvas_ShieldInfpTips;                                     
	class UCanvasPanel*                                CanvasPanel_ArrowTips;                                     
	class UCanvasPanel*                                CanvasPanel_DoubleCard;                                    
	class UCommon_Qualifying_Rounds_ArrowButton_UIBP_C* Common_Qualifying_Rounds_ArrowButton_UIBP;                 
	class UGridPanel*                                  GridPanel_2;                                               
	class UImage*                                      Image_24;                                                  
	class UImage*                                      Image_25;                                                  
	class UImage*                                      Image_60;                                                  
	class UImage*                                      Image_DoubleIcon;                                          
	class UImage*                                      Image_ScrollBg;                                            
	class UCanvasPanel*                                ScrollPanel;                                               
	class UTextBlock*                                  ScrollText;                                                
	class UTextBlock*                                  TextBlock_CardNum;                                         
	class UCanvasPanel*                                UIRoot;                                                    
	class UWidgetSwitcher*                             WidgetSwitcher_DoubleCardShowTips;                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_DoubleCard_Entrance_UIBP.Lobby_Mid_DoubleCard_Entrance_UIBP_C");
		return pStaticClass;
	}

};


}

