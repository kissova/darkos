// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_NewFakePlayerAIC_C : public ANewFakePlayerAIController
{
public:
	class UBP_VehicleAIUserComp_C*                     BP_VehicleAIUserComp;                                      
	class UAIOrderComponent*                           AIOrder;                                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_NewFakePlayerAIC.BP_NewFakePlayerAIC_C");
		return pStaticClass;
	}


	void UserConstructionScript();
};


}

