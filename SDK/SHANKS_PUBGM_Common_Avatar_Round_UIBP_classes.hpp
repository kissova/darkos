// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Avatar_Round_UIBP_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UWidgetAnimation*                            FadeOut;                                                   
	class UWidgetAnimation*                            FadeIn;                                                    
	class UCommon_Avatar_BP_C*                         Common_Avatar_BP;                                          
	class UScaleBox*                                   ScaleBox_1;                                                
	class USizeBox*                                    SizeBox_1;                                                 
	float                                              Width;                                                     
	float                                              Height;                                                    

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Avatar_Round_UIBP.Common_Avatar_Round_UIBP_C");
		return pStaticClass;
	}


	void PreConstruct(bool* IsDesignTime);
	void ExecuteUbergraph_Common_Avatar_Round_UIBP(int EntryPoint);
};


}

