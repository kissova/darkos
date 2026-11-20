// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_AvatarColor_Base_C : public UBackpackAvatarItemColor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	TArray<struct FName>                               MaskColorNames;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_AvatarColor_Base.BP_AvatarColor_Base_C");
		return pStaticClass;
	}


	void SetCustomColorDeffered(class UMaterialInterface** InMaterial, struct FSlotToMatColor* InMatColor);
	void ExecuteUbergraph_BP_AvatarColor_Base(int EntryPoint);
};


}

