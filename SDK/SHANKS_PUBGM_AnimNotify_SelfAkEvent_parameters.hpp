// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UAnimNotify_SelfAkEvent_C_PlayAkEvent_Params
{
	class USkeletalMeshComponent*                      MeshComp;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UAnimNotify_SelfAkEvent_C_Received_Notify_Params
{
	class USkeletalMeshComponent**                     MeshComp;                                                  
	class UAnimSequenceBase**                          Animation;                                                 
	bool                                               ReturnValue;                                               
};

}

