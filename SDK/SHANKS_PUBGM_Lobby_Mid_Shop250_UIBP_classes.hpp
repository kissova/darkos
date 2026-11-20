// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_Shop250_UIBP_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            Anima_RP100;                                               
	class UWidgetAnimation*                            Anima_Shop;                                                
	class UWidgetAnimation*                            Anima_Supply;                                              
	class UWidgetAnimation*                            Anima_RP;                                                  
	class UWidgetAnimation*                            Animation_Hand_Loop;                                       
	class UWidgetAnimation*                            Animation_Mask;                                            
	class UWidgetAnimation*                            eff_ShopStar;                                              
	class UWidgetAnimation*                            RP_Warning;                                                
	class UButton*                                     Button_Shop;                                               
	class UButton*                                     Button_Supply;                                             
	class UButton*                                     Button_Supply_JK;                                          
	class UCanvasPanel*                                CanvasPanel_CRATES;                                        
	class UCanvasPanel*                                CanvasPanel_Reddot;                                        
	class UCanvasPanel*                                CanvasPanel_Shop;                                          
	class UCanvasPanel*                                CanvasPanel_Supply;                                        
	class UCanvasPanel*                                Effect_Shop;                                               
	class UCanvasPanel*                                Effect_Supply;                                             
	class UImage*                                      Image_3;                                                   
	class UImage*                                      Image_70;                                                  
	class UImage*                                      Image_JKSupReddot;                                         
	class UImage*                                      Image_Shop;                                                
	class UImage*                                      Image_Shop_KJ;                                             
	class UImage*                                      Image_Star;                                                
	class UImage*                                      Image_Supply_JK;                                           
	class UImage*                                      IsShowPrime;                                               
	class UReddot_Anchor_Item12_C*                     Reddot_Anchor_Item12;                                      
	class UCanvasPanel*                                Shop_International;                                        
	class UCanvasPanel*                                Shop_JK;                                                   
	class UReddot_Anchor_C*                            Store_Reddot_Anchor;                                       
	class UReddot_Anchor_C*                            Sup_Reddot_Anchor;                                         
	class UCanvasPanel*                                Supply_JK;                                                 
	class UWidgetSwitcher*                             WidgetSwitcher_Shop;                                       
	class UWidgetSwitcher*                             WidgetSwitcher_Supply;                                     

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_Shop250_UIBP.Lobby_Mid_Shop250_UIBP_C");
		return pStaticClass;
	}

};


}

