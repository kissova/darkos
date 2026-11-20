// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Collect_TreasureLvTab_Item_UIBP_C : public UUserWidget
{
public:
	class UButton*                                     Button_Treasure;                                           
	class UTextBlock*                                  TextBlock_Lv;                                              

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Collect_TreasureLvTab_Item_UIBP.Lobby_Collect_TreasureLvTab_Item_UIBP_C");
		return pStaticClass;
	}

};


}

