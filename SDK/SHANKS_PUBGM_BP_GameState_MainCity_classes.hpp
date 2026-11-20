// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class ABP_GameState_MainCity_C : public AMainCityGameState
{
public:
	class USceneComponent*                             DefaultSceneRoot;                                          
	class ULevelDynamicComponent*                      LevelDynamic;                                              

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_GameState_MainCity.BP_GameState_MainCity_C");
		return pStaticClass;
	}


	void MulticastRPC_SwitchDS(uint64_t MulticastRPC_SwitchDS_param1);
	void MultiCast_GenericRPC(int MultiCast_GenericRPC_param1, class UObject* MultiCast_GenericRPC_param2, TArray<unsigned char> MultiCast_GenericRPC_param3);
	void __FeatureRPC_ReviveState_MulticastRevivalTimeEnd__();
	void __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua__(const struct FFatalDamageParameterCompress& __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param1, TArray<unsigned char> __FeatureRPC_FatalDamageFeature_MulticastRPC_BroadcastFatalDamageToClientForLua___param2);
	void UserConstructionScript();
};


}

