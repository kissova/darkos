// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UGameModeConfigComp_BP_C : public UGameModeConfigComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass GameModeConfigComp_BP.GameModeConfigComp_BP_C");
		return pStaticClass;
	}

};


}

