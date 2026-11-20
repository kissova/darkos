// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Avatar_All_UIBP_C : public UUserWidget
{
public:
	class UButton*                                     Button_Avatar;                                             
	class UCanvasPanel*                                CanvasPanel_Ban;                                           
	class UCanvasPanel*                                CanvasPanel_CollectLevel;                                  
	class UCanvasPanel*                                GIF_Avatar;                                                
	class UCanvasPanel*                                GIF_frame;                                                 
	class UImage*                                      Image_2;                                                   
	class UImage*                                      Image_Avatar;                                              
	class UImage*                                      Image_frame;                                               
	class UImage*                                      Image_Icon_Default;                                        
	class UImage*                                      Image_medal;                                               
	class UImage*                                      Image_roleinfo_nation;                                     
	class UTextBlock*                                  TextBlock_PlayerLevel;                                     

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Avatar_All_UIBP.Common_Avatar_All_UIBP_C");
		return pStaticClass;
	}

};


}

