// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UABP_MiniTvV2_C : public UAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FAnimNode_Root                              AnimGraphNode_Root_3CA492C64B817B9B336F31B48DA44582;       
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_9452BEDA44C9873D1F58EFB6EE16DCB6; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_21378E764DBB7DD292494BAB7888D1F1; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_0B3B17044090A86B8CBBF79C02843677; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_B0F82852421A66DECFE9EFB6EF4F6C75; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_19841E7D4C46CCAFB40201BDF9E5D873; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_3C3955134122D53E221155BEDB025AB1; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_CC54C0DE4BA6E9A5DF3DA1879D014F03; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_F58490434CB11F9A31650F99F1D1DF1F; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_A32C1EA14E2AE46E7347A7B7DA822E7A; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_FE231A5B49B93C4E070460B45A9BDBC7; 
	struct FAnimNode_BlendSpacePlayer                  AnimGraphNode_BlendSpacePlayer_0EF67A5049A5CD62888251AFDE418FDA; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_80C0E2204BF35923595780B59814FEAB; 
	struct FAnimNode_BlendListByInt                    AnimGraphNode_BlendListByInt_8A9E8E3A46E8EA408644E3A04A6F8F0B; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_3E29B9C24F91A50DE19CFF8F39F14473; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_AD1541C84EC0DCF9144CB7AAC9C9C34E; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_84B851554992EDC4728DBD94F8E4DE8D; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_7B2D365E43AE89A2851F938D79E9D9AE; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_75B5136D4567EDDF4BE8E19085C147FE; 
	struct FAnimNode_BlendListByInt                    AnimGraphNode_BlendListByInt_90B7F6A24016EED663E049A0B83BE627; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_630884284C9CB49FEDBE8B96AD28E6B6; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_4603C6CA4DE3334948CA81912973F84B; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_81BC5AD448D55A82DC87BD874BCC98B9; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_359A9A494A59A90A62AA87943538C56D; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_359F14E841315272ED46A1A9D25C2536; 
	struct FAnimNode_StateMachine                      AnimGraphNode_StateMachine_565079614924516F42E80EAECD60539D; 
	struct FAnimNode_Slot                              AnimGraphNode_Slot_9BC88A3842C7E1E1F2E94D8641B68764;       
	bool                                               bDrag;                                                     
	bool                                               BWalk;                                                     
	unsigned char                                      UnknownData00[0x2];                                        
	int                                                DoubleState;                                               
	struct FScriptMulticastDelegate                    OnWalkEnd;                                                 
	float                                              Speed;                                                     
	int                                                dragtype;                                                  
	bool                                               BFloat;                                                    

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("AnimBlueprintGeneratedClass ABP_MiniTvV2.ABP_MiniTvV2_C");
		return pStaticClass;
	}


	void SetFloat(bool NewParam);
	void SetDragType(int dragtype);
	void SetSpeed(float Speed);
	void SetWalk(bool Walk);
	void SetDrag(bool Drag);
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_TransitionResult_19841E7D4C46CCAFB40201BDF9E5D873();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_TransitionResult_CC54C0DE4BA6E9A5DF3DA1879D014F03();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_TransitionResult_F58490434CB11F9A31650F99F1D1DF1F();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_TransitionResult_B0F82852421A66DECFE9EFB6EF4F6C75();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_BlendSpacePlayer_0EF67A5049A5CD62888251AFDE418FDA();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_BlendListByInt_8A9E8E3A46E8EA408644E3A04A6F8F0B();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_TransitionResult_21378E764DBB7DD292494BAB7888D1F1();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_BlendListByInt_90B7F6A24016EED663E049A0B83BE627();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_MiniTvV2_AnimGraphNode_TransitionResult_9452BEDA44C9873D1F58EFB6EE16DCB6();
	void ExecuteUbergraph_ABP_MiniTvV2(int EntryPoint);
	void OnWalkEnd__DelegateSignature();
};


}

