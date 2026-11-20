// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UReturnActivity_Entrance_Item_C : public UUserWidget
{
public:
	class UButton*                                     Button_1;                                                  
	class UReddot_Anchor_C*                            Reddot_Anchor_1;                                           
	class UTextBlock*                                  Text_Return;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass ReturnActivity_Entrance_Item.ReturnActivity_Entrance_Item_C");
		return pStaticClass;
	}

};


}

