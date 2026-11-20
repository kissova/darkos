// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UClickEffect_UIBP_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            NewAnimation_Kick;                                         
	class UCanvasPanel*                                CanvasPanel_Content;                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass ClickEffect_UIBP.ClickEffect_UIBP_C");
		return pStaticClass;
	}

};


}

