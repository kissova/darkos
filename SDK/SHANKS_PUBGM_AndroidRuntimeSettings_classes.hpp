// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAndroidRuntimeSettings : public UObject
{
public:
	struct FString                                     PackageName;                                               
	int                                                StoreVersion;                                              
	unsigned char                                      UnknownData00[0x4];                                        
	struct FString                                     ApplicationDisplayName;                                    
	struct FString                                     VersionDisplayName;                                        
	int                                                MinSDKVersion;                                             
	int                                                TargetSDKVersion;                                          
	TEnumAsByte<EAndroidInstallLocation>               InstallLocation;                                           
	bool                                               bEnableGradle;                                             
	bool                                               bPackageDataInsideApk;                                     
	bool                                               bCreateAllPlatformsInstall;                                
	bool                                               bDisableVerifyOBBOnStartUp;                                
	bool                                               bUseExternalFilesDir;                                      
	TEnumAsByte<EAndroidScreenOrientation>             Orientation;                                               
	unsigned char                                      UnknownData01[0x1];                                        
	float                                              MaxAspectRatio;                                            
	TEnumAsByte<EAndroidAntVerbosity>                  AntVerbosity;                                              
	bool                                               bFullScreen;                                               
	bool                                               bEnableNewKeyboard;                                        
	TEnumAsByte<EAndroidDepthBufferPreference>         DepthBufferPreference;                                     
	TArray<struct FString>                             ExtraManifestNodeTags;                                     
	TArray<struct FString>                             ExtraApplicationNodeTags;                                  
	struct FString                                     ExtraApplicationSettings;                                  
	TArray<struct FString>                             ExtraActivityNodeTags;                                     
	struct FString                                     ExtraActivitySettings;                                     
	TArray<struct FString>                             ExtraPermissions;                                          
	bool                                               bAndroidVoiceEnabled;                                      
	bool                                               bPackageForGearVR;                                         
	bool                                               bRemoveOSIG;                                               
	unsigned char                                      UnknownData02[0x5];                                        
	TArray<TEnumAsByte<EGoogleVRCaps>>                 GoogleVRCaps;                                              
	bool                                               bGoogleVRSustainedPerformance;                             
	unsigned char                                      UnknownData03[0x7];                                        
	struct FString                                     KeyStore;                                                  
	struct FString                                     KeyAlias;                                                  
	struct FString                                     KeyStorePassword;                                          
	struct FString                                     KeyPassword;                                               
	bool                                               bBuildForArmV7;                                            
	bool                                               bBuildForArm64;                                            
	bool                                               bBuildForX86;                                              
	bool                                               bBuildForX8664;                                            
	bool                                               bBuildForES2;                                              
	bool                                               bBuildForES31;                                             
	bool                                               bSupportsVulkan;                                           
	bool                                               bBuildWithHiddenSymbolVisibility;                          
	bool                                               bEnableGooglePlaySupport;                                  
	bool                                               bUseGetAccounts;                                           
	unsigned char                                      UnknownData04[0x6];                                        
	struct FString                                     GamesAppID;                                                
	TArray<struct FGooglePlayAchievementMapping>       AchievementMap;                                            
	TArray<struct FGooglePlayLeaderboardMapping>       LeaderboardMap;                                            
	bool                                               bSupportAdMob;                                             
	unsigned char                                      UnknownData05[0x7];                                        
	struct FString                                     AdMobAdUnitID;                                             
	TArray<struct FString>                             AdMobAdUnitIDs;                                            
	struct FString                                     GooglePlayLicenseKey;                                      
	struct FString                                     GCMClientSenderID;                                         
	bool                                               bShowLaunchImage;                                          
	TEnumAsByte<EAndroidAudio>                         AndroidAudio;                                              
	unsigned char                                      UnknownData06[0x2];                                        
	int                                                AudioSampleRate;                                           
	int                                                AudioCallbackBufferFrameSize;                              
	int                                                AudioNumBuffersToEnqueue;                                  
	int                                                AudioMaxChannels;                                          
	int                                                AudioNumSourceWorkers;                                     
	struct FString                                     SpatializationPlugin;                                      
	struct FString                                     ReverbPlugin;                                              
	struct FString                                     OcclusionPlugin;                                           
	TEnumAsByte<EAndroidGraphicsDebugger>              AndroidGraphicsDebugger;                                   
	unsigned char                                      UnknownData07[0x7];                                        
	struct FDirectoryPath                              MaliGraphicsDebuggerPath;                                  
	struct FDirectoryPath                              RenderDocPath;                                             
	bool                                               bMultiTargetFormat_ETC1;                                   
	bool                                               bMultiTargetFormat_ETC2;                                   
	bool                                               bMultiTargetFormat_DXT;                                    
	bool                                               bMultiTargetFormat_PVRTC;                                  
	bool                                               bMultiTargetFormat_ATC;                                    
	bool                                               bMultiTargetFormat_ASTC;                                   
	unsigned char                                      UnknownData08[0x2];                                        
	float                                              TextureFormatPriority_ETC1;                                
	float                                              TextureFormatPriority_ETC2;                                
	float                                              TextureFormatPriority_DXT;                                 
	float                                              TextureFormatPriority_PVRTC;                               
	float                                              TextureFormatPriority_ATC;                                 
	float                                              TextureFormatPriority_ASTC;                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidRuntimeSettings.AndroidRuntimeSettings");
		return pStaticClass;
	}

};


}

