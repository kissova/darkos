// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UBP_Phone_Anim_C : public UAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                            
	struct FAnimNode_Root                              AnimGraphNode_Root_F915205347D80689471DF88D9872E184;       
	struct FAnimNode_Slot                              AnimGraphNode_Slot_806200C547ABA7C6C9334E8EAD357C8B;       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("AnimBlueprintGeneratedClass BP_Phone_Anim.BP_Phone_Anim_C");
		return pStaticClass;
	}


	void AnimNotify_ShowPhone();
	void ExecuteUbergraph_BP_Phone_Anim(int EntryPoint);
};


}

