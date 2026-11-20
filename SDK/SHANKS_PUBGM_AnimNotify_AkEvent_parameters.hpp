// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UAnimNotify_AkEvent_C_TryGetOwnerPawn_Params
{
	class AActor*                                      Owner;                                                     
	class APawn*                                       Pawn;                                                      
};

 
struct UAnimNotify_AkEvent_C_GetEvent_Params
{
	class USkeletalMeshComponent*                      MeshComp;                                                  
	class UAkAudioEvent*                               OutEvent;                                                  
};

 
struct UAnimNotify_AkEvent_C_Received_Notify_Params
{
	class USkeletalMeshComponent**                     MeshComp;                                                  
	class UAnimSequenceBase**                          Animation;                                                 
	bool                                               ReturnValue;                                               
};

}

