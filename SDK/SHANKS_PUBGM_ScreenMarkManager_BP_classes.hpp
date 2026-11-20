// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UScreenMarkManager_BP_C : public UScreenMarkManager
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass ScreenMarkManager_BP.ScreenMarkManager_BP_C");
		return pStaticClass;
	}

};


}

