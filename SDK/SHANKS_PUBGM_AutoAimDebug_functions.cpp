// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

struct FText UAutoAimDebug_C::Get_TextBlock_7_Text_1()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.Get_TextBlock_7_Text_1");

	UAutoAimDebug_C_Get_TextBlock_7_Text_1_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FText UAutoAimDebug_C::Get_TextBlock_3_Text_1()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.Get_TextBlock_3_Text_1");

	UAutoAimDebug_C_Get_TextBlock_3_Text_1_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

void UAutoAimDebug_C::HandleDamage(bool NewParam, bool NewParam1)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.HandleDamage");

	UAutoAimDebug_C_HandleDamage_Params params;
	params.NewParam = NewParam;
	params.NewParam1 = NewParam1;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

struct FText UAutoAimDebug_C::Get_TextBlock_14_Text_1()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.Get_TextBlock_14_Text_1");

	UAutoAimDebug_C_Get_TextBlock_14_Text_1_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

struct FText UAutoAimDebug_C::Get_TextBlock_12_Text_1()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.Get_TextBlock_12_Text_1");

	UAutoAimDebug_C_Get_TextBlock_12_Text_1_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UAutoAimDebug_C::OnPaint(struct FPaintContext* Context)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.OnPaint");

	UAutoAimDebug_C_OnPaint_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Context != nullptr)
		*Context = params.Context;
}


 
 
 
 

void UAutoAimDebug_C::DrawDebug(TArray<float>* DebugInfo)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.DrawDebug");

	UAutoAimDebug_C_DrawDebug_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (DebugInfo != nullptr)
		*DebugInfo = params.DebugInfo;
}


 
 

void UAutoAimDebug_C::Construct()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.Construct");

	UAutoAimDebug_C_Construct_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UAutoAimDebug_C::Tick(struct FGeometry* MyGeometry, float* InDeltaTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.Tick");

	UAutoAimDebug_C_Tick_Params params;
	params.MyGeometry = MyGeometry;
	params.InDeltaTime = InDeltaTime;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UAutoAimDebug_C::OnEquip(class ASTExtraWeapon* Weapon, TEnumAsByte<ESurviveWeaponPropSlot> Slot)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.OnEquip");

	UAutoAimDebug_C_OnEquip_Params params;
	params.Weapon = Weapon;
	params.Slot = Slot;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UAutoAimDebug_C::CustomEvent_1()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.CustomEvent_1");

	UAutoAimDebug_C_CustomEvent_1_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 

void UAutoAimDebug_C::CustomEvent_2()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.CustomEvent_2");

	UAutoAimDebug_C_CustomEvent_2_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UAutoAimDebug_C::CustomEvent_3(class ASTExtraShootWeapon* ShootWeapon, class ASTExtraShootWeaponBulletBase* Bullet)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.CustomEvent_3");

	UAutoAimDebug_C_CustomEvent_3_Params params;
	params.ShootWeapon = ShootWeapon;
	params.Bullet = Bullet;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 

void UAutoAimDebug_C::CustomEvent_4(class ASTExtraShootWeapon* ShootWeapon, class ASTExtraShootWeaponBulletBase* Bullet, const struct FHitResult& HitRet)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.CustomEvent_4");

	UAutoAimDebug_C_CustomEvent_4_Params params;
	params.ShootWeapon = ShootWeapon;
	params.Bullet = Bullet;
	params.HitRet = HitRet;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 
 
 

void UAutoAimDebug_C::CustomEvent_5(float Damage, const struct FDamageEvent& DamageEvent, class AActor* Casuer, class AActor* Victim)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.CustomEvent_5");

	UAutoAimDebug_C_CustomEvent_5_Params params;
	params.Damage = Damage;
	params.DamageEvent = DamageEvent;
	params.Casuer = Casuer;
	params.Victim = Victim;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UAutoAimDebug_C::ExecuteUbergraph_AutoAimDebug(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function AutoAimDebug.AutoAimDebug_C.ExecuteUbergraph_AutoAimDebug");

	UAutoAimDebug_C_ExecuteUbergraph_AutoAimDebug_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

