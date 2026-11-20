// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UGooglePADFunctionLibrary_ShowCellularDataConfirmation_Params
{
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_RequestRemoval_Params
{
	struct FString                                     Name;                                                      
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_RequestInfo_Params
{
	TArray<struct FString>                             AssetPacks;                                                
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_RequestDownload_Params
{
	TArray<struct FString>                             AssetPacks;                                                
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_ReleaseDownloadState_Params
{
	int                                                State;                                                     
};

 
struct UGooglePADFunctionLibrary_ReleaseAssetPackLocation_Params
{
	int                                                Location;                                                  
};

 
struct UGooglePADFunctionLibrary_GetTotalBytesToDownload_Params
{
	int                                                State;                                                     
	int                                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetStorageMethod_Params
{
	int                                                Location;                                                  
	EGooglePADStorageMethod                            ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetShowCellularDataConfirmationStatus_Params
{
	EGooglePADCellularDataConfirmStatus                status;                                                    
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetDownloadStatus_Params
{
	int                                                State;                                                     
	EGooglePADDownloadStatus                           ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetDownloadState_Params
{
	struct FString                                     Name;                                                      
	int                                                State;                                                     
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetBytesDownloaded_Params
{
	int                                                State;                                                     
	int                                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetAssetsPath_Params
{
	int                                                Location;                                                  
	struct FString                                     ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_GetAssetPackLocation_Params
{
	struct FString                                     Name;                                                      
	int                                                Location;                                                  
	EGooglePADErrorCode                                ReturnValue;                                               
};

 
struct UGooglePADFunctionLibrary_CancelDownload_Params
{
	TArray<struct FString>                             AssetPacks;                                                
	EGooglePADErrorCode                                ReturnValue;                                               
};

}

