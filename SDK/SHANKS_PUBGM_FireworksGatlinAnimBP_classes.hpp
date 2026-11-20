// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UFireworksGatlinAnimBP_C : public UCharacterAnimStateBase
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FAnimNode_Root                              AnimGraphNode_Root_65E678C64A034D6318676AA398B0DD4A;       
	struct FAnimNode_SubInput                          AnimGraphNode_SubInput_7492ED3944407B5FBEB9DEAD56C5A059;   
	struct FAnimNode_ModifyBone                        AnimGraphNode_ModifyBone_76F3E93741D1EE0080E835BF9141B6D5; 
	struct FAnimNode_ConvertLocalToComponentSpace      AnimGraphNode_LocalToComponentSpace_74F7DBDF4979F7AEE0F89C8E92AC80C7; 
	struct FAnimNode_ConvertComponentToLocalSpace      AnimGraphNode_ComponentToLocalSpace_E12EACC24A3741CEEB07219D045C2145; 
	struct FAnimNode_ModifyBone                        AnimGraphNode_ModifyBone_7594665B453619945A04B9A45B53D8E5; 
	struct FAnimNode_ModifyBone                        AnimGraphNode_ModifyBone_103CE9D54941589FEC28F8A82AC2C65D; 
	struct FAnimParamFloat                             AimOffsetPitch;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("AnimBlueprintGeneratedClass FireworksGatlinAnimBP.FireworksGatlinAnimBP_C");
		return pStaticClass;
	}


	void EvaluateGraphExposedInputs_ExecuteUbergraph_FireworksGatlinAnimBP_AnimGraphNode_ModifyBone_103CE9D54941589FEC28F8A82AC2C65D();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_FireworksGatlinAnimBP_AnimGraphNode_ModifyBone_7594665B453619945A04B9A45B53D8E5();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_FireworksGatlinAnimBP_AnimGraphNode_ModifyBone_76F3E93741D1EE0080E835BF9141B6D5();
	void ExecuteUbergraph_FireworksGatlinAnimBP(int EntryPoint);
};


}

