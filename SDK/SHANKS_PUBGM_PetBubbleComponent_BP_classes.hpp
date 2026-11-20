// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetBubbleComponent_BP_C : public UActorComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UParticleSystemComponent*                    BubbleParticle;                                            
	int                                                CurBubbleType;                                             
	unsigned char                                      UnknownData00[0x4];                                        
	class UTexture*                                    BubbleTexture;                                             
	struct FVector                                     BubbleOffset;                                              
	unsigned char                                      UnknownData01[0x4];                                        
	class UParticleSystemComponent*                    PlayingBubbleParticle;                                     

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetBubbleComponent_BP.PetBubbleComponent_BP_C");
		return pStaticClass;
	}


	void DisposePetBubble();
	void InvokePetBubble(int Bubble_ID);
	void SpawnEmoteBubble(int BubbleID);
	void OnLoadBubbleTextureCallBack(class UObject* Asset, int ID);
	void OnLoadEffect(class UObject* LoadedObject, const struct FName& TexParamName);
	void CustomEvent_1(class UObject* LoadedObject, int RequestID);
	void CustomEvent_2(class UObject* LoadedObject, int RequestID);
	void MIDOK(class UMaterialInstanceDynamic* MaterialInstanceDynamic);
	void ReqSpawnPetBubble(int BubbleID);
	void OnNotifySpawnPetBubble(int BubbleID);
	void ExecuteUbergraph_PetBubbleComponent_BP(int EntryPoint);
};


}

