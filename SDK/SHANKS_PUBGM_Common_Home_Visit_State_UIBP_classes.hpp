// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Home_Visit_State_UIBP_C : public ULuaUserWidget
{
public:
	class UImage*                                      Image_Icon;                                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Home_Visit_State_UIBP.Common_Home_Visit_State_UIBP_C");
		return pStaticClass;
	}

};


}

