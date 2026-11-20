// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UPetComponent_BP_C_SetSpawnPetPosZ_Params
{
};

 
struct UPetComponent_BP_C_IsFPPMode_Params
{
	bool                                               Out;                                                       
};

 
struct UPetComponent_BP_C_GetPetOwnerPlayerPawn_Params
{
	class ABP_PlayerPawn_C*                            Out;                                                       
};

 
struct UPetComponent_BP_C_GetPetPawn_Params
{
	class ABasePetCharacter_BP_C*                      Out;                                                       
};

 
struct UPetComponent_BP_C_SetPetPawn_Params
{
	class ASTExtraPetCharacter*                        InPetPawn;                                                 
	class ASTExtraPetCharacter*                        Out;                                                       
};

 
struct UPetComponent_BP_C_SetPetOwnerPlayerPawn_Params
{
	class ASTExtraBaseCharacter*                       InPlayerPawn;                                              
	class ASTExtraBaseCharacter*                       Out;                                                       
};

 
struct UPetComponent_BP_C_ResetAttachTrans_Params
{
};

 
struct UPetComponent_BP_C_SpawnPetWithInfo_Params
{
	struct FGameModePlayerPetInfo                      Info;                                                      
};

 
struct UPetComponent_BP_C_SpawnPet_Params
{
	class UClass*                                      PetClass;                                                  
};

 
struct UPetComponent_BP_C_RemovePet_Params
{
};

 
struct UPetComponent_BP_C_PlayerStateChange_Params
{
	EPawnState                                         State;                                                     
	TEnumAsByte<EPawnStateChangeType>                  ChangeType;                                                
};

 
struct UPetComponent_BP_C_OnOwnerPlayerPossessed_Params
{
	struct FGameModePlayerPetInfo                      PetInfo;                                                   
};

 
struct UPetComponent_BP_C_OnOwnerDetachedVehicle_Params
{
};

 
struct UPetComponent_BP_C_OnRep_PetPawn_Params
{
};

 
struct UPetComponent_BP_C_OnRep_PetOwnerPlayerPawn_Params
{
};

 
struct UPetComponent_BP_C_OnRep_PetInfo_Params
{
};

 
struct UPetComponent_BP_C_DoChangePetWithInfo_Params
{
	struct FGameModePlayerPetInfo*                     InPetInfo;                                                 
};

 
struct UPetComponent_BP_C_OnPlayerStateEnterEvent_Params
{
	EPawnState                                         State;                                                     
};

 
struct UPetComponent_BP_C_OnPlayerStateLeaveEvent_Params
{
	EPawnState                                         State;                                                     
};

 
struct UPetComponent_BP_C_ExecuteUbergraph_PetComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

 
struct UPetComponent_BP_C_OnRepPetInfo__DelegateSignature_Params
{
};

 
struct UPetComponent_BP_C_OnRepPetPawnCalled__DelegateSignature_Params
{
};

}

