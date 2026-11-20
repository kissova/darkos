// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_GameMode_MainCity_C : public AMainCityGameMode
{
public:
	class USceneComponent*                             DefaultSceneRoot;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_GameMode_MainCity.BP_GameMode_MainCity_C");
		return pStaticClass;
	}


	void UserConstructionScript();
};


}

