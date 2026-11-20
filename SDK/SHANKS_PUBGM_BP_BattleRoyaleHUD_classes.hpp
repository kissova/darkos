// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_BattleRoyaleHUD_C : public ASurviveHUD
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class USceneComponent*                             DefaultSceneRoot;                                          
	TArray<int>                                        DamageNumberDamageTypes;                                   
	TArray<TEnumAsByte<EWeaponTypeNew>>                InvalidDamageNumberWeaponTypes;                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_BattleRoyaleHUD.BP_BattleRoyaleHUD_C");
		return pStaticClass;
	}


	bool IsValidDamageNumber(class AActor** DamageCauser, int* DamageTypeId);
	struct FLinearColor GetPlayerNameColorByTeamID(int* TeamID);
	struct FLinearColor GetColorByTeamID(int* TeamID);
	void UserConstructionScript();
	void ReceiveBeginPlay();
	void HitFeedBackChanged(bool BoolValue);
	void OBSHitFeedbackChanged(bool BoolValue);
	void ExecuteUbergraph_BP_BattleRoyaleHUD(int EntryPoint);
};


}

