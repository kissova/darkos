// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UABP_LobbyFootLock_C : public ULobbyFootLockAnimState
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FAnimNode_MakeDynamicAdditive               AnimGraphNode_MakeDynamicAdditive_943D7C964D81FA3030066D9BA18D69ED; 
	struct FAnimNode_ApplyAdditive                     AnimGraphNode_ApplyAdditive_FBF0ECC24BA365D3E301D1B196C6E2CA; 
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_3C8C9EB7454DF2DE06790BA3DBE3A6F1; 
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_12E19BD14CC22A8D75E5DB9495986D16; 
	struct FAnimNode_ConvertLocalToComponentSpace      AnimGraphNode_LocalToComponentSpace_B51141A64C31044538489D857EE50F7B; 
	struct FAnimNode_TwoBoneIK                         AnimGraphNode_TwoBoneIK_83B366F247150B2E08BAC8852ADD2310;  
	struct FAnimNode_TwoBoneIK                         AnimGraphNode_TwoBoneIK_BDA234194CFED3542F2C92B2407309D5;  
	struct FAnimNode_ConvertComponentToLocalSpace      AnimGraphNode_ComponentToLocalSpace_FA6301214BA6CF4073B0CABEDB794C9A; 
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_DF6D1D3E4E50C94FD47E35A392506C78; 
	struct FAnimNode_LayeredBoneBlend                  AnimGraphNode_LayeredBoneBlend_602184DF436C308B4E157AA0F3D09B83; 
	struct FAnimNode_SubInput                          AnimGraphNode_SubInput_DE4D65F34C1A683F3B8C5C8DA9A900EB;   
	struct FAnimNode_SequenceEvaluator                 AnimGraphNode_SequenceEvaluator_05C0A1B441F4ABB9F509689FFE2ABC8F; 
	struct FAnimNode_Slot                              AnimGraphNode_Slot_762C64BD4449FDAF80A3F29DA857385B;       
	struct FAnimNode_Root                              AnimGraphNode_Root_288FCB394EF42302FFA3B1AAA8CF38C4;       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("AnimBlueprintGeneratedClass ABP_LobbyFootLock.ABP_LobbyFootLock_C");
		return pStaticClass;
	}


	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_LobbyFootLock_AnimGraphNode_SequenceEvaluator_05C0A1B441F4ABB9F509689FFE2ABC8F();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_LobbyFootLock_AnimGraphNode_TwoBoneIK_BDA234194CFED3542F2C92B2407309D5();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_LobbyFootLock_AnimGraphNode_TwoBoneIK_83B366F247150B2E08BAC8852ADD2310();
	void ExecuteUbergraph_ABP_LobbyFootLock(int EntryPoint);
};


}

