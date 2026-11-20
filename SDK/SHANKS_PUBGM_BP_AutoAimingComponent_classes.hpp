// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_AutoAimingComponent_C : public UWeaponAutoAimingComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	TEnumAsByte<EDrawDebugTrace>                       DrawDebugType;                                             
	unsigned char                                      UnknownData00[0x7];                                        
	class UUserWidget*                                 DebugUI;                                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_AutoAimingComponent.BP_AutoAimingComponent_C");
		return pStaticClass;
	}


	bool CheckInAngle(class AActor** EnemeyActor, float* MaxAngle);
	bool CheckSmoke(class AActor** EnemeyActor, struct FVector* StartPoint, struct FVector* EndPoint);
	bool CanEnemeyRaycastReach(class AActor** EnemeyActor, struct FVector* StartPoint, struct FVector* EndPoint, struct FName* OutHitBoneName);
	void BPDrawDebugInfo(TArray<float>* AutoAimParams);
	void ExecuteUbergraph_BP_AutoAimingComponent(int EntryPoint);
};


}

