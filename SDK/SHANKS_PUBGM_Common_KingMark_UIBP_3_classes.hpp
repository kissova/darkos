// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_KingMark_UIBP_2_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UWidgetAnimation*                            anim_KingMark3;                                            
	class UWidgetAnimation*                            anim_KingMark2;                                            
	class UWidgetAnimation*                            anim_KingMark1;                                            
	class UWidgetAnimation*                            anim_KingMark0;                                            
	class UWidgetAnimation*                            Loop;                                                      
	class UImage*                                      Image_2;                                                   
	class UImage*                                      Image_3;                                                   
	class UImage*                                      Image_4;                                                   
	class UImage*                                      Image_Icon_Gray;                                           
	class USpineWidget*                                SpineWidget_High;                                          
	class UTextBlock*                                  TextBlock_1;                                               
	class UTextBlock*                                  TextBlock_2;                                               
	class UTextBlock*                                  TextBlock_3;                                               
	class UTextBlock*                                  TextBlock_4;                                               
	class UTextBlock*                                  TextBlock_5;                                               
	class UTextBlock*                                  TextBlock_6;                                               
	class UTextBlock*                                  TextBlock_7;                                               
	class UTextBlock*                                  TextBlock_Gray;                                            
	class UTextBlock*                                  TextBlock_Num04;                                           
	class UUIParticleEmitter*                          UIParticleEmitter_1;                                       
	class UUIParticleEmitter*                          UIParticleEmitter_2;                                       
	class UUIParticleEmitter*                          UIParticleEmitter_4;                                       
	class UWidgetSwitcher*                             WidgetSwitcher_Level;                                      

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_KingMark_UIBP_3.Common_KingMark_UIBP_2_C");
		return pStaticClass;
	}


	void Construct();
	void Tick(struct FGeometry* MyGeometry, float* InDeltaTime);
	void ExecuteUbergraph_Common_KingMark_UIBP_3(int EntryPoint);
};


}

