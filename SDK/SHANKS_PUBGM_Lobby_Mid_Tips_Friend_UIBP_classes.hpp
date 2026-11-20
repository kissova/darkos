// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobby_Mid_Tips_Friend_UIBP_C : public UUserWidget
{
public:
	class UTextBlock*                                  Text_Friend_Tips;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Lobby_Mid_Tips_Friend_UIBP.Lobby_Mid_Tips_Friend_UIBP_C");
		return pStaticClass;
	}

};


}

