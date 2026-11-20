// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_AvatarPattern_Free_C : public UBP_AvatarPattern_Base_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_AvatarPattern_Free.BP_AvatarPattern_Free_C");
		return pStaticClass;
	}

};


}

