// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_Friend_UIBP_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            Anim_Glow;                                                 
	class UWidgetAnimation*                            Anim_Out;                                                  
	class UWidgetAnimation*                            Anim_Loop02;                                               
	class UWidgetAnimation*                            FadeOut;                                                   
	class UWidgetAnimation*                            FadeIn;                                                    
	class UWidgetAnimation*                            Anim_Prompt;                                               
	class UWidgetAnimation*                            Friend_Remind;                                             
	class UWidgetAnimation*                            Anim_loop;                                                 
	class UCommon_Avatar_Round_UIBP_C*                 Avatar01;                                                  
	class UCommon_Avatar_Round_UIBP_C*                 Avatar02;                                                  
	class UCommon_Avatar_Round_UIBP_C*                 Avatar03;                                                  
	class UButton*                                     Button_OnlinePlayers2;                                     
	class UButton*                                     Button_TeamQuick;                                          
	class UCanvasPanel*                                CanvasPanel_18;                                            
	class UCanvasPanel*                                CanvasPanel_BuddyTips;                                     
	class UCanvasPanel*                                CanvasPanel_CareTips;                                      
	class UCanvasPanel*                                CanvasPanel_FriendReddot;                                  
	class UCanvasPanel*                                CanvasPanel_Glow;                                          
	class UCanvasPanel*                                CanvasPanel_Home_Entrance;                                 
	class UCanvasPanel*                                CanvasPanel_Root;                                          
	class UCanvasPanel*                                CanvasPanel_TeamQucikTips;                                 
	class UCanvasPanel*                                CanvasPanel_TeamQuick;                                     
	class UImage*                                      Image_3;                                                   
	class UImage*                                      Image_5;                                                   
	class UImage*                                      Image_9;                                                   
	class UImage*                                      Image_Reddot;                                              
	class ULobby_Mid_Squad_Tips_UIBP_C*                Lobby_Mid_Squad_Tips_UIBP;                                 
	class ULobby_Mid_Tips_Friend_UIBP_C*               Lobby_Mid_Tips_Friend_UIBP_C_1;                            
	class ULoopScrollBox*                              LoopScrollBox_1;                                           
	class UTextBlock*                                  Text_Value;                                                
	class UTextBlock*                                  Text_Value01;                                              
	class UTextBlock*                                  Text_Value2;                                               
	class UTextBlock*                                  TextBlock_1;                                               
	class UTextBlock*                                  TextBlock_2;                                               
	class UUIParticleEmitter*                          UIParticleEmitter_27;                                      
	class UWidgetSwitcher*                             WidgetSwitcher_1;                                          
	class UWidgetSwitcher*                             WidgetSwitcher_TeamQuick;                                  
	struct FSlateColor                                 MentorWhiteColor;                                          
	struct FSlateColor                                 MentorYellowColor;                                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_Friend_UIBP.Lobby_Mid_Friend_UIBP_C");
		return pStaticClass;
	}

};


}

