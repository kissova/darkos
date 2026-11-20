// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBattleItemHandle_WeapAttachment_SpecialScope_C : public UBattleItemHandle_WeapAttachment_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BattleItemHandle_WeapAttachment_SpecialScope.BattleItemHandle_WeapAttachment_SpecialScope_C");
		return pStaticClass;
	}


	void GetFov(float* FOV);
};


}

