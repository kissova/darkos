// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ULobbyPlayEmoteComponent_BP_C : public ULobbyPlayEmoteComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class ULevelSequencePlayer*                        LevelSequencePlayer;                                       
	class ALevelSequenceActor*                         LevelSequenceActor;                                        
	class UUserWidget*                                 levelSequenceMask;                                         
	unsigned char                                      UnknownData00[0x50];                                       
	bool                                               bFreezeEndFrame;                                           
	bool                                               bUseSequenceCamera;                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass LobbyPlayEmoteComponent_BP.LobbyPlayEmoteComponent_BP_C");
		return pStaticClass;
	}


	void OnEquipmentChange(int resID, bool bPutOn);
	void OnStartLevelSequence();
	void GetLobbyCamera(class ACameraActor** CameraActor);
	void OnStopLevelSequence();
	void ChangetoLevelSequenceCamera();
	void OnTrackEvent(const struct FString& EventData);
	void PlayCameraEmoteAnim(class ULevelSequence** CurrentCameraEmoteAnim);
	void StopCameraEmoteAnim();
	void ShowAvatarForEmote(bool* Show, bool* Force);
	void BindEventToCameraSequence(class ULevelSequencePlayer** SeqPlayer);
	void ExecuteUbergraph_LobbyPlayEmoteComponent_BP(int EntryPoint);
};


}

