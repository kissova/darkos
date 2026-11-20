// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
enum class ECompareType : uint8_t
{
	CMP_Equal                      = 0,
	CMP_Less                       = 1,
	CMP_LessEqual                  = 2,
	CMP_Greater                    = 3,
	CMP_GreaterEqual               = 4,
	CMP_NotEqual                   = 5,
	CMP_Regex                      = 6,
	CMP_MAX                        = 7
};


 
enum class ESourceType : uint8_t
{
	SRC_PreviousRegexMatch         = 0,
	SRC_GpuFamily                  = 1,
	SRC_GlVersion                  = 2,
	SRC_AndroidVersion             = 3,
	SRC_DeviceMake                 = 4,
	SRC_DeviceModel                = 5,
	SRC_VulkanVersion              = 6,
	SRC_UsingHoudini               = 7,
	SRC_VulkanAvailable            = 8,
	SRC_MemorySizeInGB             = 9,
	SRC_CPUCoreNum                 = 10,
	SRC_CPUMaxFreq                 = 11,
	SRC_GLExtensions               = 12,
	SRC_BrandROMVersion            = 13,
	SRC_VulkanVendorID             = 14,
	SRC_VulkanDriverVersion        = 15,
	SRC_VulkanApiVersion           = 16,
	SRC_MainBroadInfo              = 17,
	SRC_SocName                    = 18,
	SRC_Chipset                    = 19,
	SRC_MAX                        = 20
};


 
enum class EGradeScoreType : uint8_t
{
	GST_GPU                        = 0,
	GST_Memory                     = 1,
	GST_CPUCore                    = 2,
	GST_CPUFreq                    = 3,
	GST_MAX                        = 4
};


 
enum class EGradeType : uint8_t
{
	GAT_Grade01                    = 0,
	GAT_Grade02                    = 1,
	GAT_Grade03                    = 2,
	GAT_Grade04                    = 3,
	GAT_Grade05                    = 4,
	GAT_Grade06                    = 5,
	GAT_Grade07                    = 6,
	GAT_MAX                        = 7
};



 
 
 

 
 
struct FGradeScoreProfileName
{
	struct FString                                     ProfileName;                                               
	int                                                Score;                                                     
	unsigned char                                      UnknownData00[0x4];                                        
};

 
 
struct FGradeProfileMatchItem
{
	TEnumAsByte<ESourceType>                           SourceType;                                                
	TEnumAsByte<ECompareType>                          CompareType;                                               
	unsigned char                                      UnknownData00[0x6];                                        
	struct FString                                     MatchString;                                               
};

 
 
struct FGradeProfileMatch
{
	TEnumAsByte<EGradeScoreType>                       ScoreType;                                                 
	unsigned char                                      UnknownData00[0x3];                                        
	int                                                Score;                                                     
	TArray<struct FGradeProfileMatchItem>              Match;                                                     
};

 
 
struct FProfileMatchItem
{
	TEnumAsByte<ESourceType>                           SourceType;                                                
	TEnumAsByte<ECompareType>                          CompareType;                                               
	unsigned char                                      UnknownData00[0x6];                                        
	struct FString                                     MatchString;                                               
};

 
 
struct FProfileMatch
{
	struct FString                                     Profile;                                                   
	TArray<struct FProfileMatchItem>                   Match;                                                     
};

 
 
struct FJavaSurfaceViewDevice
{
	struct FString                                     Manufacturer;                                              
	struct FString                                     Model;                                                     
};

}

