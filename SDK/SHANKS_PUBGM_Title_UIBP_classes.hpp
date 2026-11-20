// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UTitle_UIBP_C : public ULuaUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UCanvasPanel*                                CanvasPanelRoot;                                           

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Title_UIBP.Title_UIBP_C");
		return pStaticClass;
	}


	void SetAliasInfo(int ID, const struct FString& Title, const struct FString& Nation, float Available_len, int RankID);
	void PreConstruct(bool* IsDesignTime);
	void ExecuteUbergraph_Title_UIBP(int EntryPoint);
};


}

