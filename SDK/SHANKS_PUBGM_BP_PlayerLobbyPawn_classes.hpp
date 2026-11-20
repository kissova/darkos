// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_PlayerLobbyPawn_C : public ASTExtraLobbyCharacter
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	class UCameraComponent*                            Camera;                                                    
	class UBP_LobbyWeaponManager_C*                    BP_LobbyWeaponManager;                                     
	class ULobbyPlayEmoteComponent_BP_C*               LobbyPlayEmoteComponent_BP;                                
	class ULobbyWeaponAnimationComponent_C*            LobbyWeaponAnimationComponent;                             
	class USkeletalMeshComponent*                      WeaponSkeletalMesh;                                        
	class UCharacterAvatarComp2_BP_C*                  CharacterAvatarComp2_BP;                                   
	class UAELobbyCharAnimListComp*                    AELobbyCharAnimListComp;                                   
	float                                              Timeline_0_Time_DFD4E0A94A64AF2CC7AD9DB7F31CA12E;          
	TEnumAsByte<ETimelineDirection>                    Timeline_0__Direction_DFD4E0A94A64AF2CC7AD9DB7F31CA12E;    
	unsigned char                                      UnknownData00[0x3];                                        
	class UTimelineComponent*                          Timeline_1;                                                
	int                                                headid;                                                    
	int                                                resID;                                                     
	bool                                               press;                                                     
	unsigned char                                      UnknownData01[0x3];                                        
	float                                              LocationX;                                                 
	TEnumAsByte<ETouchIndex>                           FingerIndex;                                               
	unsigned char                                      UnknownData02[0x3];                                        
	int                                                LobbyPosition;                                             
	class ASTExtraWeapon*                              curEquipingWeapon;                                         
	TMap<int, class UBackpackEmoteHandle*>             EmoteItemIDToHandleMap;                                    
	struct FString                                     PlayerKey;                                                 
	bool                                               HeadIsVisible;                                             
	bool                                               canRotate;                                                 
	unsigned char                                      UnknownData03[0x2];                                        
	int                                                LuaID;                                                     
	struct FScriptMulticastDelegate                    OnPlayAction;                                              
	struct FScriptMulticastDelegate                    OnStopAction;                                              
	struct FScriptMulticastDelegate                    OnChangeEquipment;                                         
	class UBackpackEmoteHandle*                        CurEmoteHandle;                                            
	bool                                               bIsEmoteLooping;                                           
	unsigned char                                      UnknownData04[0x3];                                        
	int                                                CurrentActionID;                                           
	bool                                               IsChangingHead;                                            
	unsigned char                                      UnknownData05[0x3];                                        
	int                                                PlayOnChangingHeadAcionID;                                 
	int                                                CurPlayEmoteId;                                            
	bool                                               IsPlayingAction;                                           
	unsigned char                                      UnknownData06[0x3];                                        
	float                                              RotateTime;                                                
	float                                              TargetRotation;                                            
	bool                                               StartRotateFlag;                                           
	unsigned char                                      UnknownData07[0x3];                                        
	float                                              ClothAnimDyAlpha;                                          
	float                                              CurClothAnimDyAlpha;                                       
	float                                              ClothAnimDyAlphaDiff;                                      
	bool                                               isMVPMotion;                                               
	unsigned char                                      UnknownData08[0x7];                                        
	struct FScriptMulticastDelegate                    OnchangeGender;                                            
	bool                                               bEquipingSkateAircraft;                                    
	bool                                               isAutoTest;                                                
	unsigned char                                      UnknownData09[0x2];                                        
	struct FVector                                     LocationBeforeEmote;                                       
	float                                              Inten;                                                     
	unsigned char                                      UnknownData10[0x4];                                        
	TMap<int, int>                                     DynamicMatClothMap;                                        
	float                                              WindSpeed_Editor;                                          
	float                                              WindStrength_Editor;                                       
	float                                              WindRadius_Editor;                                         
	unsigned char                                      UnknownData11[0x4];                                        
	class UCurveFloat*                                 WindSpeed;                                                 
	float                                              AccumelateWindTime;                                        
	unsigned char                                      UnknownData12[0x4];                                        
	struct FScriptMulticastDelegate                    OnSceneType2Change;                                        
	int                                                SceneType2;                                                
	bool                                               NeedLookAtCam;                                             
	unsigned char                                      UnknownData13[0x3];                                        
	struct FScriptMulticastDelegate                    OnPreChangeEquip;                                          
	bool                                               bIgnoreDragRotation;                                       
	unsigned char                                      UnknownData14[0x7];                                        
	class UClass*                                      LobbyFootLockABP;                                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_PlayerLobbyPawn.BP_PlayerLobbyPawn_C");
		return pStaticClass;
	}


	void UpdateCameraLocation();
	void SetCompRotate(class USceneComponent* RotateComp, float Rotate);
	void SetAddCharacterWeaponAnimListHandle(TArray<struct FLobbyCharacterWeaponAnimData>* addAnimData);
	void CharEquipWeaponPendant(int WeaponId, EWeaponPendantSocketType PendantSocketType);
	void WeaponAllAssetLoadFinish();
	void CharUnEquipWeaponByResId(int resID, const struct FName& SocketName);
	void CharUnEquipExtraWeapon();
	void SetForceUseDefaultIdle(bool Force);
	void UpdateClothInten(float leten);
	void UpdateClothMatParam(float RotateSpeed);
	void StopActionCamera();
	void RotateOnTickInternal();
	void GetCurrentActionID(int* ActionID);
	void OnAvatarAllMeshLoaded();
	void TryRotateAvatar();
	void SetAvatarVisibleForEmote(bool Visible);
	void RequestWeaponDIYData(const struct FString& InPlayerUID, int WeaponAvatarID, int InDIYPlanID);
	void SetIsMVPMotion(bool isMVPMotion);
	void InitDefaultAvatarByResID(int AGender, int Head, int hair);
	void SetClothAnimDyAlphaInst(float Alpha);
	void SetClothAnimDyAlphaGrad(float Alpha);
	void SetClothAnimDyAlpha(float Alpha);
	void RotateOnTick(float RotateTime, float TargetRotation);
	void OnEndActionHandle(int ActionID);
	void OnPlayActionHandle(int ActionID);
	void SetConflictRuleEnable(bool bEnableConflictRule);
	void PutOffEquipmentBySlot(EAvatarSlotType SlotType, bool* Result);
	void PlayEmoteLoop();
	void ShouldCurEmoteShowWeapon(bool* Result);
	void HandleWeaponDisplayWhenPlayEmote();
	void GetAllEquipmentList(TArray<int>* Result);
	void SetCanRotate(bool canRotate);
	void PutOffEquipmentByResID(int resID, bool* Result);
	void HideWeapon(bool isHide);
	void CharPlayEmoteByResId(int EmoteId, const struct FString& ExtraInfo);
	void CharUnEquipWeapon();
	void CharEquipWeaponByResId(int resID, bool bUse, bool bAsync, const struct FName& SocketName, class ASTExtraWeapon** Weapon);
	class UBackpackEmoteHandle* GetEmoteHandle(int* ItemId);
	void GetBPID(int RowName, int* BPID);
	void UserConstructionScript();
	void Timeline_0__FinishedFunc();
	void Timeline_0__UpdateFunc();
	void ReceiveTick(float* DeltaSeconds);
	void TickClothLeten(float From);
	void ExecuteUbergraph_BP_PlayerLobbyPawn(int EntryPoint);
	void OnPreChangeEquip__DelegateSignature();
	void OnSceneType2Change__DelegateSignature(int sceneType);
	void OnchangeGender__DelegateSignature();
	void OnChangeEquipment__DelegateSignature();
	void OnStopAction__DelegateSignature(int ActionID);
	void OnPlayAction__DelegateSignature(int ActionID);
};


}

