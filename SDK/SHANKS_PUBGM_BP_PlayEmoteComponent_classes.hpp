// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_PlayEmoteComponent_C : public UPlayEmoteComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_PlayEmoteComponent.BP_PlayEmoteComponent_C");
		return pStaticClass;
	}

};


}

