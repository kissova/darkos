// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Collect_Level_DynamicLoading_UIBP_C : public ULuaUserWidget
{
public:
	class UCanvasPanel*                                CanvasPanel_CollectLevelItem;                              
	class UCanvasPanel*                                CanvasPanel_DownLoading;                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Collect_Level_DynamicLoading_UIBP.Common_Collect_Level_DynamicLoading_UIBP_C");
		return pStaticClass;
	}

};


}

