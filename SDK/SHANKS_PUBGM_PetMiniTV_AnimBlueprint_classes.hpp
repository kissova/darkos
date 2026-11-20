// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPetMiniTV_AnimBlueprint_C : public USTExtraPetAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FAnimNode_Root                              AnimGraphNode_Root_C9E39A234EEDF321D02920B2479D5BEF;       
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_50BBE809472C38EAB593E3834784AEDB; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_00BBBF784BC9B749FFA330BFA402AEBD; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_CA199F1E416BF993AF4C84B8BAFD41C4; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_C17DD9FF4071D328B547BEA232EEB16F; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_8184F36049B1B9154763B98AE881E97B; 
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_1DDC764C421D165D8327F2911CC4991C; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_5458D5FD468790039C4DCE88F9F3C341; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_FFE59E3544674C3B0997018906F806B0; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_B95BF109444EA27E295BA5A3719574FA; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_52E3060346A6851D7806948D7C35485A; 
	struct FAnimNode_BlendSpacePlayer                  AnimGraphNode_BlendSpacePlayer_2306A39C4D7CE8A70EECEBB37BFCCB93; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_FBF4150A4D493BF499668990935144AE; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_009041B3462D8CF2D4A201865DD876D2; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_0B36E1E74255218192097EB7CBB22FC3; 
	struct FAnimNode_StateMachine                      AnimGraphNode_StateMachine_E0FB467640D9C53014BDF1A08A1BD8B1; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_BE8933BC4CCCEB2BCB7183AD234DBB67; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_C68145EE42730BC7755F3D9DD43A1378; 
	struct FAnimNode_StateMachine                      AnimGraphNode_StateMachine_6945DDAC45D574B30BF676AB76C8099E; 
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_A30E6183458B0B3F2595A8A2ED7F8D0C; 
	struct FAnimNode_Root                              AnimGraphNode_StateResult_AA3ADF8F403D8AF7041DA3B4FD89F07B; 
	struct FAnimNode_StateMachine                      AnimGraphNode_StateMachine_94939C3444B46FBCC07548B43E441B8F; 
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_8C17E583493EFEA0F44C919180EABFD2; 
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_A3F2DFF946358CFE52D97B94D948E4AA; 
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_C861DABD43F34B5D7DDE18B61B409F9E; 
	struct FAnimNode_Slot                              AnimGraphNode_Slot_8936495044F5FF29C130F782420447F7;       
	struct FAnimNode_BlendListByBool                   AnimGraphNode_BlendListByBool_2DE059B04DF7111204D21EBAFE22CE81; 
	struct FAnimNode_BlendListByBool                   AnimGraphNode_BlendListByBool_823FBE9B475C16E23156C4A71722896F; 
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_B6A862EB42F36F31F7308FA3D31D623A; 
	struct FAnimNode_BlendListByBool                   AnimGraphNode_BlendListByBool_3D1960524214E1A6816BEF84FE55493B; 
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_195F2EA040C4F0C39693A0AD5BC25FEC; 
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_C0CBCECB438375034C1DEC9DE3D54CDF; 
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_F6EC15D049B2F3896FC0089BAE635DF9; 
	float                                              EnterIdleTS;                                               
	bool                                               bEnterSleepLoop;                                           
	bool                                               bCanEnterSleep;                                            
	bool                                               bInIdle;                                                   

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("AnimBlueprintGeneratedClass PetMiniTV_AnimBlueprint.PetMiniTV_AnimBlueprint_C");
		return pStaticClass;
	}


	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_TransitionResult_1DDC764C421D165D8327F2911CC4991C();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_BlendSpacePlayer_2306A39C4D7CE8A70EECEBB37BFCCB93();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_TransitionResult_C17DD9FF4071D328B547BEA232EEB16F();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_SequencePlayer_009041B3462D8CF2D4A201865DD876D2();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_TransitionResult_CA199F1E416BF993AF4C84B8BAFD41C4();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_SequencePlayer_BE8933BC4CCCEB2BCB7183AD234DBB67();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_SequencePlayer_A30E6183458B0B3F2595A8A2ED7F8D0C();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_BlendListByBool_2DE059B04DF7111204D21EBAFE22CE81();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_BlendListByBool_823FBE9B475C16E23156C4A71722896F();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_BlendListByBool_3D1960524214E1A6816BEF84FE55493B();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_TransitionResult_00BBBF784BC9B749FFA330BFA402AEBD();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_TransitionResult_50BBE809472C38EAB593E3834784AEDB();
	void AnimNotify_OnEnterIdle();
	void AnimNotify_OnLeftIdle();
	void AnimNotify_OnEnterSleepStart();
	void AnimNotify_OnLeftSleepStart();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_PetMiniTV_AnimBlueprint_AnimGraphNode_TransitionResult_8184F36049B1B9154763B98AE881E97B();
	void ExecuteUbergraph_PetMiniTV_AnimBlueprint(int EntryPoint);
};


}

