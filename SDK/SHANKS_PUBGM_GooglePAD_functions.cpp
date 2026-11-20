// HMOOD__TG@i_8_f
 

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::ShowCellularDataConfirmation()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.ShowCellularDataConfirmation");

	UGooglePADFunctionLibrary_ShowCellularDataConfirmation_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::RequestRemoval(const struct FString& Name)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.RequestRemoval");

	UGooglePADFunctionLibrary_RequestRemoval_Params params;
	params.Name = Name;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::RequestInfo(TArray<struct FString> AssetPacks)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.RequestInfo");

	UGooglePADFunctionLibrary_RequestInfo_Params params;
	params.AssetPacks = AssetPacks;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::RequestDownload(TArray<struct FString> AssetPacks)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.RequestDownload");

	UGooglePADFunctionLibrary_RequestDownload_Params params;
	params.AssetPacks = AssetPacks;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 

void UGooglePADFunctionLibrary::ReleaseDownloadState(int State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.ReleaseDownloadState");

	UGooglePADFunctionLibrary_ReleaseDownloadState_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 

void UGooglePADFunctionLibrary::ReleaseAssetPackLocation(int Location)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.ReleaseAssetPackLocation");

	UGooglePADFunctionLibrary_ReleaseAssetPackLocation_Params params;
	params.Location = Location;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


 
 
 
 
 

int UGooglePADFunctionLibrary::GetTotalBytesToDownload(int State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetTotalBytesToDownload");

	UGooglePADFunctionLibrary_GetTotalBytesToDownload_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADStorageMethod UGooglePADFunctionLibrary::GetStorageMethod(int Location)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetStorageMethod");

	UGooglePADFunctionLibrary_GetStorageMethod_Params params;
	params.Location = Location;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::GetShowCellularDataConfirmationStatus(EGooglePADCellularDataConfirmStatus* status)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetShowCellularDataConfirmationStatus");

	UGooglePADFunctionLibrary_GetShowCellularDataConfirmationStatus_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (status != nullptr)
		*status = params.status;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADDownloadStatus UGooglePADFunctionLibrary::GetDownloadStatus(int State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetDownloadStatus");

	UGooglePADFunctionLibrary_GetDownloadStatus_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::GetDownloadState(const struct FString& Name, int* State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetDownloadState");

	UGooglePADFunctionLibrary_GetDownloadState_Params params;
	params.Name = Name;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (State != nullptr)
		*State = params.State;

	return params.ReturnValue;
}


 
 
 
 
 

int UGooglePADFunctionLibrary::GetBytesDownloaded(int State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetBytesDownloaded");

	UGooglePADFunctionLibrary_GetBytesDownloaded_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 

struct FString UGooglePADFunctionLibrary::GetAssetsPath(int Location)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetAssetsPath");

	UGooglePADFunctionLibrary_GetAssetsPath_Params params;
	params.Location = Location;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


 
 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::GetAssetPackLocation(const struct FString& Name, int* Location)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.GetAssetPackLocation");

	UGooglePADFunctionLibrary_GetAssetPackLocation_Params params;
	params.Name = Name;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Location != nullptr)
		*Location = params.Location;

	return params.ReturnValue;
}


 
 
 
 
 

EGooglePADErrorCode UGooglePADFunctionLibrary::CancelDownload(TArray<struct FString> AssetPacks)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GooglePAD.GooglePADFunctionLibrary.CancelDownload");

	UGooglePADFunctionLibrary_CancelDownload_Params params;
	params.AssetPacks = AssetPacks;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

