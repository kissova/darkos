// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 
 
 

void UBP_AvatarPattern_Base_C::GetPatternNumTexturePath(int* InNumID, struct FSoftObjectPath* OutTexture1, struct FSoftObjectPath* OutTexture2)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarPattern_Base.BP_AvatarPattern_Base_C.GetPatternNumTexturePath");

	UBP_AvatarPattern_Base_C_GetPatternNumTexturePath_Params params;
	params.InNumID = InNumID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutTexture1 != nullptr)
		*OutTexture1 = params.OutTexture1;
	if (OutTexture2 != nullptr)
		*OutTexture2 = params.OutTexture2;
}


 
 
 
 
 

void UBP_AvatarPattern_Base_C::SetCustomPattern_Implementation(class UMaterialInterface* InMaterial, const struct FSlotToMatPattern& InMatPattern)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarPattern_Base.BP_AvatarPattern_Base_C.SetCustomPattern_Implementation");

	UBP_AvatarPattern_Base_C_SetCustomPattern_Implementation_Params params;
	params.InMaterial = InMaterial;
	params.InMatPattern = InMatPattern;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UBP_AvatarPattern_Base_C::SetCustomPatternNum_Implementation(class UMaterialInterface* InMaterial, const struct FSlotToMatPattern& InMatPattern)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarPattern_Base.BP_AvatarPattern_Base_C.SetCustomPatternNum_Implementation");

	UBP_AvatarPattern_Base_C_SetCustomPatternNum_Implementation_Params params;
	params.InMaterial = InMaterial;
	params.InMatPattern = InMatPattern;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

void UBP_AvatarPattern_Base_C::SetCustomPatternDeffered(class UMaterialInterface** InMaterial, struct FSlotToMatPattern* InMatPattern)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarPattern_Base.BP_AvatarPattern_Base_C.SetCustomPatternDeffered");

	UBP_AvatarPattern_Base_C_SetCustomPatternDeffered_Params params;
	params.InMaterial = InMaterial;
	params.InMatPattern = InMatPattern;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UBP_AvatarPattern_Base_C::ExecuteUbergraph_BP_AvatarPattern_Base(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_AvatarPattern_Base.BP_AvatarPattern_Base_C.ExecuteUbergraph_BP_AvatarPattern_Base");

	UBP_AvatarPattern_Base_C_ExecuteUbergraph_BP_AvatarPattern_Base_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

