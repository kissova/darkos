// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Avatar_Collect_Level_UIBP_C : public UUserWidget
{
public:
	class UCommon_Collect_Level_DynamicLoading_UIBP_C* Common_Collect_Level_DynamicLoading_UIBP;                  

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Avatar_Collect_Level_UIBP.Common_Avatar_Collect_Level_UIBP_C");
		return pStaticClass;
	}

};


}

