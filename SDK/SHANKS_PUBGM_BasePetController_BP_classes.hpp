// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABasePetController_BP_C : public ASTExtraFightPetController
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UBehaviorTree*                               CurBT;                                                     
	struct FName                                       PetOwnerEmoteId;                                           
	struct FName                                       IsAirAttacking;                                            
	struct FName                                       AirAttackArea;                                             
	struct FTimerHandle                                CheckAirAttackTimer;                                       
	struct FVector                                     CurAttackArea;                                             
	unsigned char                                      UnknownData00[0x4];                                        
	class UBehaviorTree*                               FlyBt;                                                     

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BasePetController_BP.BasePetController_BP_C");
		return pStaticClass;
	}


	void LoadBehaviorTree(int Clothes);
	void CalcInAirAttackArea();
	void OnPlayerStopEmote(int EmoteId, int Reason);
	void OnPlayerPlayEmote(int Emote);
	void UserConstructionScript();
	void ReceiveBeginPlay();
	void ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason);
	void ExecuteUbergraph_BasePetController_BP(int EntryPoint);
};


}

