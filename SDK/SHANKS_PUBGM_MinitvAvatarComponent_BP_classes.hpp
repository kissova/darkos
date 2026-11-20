// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UMinitvAvatarComponent_BP_C : public UPetAvatarComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass MinitvAvatarComponent_BP.MinitvAvatarComponent_BP_C");
		return pStaticClass;
	}


	void RayEquipItemById(int ID);
};


}

