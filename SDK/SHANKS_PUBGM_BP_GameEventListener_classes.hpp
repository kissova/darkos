// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_GameEventListener_C : public UGameEventListener
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_GameEventListener.BP_GameEventListener_C");
		return pStaticClass;
	}


	void SetDefaultNearClipPlane();
	void IsIOSPlatform();
	void SetDefaultRendering();
	void EnableGrassLOD(int Enable);
	void ChangeStreamingLevel();
	void InitIncaseReconnect();
	void ReceiveBeginPlay();
	void ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason);
	void UnloadTree();
	void LoadTree();
	void ExecuteUbergraph_BP_GameEventListener(int EntryPoint);
};


}

