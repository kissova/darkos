// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UGlobalBattleUIFunctionLibrary_C_GetPlayerTeamColor_Params
{
	int                                                Index;                                                     
	class UObject*                                     __WorldContext;                                            
	struct FLinearColor                                Result;                                                    
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetAudioIDSignType_Params
{
	class UObject*                                     WorldContext;                                              
	int                                                actorid;                                                   
	int                                                SignType;                                                  
	class UObject*                                     __WorldContext;                                            
	int                                                audioID;                                                   
};

 
struct UGlobalBattleUIFunctionLibrary_C_IsBankExistByActorID_Params
{
	class UObject*                                     WorldContext;                                              
	int                                                actorid;                                                   
	class UObject*                                     __WorldContext;                                            
	bool                                               bExist;                                                    
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetButtomQualityPath_Params
{
	int                                                Quality;                                                   
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Path;                                                      
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetBgQualityPath_Params
{
	int                                                Quality;                                                   
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Path;                                                      
};

 
struct UGlobalBattleUIFunctionLibrary_C_IsCustomUIDataValid_Params
{
	class UWidget*                                     Widget;                                                    
	struct FVector2D                                   SaveDateSize;                                              
	class UObject*                                     __WorldContext;                                            
	bool                                               IsValid;                                                   
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetDurabilityColorConfig_Params
{
	int                                                Durability;                                                
	int                                                MaxDurability;                                             
	class UObject*                                     __WorldContext;                                            
	struct FSlateColor                                 OutColor;                                                  
	int                                                status;                                                    
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetQuickSignText_Params
{
	class UObject*                                     WorldContext;                                              
	int                                                SignType;                                                  
	int                                                actorid;                                                   
	class UObject*                                     __WorldContext;                                            
	int                                                TextId;                                                    
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetLocalizeVoiceText_Params
{
	struct FString                                     Key;                                                       
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Text;                                                      
};

 
struct UGlobalBattleUIFunctionLibrary_C_Get3DTouchSwitch_Params
{
	class UObject*                                     __WorldContext;                                            
	bool                                               TouchSwitch;                                               
};

 
struct UGlobalBattleUIFunctionLibrary_C_Get3DTouchValue_Params
{
	class UObject*                                     __WorldContext;                                            
	float                                              TouchValue;                                                
};

 
struct UGlobalBattleUIFunctionLibrary_C_IsIOSOneGigabyteDevice_Params
{
	class UObject*                                     __WorldContext;                                            
	bool                                               Output;                                                    
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetLocalizeBattleText_Params
{
	struct FString                                     Key;                                                       
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Text;                                                      
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetReportBugSwitch_Params
{
	class UObject*                                     __WorldContext;                                            
	bool                                               Ret;                                                       
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetSelfieSwitch_Params
{
	class UObject*                                     __WorldContext;                                            
	bool                                               Ret;                                                       
};

 
struct UGlobalBattleUIFunctionLibrary_C_ShowGender_Params
{
	class UObject*                                     __WorldContext;                                            
	bool                                               BShowGender;                                               
};

 
struct UGlobalBattleUIFunctionLibrary_C_IsWidgetVisible_Params
{
	class UWidget*                                     Widget;                                                    
	class UObject*                                     __WorldContext;                                            
	bool                                               Visible;                                                   
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetTimeByInt_Params
{
	int                                                second_;                                                   
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Time;                                                      
};

 
struct UGlobalBattleUIFunctionLibrary_C_SetImageWithSpriteResInBattle_Params
{
	struct FString                                     ResPath;                                                   
	class UImage*                                      Image;                                                     
	class UObject*                                     __WorldContext;                                            
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetNationInfoInBattle_Params
{
	struct FString                                     NationCode;                                                
	class UObject*                                     __WorldContext;                                            
	struct FBP_STRUCT_RegionConfig_type                NationInfo;                                                
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetNationSwitch_Params
{
	struct FString                                     Name;                                                      
	class UObject*                                     __WorldContext;                                            
	bool                                               Ret;                                                       
};

 
struct UGlobalBattleUIFunctionLibrary_C_CreateUAEUserWidget_Params
{
	class UClass*                                      Class;                                                     
	class UUAEUserWidget*                              Parent;                                                    
	class UObject*                                     __WorldContext;                                            
	class UUAEUserWidget*                              Widget;                                                    
};

 
struct UGlobalBattleUIFunctionLibrary_C_GetLocalizeText_Params
{
	struct FString                                     Key;                                                       
	class UObject*                                     __WorldContext;                                            
	struct FString                                     Text;                                                      
};

}

