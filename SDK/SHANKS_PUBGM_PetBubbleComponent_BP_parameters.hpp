// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UPetBubbleComponent_BP_C_DisposePetBubble_Params
{
};

 
struct UPetBubbleComponent_BP_C_InvokePetBubble_Params
{
	int                                                Bubble_ID;                                                 
};

 
struct UPetBubbleComponent_BP_C_SpawnEmoteBubble_Params
{
	int                                                BubbleID;                                                  
};

 
struct UPetBubbleComponent_BP_C_OnLoadBubbleTextureCallBack_Params
{
	class UObject*                                     Asset;                                                     
	int                                                ID;                                                        
};

 
struct UPetBubbleComponent_BP_C_OnLoadEffect_Params
{
	class UObject*                                     LoadedObject;                                              
	struct FName                                       TexParamName;                                              
};

 
struct UPetBubbleComponent_BP_C_CustomEvent_1_Params
{
	class UObject*                                     LoadedObject;                                              
	int                                                RequestID;                                                 
};

 
struct UPetBubbleComponent_BP_C_CustomEvent_2_Params
{
	class UObject*                                     LoadedObject;                                              
	int                                                RequestID;                                                 
};

 
struct UPetBubbleComponent_BP_C_MIDOK_Params
{
	class UMaterialInstanceDynamic*                    MaterialInstanceDynamic;                                   
};

 
struct UPetBubbleComponent_BP_C_ReqSpawnPetBubble_Params
{
	int                                                BubbleID;                                                  
};

 
struct UPetBubbleComponent_BP_C_OnNotifySpawnPetBubble_Params
{
	int                                                BubbleID;                                                  
};

 
struct UPetBubbleComponent_BP_C_ExecuteUbergraph_PetBubbleComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

}

