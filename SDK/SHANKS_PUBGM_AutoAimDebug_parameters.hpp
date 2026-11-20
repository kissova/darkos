// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UAutoAimDebug_C_Get_TextBlock_7_Text_1_Params
{
	struct FText                                       ReturnValue;                                               
};

 
struct UAutoAimDebug_C_Get_TextBlock_3_Text_1_Params
{
	struct FText                                       ReturnValue;                                               
};

 
struct UAutoAimDebug_C_HandleDamage_Params
{
	bool                                               NewParam;                                                  
	bool                                               NewParam1;                                                 
};

 
struct UAutoAimDebug_C_Get_TextBlock_14_Text_1_Params
{
	struct FText                                       ReturnValue;                                               
};

 
struct UAutoAimDebug_C_Get_TextBlock_12_Text_1_Params
{
	struct FText                                       ReturnValue;                                               
};

 
struct UAutoAimDebug_C_OnPaint_Params
{
	struct FPaintContext                               Context;                                                   
};

 
struct UAutoAimDebug_C_DrawDebug_Params
{
	TArray<float>                                      DebugInfo;                                                 
};

 
struct UAutoAimDebug_C_Construct_Params
{
};

 
struct UAutoAimDebug_C_Tick_Params
{
	struct FGeometry*                                  MyGeometry;                                                
	float*                                             InDeltaTime;                                               
};

 
struct UAutoAimDebug_C_OnEquip_Params
{
	class ASTExtraWeapon*                              Weapon;                                                    
	TEnumAsByte<ESurviveWeaponPropSlot>                Slot;                                                      
};

 
struct UAutoAimDebug_C_CustomEvent_1_Params
{
};

 
struct UAutoAimDebug_C_CustomEvent_2_Params
{
};

 
struct UAutoAimDebug_C_CustomEvent_3_Params
{
	class ASTExtraShootWeapon*                         ShootWeapon;                                               
	class ASTExtraShootWeaponBulletBase*               Bullet;                                                    
};

 
struct UAutoAimDebug_C_CustomEvent_4_Params
{
	class ASTExtraShootWeapon*                         ShootWeapon;                                               
	class ASTExtraShootWeaponBulletBase*               Bullet;                                                    
	struct FHitResult                                  HitRet;                                                    
};

 
struct UAutoAimDebug_C_CustomEvent_5_Params
{
	float                                              Damage;                                                    
	struct FDamageEvent                                DamageEvent;                                               
	class AActor*                                      Casuer;                                                    
	class AActor*                                      Victim;                                                    
};

 
struct UAutoAimDebug_C_ExecuteUbergraph_AutoAimDebug_Params
{
	int                                                EntryPoint;                                                
};

}

