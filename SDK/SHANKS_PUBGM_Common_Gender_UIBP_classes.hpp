// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Gender_UIBP_C : public ULuaUserWidget
{
public:
	class UImage*                                      Image_1;                                                   
	class USizeBox*                                    SizeBox_1;                                                 

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Gender_UIBP.Common_Gender_UIBP_C");
		return pStaticClass;
	}

};


}

