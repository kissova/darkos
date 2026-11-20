// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class AHalloween_CarPosition_C : public AActor
{
public:
	class UArrowComponent*                             Arrow;                                                     
	class USceneComponent*                             DefaultSceneRoot;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass Halloween_CarPosition.Halloween_CarPosition_C");
		return pStaticClass;
	}


	void UserConstructionScript();
};


}

