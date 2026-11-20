// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_RoleInfo_IntimacyItem_UIBP_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UWidgetAnimation*                            Anim_Out;                                                  
	class UWidgetAnimation*                            Anim_in;                                                   
	class UCanvasPanel*                                CanvasPanel_Glow_2;                                        
	class UCanvasPanel*                                CanvasPanel_Glow_3;                                        
	class UCanvasPanel*                                CanvasPanel_Glow_4;                                        
	class UCanvasPanel*                                CanvasPanel_Glow_5;                                        
	class UCanvasPanel*                                CanvasPanel_Glow_6;                                        
	class UCanvasPanel*                                CanvasPanel_Glow_7;                                        
	class UImage*                                      Image_1;                                                   
	class UImage*                                      Image_Icon;                                                
	class UIntimacyItemChildItem_Glow01_UIBP_C*        IntimacyItemChildItem_Glow01_UIBP;                         
	class UIntimacyItemChildItem_Glow02_UIBP_C*        IntimacyItemChildItem_Glow02_UIBP;                         
	class UIntimacyItemChildItem_Glow03_UIBP_C*        IntimacyItemChildItem_Glow03_UIBP;                         
	class UIntimacyItemChildItem_Glow04_UIBP_C*        IntimacyItemChildItem_Glow04_UIBP;                         
	class UIntimacyItemChildItem_Glow05_UIBP_C*        IntimacyItemChildItem_Glow05_UIBP;                         
	class UIntimacyItemChildItem_Glow06_UIBP_C*        IntimacyItemChildItem_Glow06_UIBP;                         
	class UTextBlock*                                  TextBlock_Lv;                                              
	class UWidgetSwitcher*                             WidgetSwitcher_Glow;                                       
	struct FSlateColor                                 TextColor;                                                 
	ESlateVisibility                                   TextBG;                                                    

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_RoleInfo_IntimacyItem_UIBP.Lobby_RoleInfo_IntimacyItem_UIBP_C");
		return pStaticClass;
	}


	void PreConstruct(bool* IsDesignTime);
	void ExecuteUbergraph_Lobby_RoleInfo_IntimacyItem_UIBP(int EntryPoint);
};


}

