// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_Squad_Tips_UIBP_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            Anim_Out;                                                  
	class UWidgetAnimation*                            Anim_in;                                                   
	class UButton*                                     Button_HotZone;                                            
	class UCanvasPanel*                                CanvasPanel_16;                                            
	class UCanvasPanel*                                CanvasPanel_Attach;                                        
	class UCanvasPanel*                                CanvasPanel_Card;                                          
	class UCanvasPanel*                                CanvasPanel_Tips;                                          
	class UImage*                                      Image_Arrow3;                                              
	class UImage*                                      Image_Line3;                                               
	class UCanvasPanel*                                Panel_Award;                                               
	class UReddot_Anchor_Item05_C*                     Reddot_Anchor_Item05;                                      
	class UCanvasPanel*                                SocialIsland_Tips;                                         
	class UTextBlock*                                  TextBlock_1;                                               
	class UTextBlock*                                  TextBlock_2;                                               
	class UTextBlock*                                  TextBlock_3;                                               
	class UWidgetSwitcher*                             WidgetSwitcher_State;                                      

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_Squad_Tips_UIBP.Lobby_Mid_Squad_Tips_UIBP_C");
		return pStaticClass;
	}

};


}

