// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_LightBoard_UIBP_C : public ULuaUserWidget
{
public:
	class UCanvasPanel*                                CanvasPanel_AttachBP;                                      
	class UTextBlock*                                  TextBlock_Name;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_LightBoard_UIBP.Common_LightBoard_UIBP_C");
		return pStaticClass;
	}

};


}

