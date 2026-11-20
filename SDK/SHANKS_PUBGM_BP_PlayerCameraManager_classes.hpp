// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_PlayerCameraManager_C : public ASTPlayerCameraManager
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_PlayerCameraManager.BP_PlayerCameraManager_C");
		return pStaticClass;
	}

};


}

