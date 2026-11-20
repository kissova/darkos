// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UClickEffect_DefaultEffect_UIBP_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            click;                                                     
	class UCanvasPanel*                                CanvasPanel_Effect;                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass ClickEffect_DefaultEffect_UIBP.ClickEffect_DefaultEffect_UIBP_C");
		return pStaticClass;
	}

};


}

