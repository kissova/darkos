// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_TeamPlatform_Entry_C : public UUserWidget
{
public:
	class UBorder*                                     Border_3;                                                  
	class UButton*                                     Button_TeamUp;                                             
	class UCanvasPanel*                                CanvasPanel_32;                                            
	class UImage*                                      Image_bg;                                                  
	class UImage*                                      Image_Effect;                                              
	class UImage*                                      Image_Effect2;                                             
	class UImage*                                      Image_New;                                                 
	class UReddot_Anchor_C*                            Reddot_Anchor;                                             
	class UTextBlock*                                  TextBlock_Team;                                            
	class UWidgetSwitcher*                             WidgetSwitcher_ImageTeamUp;                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_TeamPlatform_Entry.Lobby_TeamPlatform_Entry_C");
		return pStaticClass;
	}

};


}

