// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UVault_Controller_C : public UPlayerMantleComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass Vault_Controller.Vault_Controller_C");
		return pStaticClass;
	}


	void JumpVault();
	void VaultServer(float dis, float Height, float Length, const struct FString& VaultKey, const struct FVector& StartPos, class AActor* checkActor, float crossblockMaxFall, float crossblockMaxDis, const struct FVector& HitPoint, class AActor* WindowActor, const struct FRotator& MoveDir);
	void vaultAll(float dis, float Height, float Length, const struct FString& VaultKey, const struct FVector& StartPos, class AActor* checkActor, float crossmaxFalling, float crossmaxDis, const struct FVector& HitPoint, const struct FRotator& MoveDir);
	void StopVault();
	void DsCheckStopVault();
	void ExecuteUbergraph_Vault_Controller(int EntryPoint);
};


}

