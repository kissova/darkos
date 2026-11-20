// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct ULobbyPlayEmoteComponent_BP_C_OnEquipmentChange_Params
{
	int                                                resID;                                                     
	bool                                               bPutOn;                                                    
};

 
struct ULobbyPlayEmoteComponent_BP_C_OnStartLevelSequence_Params
{
};

 
struct ULobbyPlayEmoteComponent_BP_C_GetLobbyCamera_Params
{
	class ACameraActor*                                CameraActor;                                               
};

 
struct ULobbyPlayEmoteComponent_BP_C_OnStopLevelSequence_Params
{
};

 
struct ULobbyPlayEmoteComponent_BP_C_ChangetoLevelSequenceCamera_Params
{
};

 
struct ULobbyPlayEmoteComponent_BP_C_OnTrackEvent_Params
{
	struct FString                                     EventData;                                                 
};

 
struct ULobbyPlayEmoteComponent_BP_C_PlayCameraEmoteAnim_Params
{
	class ULevelSequence**                             CurrentCameraEmoteAnim;                                    
};

 
struct ULobbyPlayEmoteComponent_BP_C_StopCameraEmoteAnim_Params
{
};

 
struct ULobbyPlayEmoteComponent_BP_C_ShowAvatarForEmote_Params
{
	bool*                                              Show;                                                      
	bool*                                              Force;                                                     
};

 
struct ULobbyPlayEmoteComponent_BP_C_BindEventToCameraSequence_Params
{
	class ULevelSequencePlayer**                       SeqPlayer;                                                 
};

 
struct ULobbyPlayEmoteComponent_BP_C_ExecuteUbergraph_LobbyPlayEmoteComponent_BP_Params
{
	int                                                EntryPoint;                                                
};

}

