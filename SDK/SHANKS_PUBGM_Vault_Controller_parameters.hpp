// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UVault_Controller_C_JumpVault_Params
{
};

 
struct UVault_Controller_C_VaultServer_Params
{
	float                                              dis;                                                       
	float                                              Height;                                                    
	float                                              Length;                                                    
	struct FString                                     VaultKey;                                                  
	struct FVector                                     StartPos;                                                  
	class AActor*                                      checkActor;                                                
	float                                              crossblockMaxFall;                                         
	float                                              crossblockMaxDis;                                          
	struct FVector                                     HitPoint;                                                  
	class AActor*                                      WindowActor;                                               
	struct FRotator                                    MoveDir;                                                   
};

 
struct UVault_Controller_C_vaultAll_Params
{
	float                                              dis;                                                       
	float                                              Height;                                                    
	float                                              Length;                                                    
	struct FString                                     VaultKey;                                                  
	struct FVector                                     StartPos;                                                  
	class AActor*                                      checkActor;                                                
	float                                              crossmaxFalling;                                           
	float                                              crossmaxDis;                                               
	struct FVector                                     HitPoint;                                                  
	struct FRotator                                    MoveDir;                                                   
};

 
struct UVault_Controller_C_StopVault_Params
{
};

 
struct UVault_Controller_C_DsCheckStopVault_Params
{
};

 
struct UVault_Controller_C_ExecuteUbergraph_Vault_Controller_Params
{
	int                                                EntryPoint;                                                
};

}

