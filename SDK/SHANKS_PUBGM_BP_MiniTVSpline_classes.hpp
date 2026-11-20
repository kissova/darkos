// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_MiniTVSpline_C : public AActor
{
public:
	class USplineComponent*                            Spline;                                                    
	bool                                               MoveActor;                                                 

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_MiniTVSpline.BP_MiniTVSpline_C");
		return pStaticClass;
	}


	void UserConstructionScript();
};


}

