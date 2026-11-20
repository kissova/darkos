// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_KingMark_UIBP_C : public UUserWidget
{
public:
	class UImage*                                      Image_Icon_Bg;                                             
	class UTextBlock*                                  TextBlock_Num;                                             

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_KingMark_UIBP.Common_KingMark_UIBP_C");
		return pStaticClass;
	}

};


}

