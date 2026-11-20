// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCameraShakeForFalling_C : public UCameraShake
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CameraShakeForFalling.CameraShakeForFalling_C");
		return pStaticClass;
	}


	void ReceivePlayShake(float* Scale);
	void ExecuteUbergraph_CameraShakeForFalling(int EntryPoint);
};


}

