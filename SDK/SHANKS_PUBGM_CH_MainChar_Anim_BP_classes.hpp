// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCH_MainChar_Anim_BP_C : public UMainCharAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FAnimNode_Root                              AnimGraphNode_Root_29FBB5C84AA95043DE3725AA9FAB5D9B;       
	bool                                               __SUBINSTANCE_bIsFPPAnimInstace_1E6668964E4BAA438CD5A3958631C7E0; 
	unsigned char                                      UnknownData00[0x7];                                        
	struct FAnimNode_SubInstance                       AnimGraphNode_SubInstance_1E6668964E4BAA438CD5A3958631C7E0; 
	bool                                               __SUBINSTANCE_bIsFPPAnimInstace_C9C6D110426F05EEF79F0EA47F0A00F3; 
	unsigned char                                      UnknownData01[0x7];                                        
	struct FAnimNode_SubInstance                       AnimGraphNode_SubInstance_C9C6D110426F05EEF79F0EA47F0A00F3; 
	struct FAnimNode_BlendListByBool                   AnimGraphNode_BlendListByBool_2E47FBFF49F72ABC9D5C60B35FCBF042; 
	struct FAnimNode_Slot                              AnimGraphNode_Slot_BB6C36284ACBE90B274152B2D2F8DBA6;       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("AnimBlueprintGeneratedClass CH_MainChar_Anim_BP.CH_MainChar_Anim_BP_C");
		return pStaticClass;
	}


	void EvaluateGraphExposedInputs_ExecuteUbergraph_CH_MainChar_Anim_BP_AnimGraphNode_BlendListByBool_2E47FBFF49F72ABC9D5C60B35FCBF042();
	void ExecuteUbergraph_CH_MainChar_Anim_BP(int EntryPoint);
};


}

