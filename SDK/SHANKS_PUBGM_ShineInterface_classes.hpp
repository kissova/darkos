// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UShineInterface_C : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass ShineInterface.ShineInterface_C");
		return pStaticClass;
	}


	void ShowNormal();
	void ShowShine();
};


}

