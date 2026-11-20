// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_PlayerTransformComponent_C : public ULuaActorComponent
{
public:
	struct FString                                     TransformDataComponentPath;                                
	bool                                               bLocalBindCameraSwitch;                                    

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_PlayerTransformComponent.BP_PlayerTransformComponent_C");
		return pStaticClass;
	}

};


}

