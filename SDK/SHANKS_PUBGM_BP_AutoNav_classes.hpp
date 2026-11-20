// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_AutoNav_C : public UPlayerAutoNavComponent
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	float                                              MinDistanceToDesc;                                         
	float                                              MaxFailMoveDescTime;                                       
	float                                              CurFailMoveDescTime;                                       
	float                                              RotationSpeed;                                             
	TMap<EPlayerAutoNavResult, int>                    ResultTipMap;                                              
	struct FRotator                                    NewVar_1;                                                  
	bool                                               bShowRequestTip;                                           
	bool                                               bShowResultTip;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_AutoNav.BP_AutoNav_C");
		return pStaticClass;
	}


	void CheckObstacle(const struct FVector& StartLocation, const struct FVector& EndLoc, bool* bRet);
	bool IsArrivalDesc_Ex(const struct FVector& ActorLocation);
	void IsPartialPathFinding(bool* bRet);
	bool IsSwim();
	void GetLastMinDistance(float* Distance);
	bool CheckCharacterPoseState(class ASTExtraPlayerController** PC);
	void StopPlayerAutoSprint();
	void ShowStopMoveResult(EPlayerAutoNavResult Result);
	void ShowTips(int ID);
	void CallSetPlayerAutoSprint(class ASTExtraPlayerController* Target, class ASTExtraBaseCharacter* Character);
	void IsAutoSpint(bool* bAutoSprint);
	struct FRotator GetRotatorToDesc(const struct FVector& ActorLocation);
	void ResetMinDistanceToDesc(const struct FVector& ActorLocation);
	float GetDescDistance(const struct FVector& ActorLocation);
	bool IsLastPoint();
	void GotoNextPoint();
	bool IsArrivalDesc(const struct FVector& ActorLocation);
	void GetDesc(struct FVector* Desc);
	void TickCloseToTarget(class ASTExtraPlayerController** PC, float* DeltaTime);
	void OnStartAutoMove(class ASTExtraPlayerController** PC);
	void ReceiveBeginPlay();
	void CustomEvent(EPlayerAutoNavFindResult FindResult);
	void StopMove();
	void OnRepPlayerState();
	void BPOnRequestMove(EPlayerAutoNavMode* CurMode, struct FString* TargetParam, struct FVector* TargetLoc);
	void ExecuteUbergraph_BP_AutoNav(int EntryPoint);
};


}

