// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UCreativeBridgeLuaVM : public UCreativeLuaVM
{
public:
	unsigned char                                      UnknownData00[0x8];                                        
	class UObject*                                     LuaVMManager;                                              
	struct FString                                     RegisterUGCVMFunctionHandlerName;                          
	struct FString                                     UGCVMPostInitFunctionHandlerName;                          

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CreativeLua.CreativeBridgeLuaVM");
		return pStaticClass;
	}


	void UGCLuaError(int ErrCode);
	void SetUGCSuspendStateFix(bool bEnable);
	void RegisterSluaCallUgcluaEventHandler();
	void PostInit();
	bool GetUGCSuspendStateFix();
};


 
 
class UCreativeEnvLuaVM : public UObject
{
public:
	unsigned char                                      UnknownData00[0x58];                                       

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CreativeLua.CreativeEnvLuaVM");
		return pStaticClass;
	}

};


 
 
class UCreativeEnvLuaVMFactory : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CreativeLua.CreativeEnvLuaVMFactory");
		return pStaticClass;
	}


	static class UCreativeEnvLuaVM* CreateCreativeEnvLuaVM(const struct FString& InLuaFilePath, class UObject* WorldContextObject);
};


}

