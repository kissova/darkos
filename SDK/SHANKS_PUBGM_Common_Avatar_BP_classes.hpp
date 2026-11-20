// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCommon_Avatar_BP_C : public ULuaUserWidget
{
public:
	class UWidgetAnimation*                            Animation_chuo1chuo;                                       
	class UCanvasPanel*                                CanvasPanel_2;                                             
	struct FString                                     PlayerUID;                                                 
	class UButton*                                     buttonItem;                                                
	struct FScriptMulticastDelegate                    OnClickItemCallback;                                       
	struct FScriptMulticastDelegate                    DownloadSuc;                                               

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass Common_Avatar_BP.Common_Avatar_BP_C");
		return pStaticClass;
	}


	void SetAssetLoadingMethod(bool Async);
	void InitView(int Style, const struct FString& UID, const struct FString& iconUrl, int Gender, int frameLevel, int PlayerLevel, bool ignoreFrame, const struct FString& RoleNation);
	void DownloadSuc__DelegateSignature();
	void OnClickItemCallback__DelegateSignature(const struct FString& UID);
};


}

