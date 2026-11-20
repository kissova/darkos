// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_ChangeWearingComp_C : public UChangeWearingComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_ChangeWearingComp.BP_ChangeWearingComp_C");
		return pStaticClass;
	}

};


}

