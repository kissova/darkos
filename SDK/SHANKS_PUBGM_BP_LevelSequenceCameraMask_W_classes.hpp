// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_LevelSequenceCameraMask_W_C : public UUserWidget
{
public:
	class UWidgetAnimation*                            FadeOut;                                                   
	class UCanvasPanel*                                CanvasPanel_1;                                             
	class UImage*                                      Image_1;                                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass BP_LevelSequenceCameraMask_W.BP_LevelSequenceCameraMask_W_C");
		return pStaticClass;
	}

};


}

