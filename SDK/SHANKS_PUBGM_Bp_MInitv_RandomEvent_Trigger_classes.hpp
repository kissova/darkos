// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABp_MInitv_RandomEvent_Trigger_C : public AActor
{
public:
	class UBoxComponent*                               Box;                                                       
	struct FString                                     EventName;                                                 

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass Bp_MInitv_RandomEvent_Trigger.Bp_MInitv_RandomEvent_Trigger_C");
		return pStaticClass;
	}


	void UserConstructionScript();
};


}

