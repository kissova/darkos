// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetComponent_BP_C : public USTExtraFightPetComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UClass*                                      SpawnPetClass;                                             
	struct FTransform                                  SpawnTrans;                                                
	TArray<class AActor*>                              NewVar_1;                                                  
	struct FScriptMulticastDelegate                    OnRepPetPawnCalled;                                        
	struct FScriptMulticastDelegate                    OnRepPetInfo;                                              
	bool                                               bNeedRecreateMiniTv;                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PetComponent_BP.PetComponent_BP_C");
		return pStaticClass;
	}


	void SetSpawnPetPosZ();
	void IsFPPMode(bool* Out);
	void GetPetOwnerPlayerPawn(class ABP_PlayerPawn_C** Out);
	void GetPetPawn(class ABasePetCharacter_BP_C** Out);
	void SetPetPawn(class ASTExtraPetCharacter* InPetPawn, class ASTExtraPetCharacter** Out);
	void SetPetOwnerPlayerPawn(class ASTExtraBaseCharacter* InPlayerPawn, class ASTExtraBaseCharacter** Out);
	void ResetAttachTrans();
	void SpawnPetWithInfo(const struct FGameModePlayerPetInfo& Info);
	void SpawnPet(class UClass* PetClass);
	void RemovePet();
	void PlayerStateChange(EPawnState State, TEnumAsByte<EPawnStateChangeType> ChangeType);
	void OnOwnerPlayerPossessed(const struct FGameModePlayerPetInfo& PetInfo);
	void OnOwnerDetachedVehicle();
	void OnRep_PetPawn();
	void OnRep_PetOwnerPlayerPawn();
	void OnRep_PetInfo();
	void DoChangePetWithInfo(struct FGameModePlayerPetInfo* InPetInfo);
	void OnPlayerStateEnterEvent(EPawnState State);
	void OnPlayerStateLeaveEvent(EPawnState State);
	void ExecuteUbergraph_PetComponent_BP(int EntryPoint);
	void OnRepPetInfo__DelegateSignature();
	void OnRepPetPawnCalled__DelegateSignature();
};


}

