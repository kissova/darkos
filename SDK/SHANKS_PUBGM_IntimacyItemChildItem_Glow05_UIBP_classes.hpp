// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UIntimacyItemChildItem_Glow05_UIBP_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            Time1;                                                     
	class UWidgetAnimation*                            Anim_in;                                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass IntimacyItemChildItem_Glow05_UIBP.IntimacyItemChildItem_Glow05_UIBP_C");
		return pStaticClass;
	}

};


}

