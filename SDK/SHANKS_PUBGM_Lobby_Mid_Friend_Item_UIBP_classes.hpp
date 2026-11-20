// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_Friend_Item_UIBP_C : public UUserWidget
{
public:
	class UButton*                                     Button_Del;                                                
	class UCommon_Avatar_BP_C*                         Common_Avatar_BP_C_1;                                      
	class UImage*                                      Image_5;                                                   
	class UImage*                                      Image_8;                                                   
	class USizeBox*                                    SizeBox_1;                                                 
	class USizeBox*                                    SizeBox_5;                                                 
	class UWidgetSwitcher*                             WidgetSwitcher_1;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_Friend_Item_UIBP.Lobby_Mid_Friend_Item_UIBP_C");
		return pStaticClass;
	}

};


}

