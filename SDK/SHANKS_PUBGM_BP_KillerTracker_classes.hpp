// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_KillerTracker_C : public AKillerTracker
{
public:
	class UCameraComponent*                            Camera;                                                    
	class USpringArmComponent*                         SpringArm;                                                 
	class USceneComponent*                             DefaultSceneRoot;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_KillerTracker.BP_KillerTracker_C");
		return pStaticClass;
	}


	void UserConstructionScript();
};


}

