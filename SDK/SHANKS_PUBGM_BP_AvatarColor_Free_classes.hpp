// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_AvatarColor_Free_C : public UBP_AvatarColor_Base_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_AvatarColor_Free.BP_AvatarColor_Free_C");
		return pStaticClass;
	}

};


}

