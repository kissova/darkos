// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAndroidCommonDeviceProfileGradeScore : public UObject
{
public:
	int                                                MaxScore;                                                  
	unsigned char                                      UnknownData00[0x4];                                        
	TArray<struct FGradeScoreProfileName>              GradeScoreProfileName;                                     
	TArray<float>                                      GradeScoreTypePercentage;                                  

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidCommonDeviceProfileGradeScore");
		return pStaticClass;
	}

};


 
 
class UAndroidCommonDeviceProfileMatchingRules : public UObject
{
public:
	TArray<struct FGradeProfileMatch>                  GradeMatchProfile;                                         

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidCommonDeviceProfileMatchingRules");
		return pStaticClass;
	}

};


 
 
class UAndroidCommonDeviceProfileVulkanBlackList : public UObject
{
public:
	TArray<struct FProfileMatch>                       VulkanList;                                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidCommonDeviceProfileVulkanBlackList");
		return pStaticClass;
	}

};


 
 
class UAndroidCommonDeviceProfileVulkanWhiteList : public UObject
{
public:
	TArray<struct FProfileMatch>                       VulkanList;                                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidCommonDeviceProfileVulkanWhiteList");
		return pStaticClass;
	}

};


 
 
class UAndroidCommonDeviceProfileWhiteList : public UObject
{
public:
	TArray<struct FProfileMatch>                       GradeMatchProfileWhiteList;                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidCommonDeviceProfileWhiteList");
		return pStaticClass;
	}

};


 
 
class UAndroidDeviceProfileMatchingRules : public UObject
{
public:
	TArray<struct FProfileMatch>                       MatchProfile;                                              

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidDeviceProfileMatchingRules");
		return pStaticClass;
	}

};


 
 
class UAndroidJavaSurfaceViewDevices : public UObject
{
public:
	TArray<struct FJavaSurfaceViewDevice>              SurfaceViewDevices;                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidJavaSurfaceViewDevices");
		return pStaticClass;
	}

};


 
 
class UAndroidProjectDeviceProfileWhiteList : public UObject
{
public:
	TArray<struct FProfileMatch>                       GradeMatchProfileWhiteList;                                

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidDeviceProfileSelector.AndroidProjectDeviceProfileWhiteList");
		return pStaticClass;
	}

};


}

