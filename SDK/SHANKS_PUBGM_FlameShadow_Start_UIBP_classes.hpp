// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UFlameShadow_Start_UIBP_C : public UUserWidget
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass FlameShadow_Start_UIBP.FlameShadow_Start_UIBP_C");
		return pStaticClass;
	}

};


}

