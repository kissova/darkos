// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPeakGame_RankIntegralLevel_Style_Small_UIBP_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UCanvasPanel*                                Root;                                                      
	TEnumAsByte<EPeakGame_RankIntegralType>            RankIntegralType;                                          
	unsigned char                                      UnknownData00[0x7];                                        
	class UUserWidget*                                 RankIntegralUIBP;                                          
	struct FSlateColor                                 RankTextColor;                                             
	struct FSlateColor                                 RankTextShadowColor;                                       
	struct FSlateFontInfo                              RankFontInfo;                                              

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass PeakGame_RankIntegralLevel_Style_Small_UIBP.PeakGame_RankIntegralLevel_Style_Small_UIBP_C");
		return pStaticClass;
	}


	void GetPreviewPath(struct FString* BPPath);
	void ConstructPreviewSubItem();
	void PreConstruct(bool* IsDesignTime);
	void ExecuteUbergraph_PeakGame_RankIntegralLevel_Style_Small_UIBP(int EntryPoint);
};


}

