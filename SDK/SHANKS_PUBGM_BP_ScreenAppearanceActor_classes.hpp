// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_ScreenAppearanceActor_C : public AScreenAppearanceActor
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_ScreenAppearanceActor.BP_ScreenAppearanceActor_C");
		return pStaticClass;
	}

};


}

