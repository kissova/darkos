// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAutoAimDebug_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UTextBlock*                                  T1;                                                        
	class UTextBlock*                                  t2;                                                        
	class UTextBlock*                                  t3;                                                        
	class UTextBlock*                                  t4;                                                        
	class UTextBlock*                                  t5;                                                        
	class UTextBlock*                                  t6;                                                        
	class UTextBlock*                                  t7;                                                        
	class UTextBlock*                                  TextBlock_4;                                               
	class UTextBlock*                                  TextBlock_8;                                               
	class UTextBlock*                                  TextBlock_13;                                              
	class UTextBlock*                                  TextBlock_15;                                              
	TArray<class UTextBlock*>                          TextWidgetArray;                                           
	float                                              LastAimTime;                                               
	unsigned char                                      UnknownData00[0x4];                                        
	TArray<float>                                      AimDelta;                                                  
	int                                                Debug_Hit_Num;                                             
	int                                                Debug_Miss_Num;                                            
	float                                              Damage;                                                    
	int                                                headShot;                                                  

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("WidgetBlueprintGeneratedClass AutoAimDebug.AutoAimDebug_C");
		return pStaticClass;
	}


	struct FText Get_TextBlock_7_Text_1();
	struct FText Get_TextBlock_3_Text_1();
	void HandleDamage(bool NewParam, bool NewParam1);
	struct FText Get_TextBlock_14_Text_1();
	struct FText Get_TextBlock_12_Text_1();
	void OnPaint(struct FPaintContext* Context);
	void DrawDebug(TArray<float>* DebugInfo);
	void Construct();
	void Tick(struct FGeometry* MyGeometry, float* InDeltaTime);
	void OnEquip(class ASTExtraWeapon* Weapon, TEnumAsByte<ESurviveWeaponPropSlot> Slot);
	void CustomEvent_1();
	void CustomEvent_2();
	void CustomEvent_3(class ASTExtraShootWeapon* ShootWeapon, class ASTExtraShootWeaponBulletBase* Bullet);
	void CustomEvent_4(class ASTExtraShootWeapon* ShootWeapon, class ASTExtraShootWeaponBulletBase* Bullet, const struct FHitResult& HitRet);
	void CustomEvent_5(float Damage, const struct FDamageEvent& DamageEvent, class AActor* Casuer, class AActor* Victim);
	void ExecuteUbergraph_AutoAimDebug(int EntryPoint);
};


}

