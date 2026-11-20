// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_Message_UIBP_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UWidgetAnimation*                            FadeIn;                                                    
	class UWidgetAnimation*                            Anim_loop;                                                 
	class UImage*                                      _18_;                                                      
	class UButton*                                     Button_Observe;                                            
	class UCanvasPanel*                                CanvasPanel_9;                                             
	class UCanvasPanel*                                CanvasPanel_ButtonList;                                    
	class UCanvasPanel*                                CanvasPanel_Home_Entrance;                                 
	class UCanvasPanel*                                CanvasPanel_Regression;                                    
	class UCanvasPanel*                                CanvasPanel_TeamPlatformEntry;                             
	class UCanvasPanel*                                CanvasPanel_TeamPlatformTips;                              
	class UCanvasPanel*                                CanvasPanel_TreasureLvTab;                                 
	class ULobby_Collect_TreasureLvTab_Item_UIBP_C*    Collect_TreasureLvTab_Item_UIBP;                           
	class UCommon_Avatar_BP_C*                         Common_Avatar_BP;                                          
	class UImage*                                      Image_1;                                                   
	class UImage*                                      Image_12;                                                  
	class UReddot_Anchor_Item05_C*                     Image_Avatar_New;                                          
	class UReddot_Anchor_Item05_C*                     Image_Home_Guide_New;                                      
	class UCanvasPanel*                                NewbieGuide_TeamPlatformEntry;                             
	class USizeBox*                                    SizeBox_CrazyWeekend;                                      
	class USizeBox*                                    SizeBox_TeamPlatformEntry;                                 
	class UTextBlock*                                  TextBlock_1;                                               
	class UTextBlock*                                  TextBlock_2;                                               
	class UTextBlock*                                  TextBlock_NickName;                                        
	struct FSlateColor                                 MentorWhiteColor;                                          
	struct FSlateColor                                 MentorYellowColor;                                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_Message_UIBP.Lobby_Mid_Message_UIBP_C");
		return pStaticClass;
	}


	void PreConstruct(bool* IsDesignTime);
	void ExecuteUbergraph_Lobby_Mid_Message_UIBP(int EntryPoint);
};


}

