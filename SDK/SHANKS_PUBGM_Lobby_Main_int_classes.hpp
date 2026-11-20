// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ALobby_Main_int_C : public ALuaLevelScriptActor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UFrontendUtils*                              frontUtils;                                                
	bool                                               blockBackScene;                                            
	unsigned char                                      UnknownData00[0x7];                                        
	struct FName                                       lastSceneCamera;                                           
	class USettingConfig_C*                            SetConfig;                                                 
	struct FScriptMulticastDelegate                    Dispatcher_OpenBox;                                        
	struct FVector2D                                   viewportSize;                                              
	float                                              accumTime;                                                 
	int                                                folderDevice;                                              
	class ASkyLight*                                   SkyLight_1_EdGraph_4_RefProperty;                          
	class APointLight*                                 PointLight_0_EdGraph_4_RefProperty;                        
	class ADirectionalLight*                           DirectionalLight_0_EdGraph_4_RefProperty;                  
	class ACameraActor*                                LobbySecondCam_EdGraph_4_RefProperty;                      
	class ACameraActor*                                LobbyFirstCam_EdGraph_4_RefProperty;                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass Lobby_Main_int.Lobby_Main_int_C");
		return pStaticClass;
	}


	void RegistPersistLevelObjs(class UFrontendUtils* Utils);
	void InpActEvt_N_K2Node_InputKeyEvent_12(const struct FKey& Key);
	void InpActEvt_B_K2Node_InputKeyEvent_11(const struct FKey& Key);
	void InpActEvt_Android_Back_K2Node_InputKeyEvent_10(const struct FKey& Key);
	void InpActEvt_BackSpace_K2Node_InputKeyEvent_9(const struct FKey& Key);
	void InpActEvt_E_K2Node_InputKeyEvent_8(const struct FKey& Key);
	void InpActEvt_G_K2Node_InputKeyEvent_7(const struct FKey& Key);
	void InpAxisKeyEvt_RotationRate_K2Node_InputVectorAxisEvent_1(const struct FVector& AxisValue);
	void ReceiveTick(float* DeltaSeconds);
	void ReceiveBeginPlay();
	void ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason);
	void OnViewportChanged(const struct FVector2D& OldViewportSize, const struct FVector2D& NewViewportSize);
	void ExecuteUbergraph_Lobby_Main_int(int EntryPoint);
	void Dispatcher_OpenBox__DelegateSignature(class ASkeletalMeshActor* NewParam);
};


}

