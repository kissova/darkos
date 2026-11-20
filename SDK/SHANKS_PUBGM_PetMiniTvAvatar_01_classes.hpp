// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetMiniTvAvatar_01_C : public UPetAvatarHandle
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetMiniTvAvatar_01.PetMiniTvAvatar_01_C");
		return pStaticClass;
	}

};


}

