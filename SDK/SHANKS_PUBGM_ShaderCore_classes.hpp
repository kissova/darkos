// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPrecompileShaderGameConfig : public UObject
{
public:
	TArray<struct FCollectSwitchs>                     CollectSwitchs;                                            
	TArray<struct FDeviceRenderConfig>                 DeviceRenderConfigs;                                       
	TArray<struct FMapRenderConfig>                    MapRenderConfigs;                                          
	unsigned char                                      UnknownData00[0x18];                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ShaderCore.PrecompileShaderGameConfig");
		return pStaticClass;
	}

};


 
 
class UShaderGroupSettings : public UObject
{
public:
	unsigned char                                      UnknownData00[0x28];                                       
	TArray<struct FShaderLevel>                        Levels_IOS;                                                
	TArray<struct FShaderLevel>                        Levels_AOS;                                                
	TArray<struct FShaderPak>                          Paks_IOS;                                                  
	TArray<struct FShaderPak>                          Paks_AOS;                                                  
	TArray<struct FShaderPak>                          Paks_PC;                                                   
	unsigned char                                      UnknownData01[0x28];                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ShaderCore.ShaderGroupSettings");
		return pStaticClass;
	}

};


}

