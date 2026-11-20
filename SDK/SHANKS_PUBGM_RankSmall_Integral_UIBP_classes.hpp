// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class URankSmall_Integral_UIBP_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UImage*                                      Image_Icon;                                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass RankSmall_Integral_UIBP.RankSmall_Integral_UIBP_C");
		return pStaticClass;
	}


	void SetRankText(const struct FSlateColor& Color, const struct FSlateColor& ShadowColor, const struct FSlateFontInfo& FontInfo);
	void SetRankIntegral(const struct FBP_STRUCT_RankIntegralLevel_type& RankIntegralLevel_Info, bool isStarOpen);
	void ExecuteUbergraph_RankSmall_Integral_UIBP(int EntryPoint);
};


}

