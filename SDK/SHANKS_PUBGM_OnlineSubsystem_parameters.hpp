// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UTurnBasedMatchInterface_OnMatchReceivedTurn_Params
{
	struct FString                                     Match;                                                     
	bool                                               bDidBecomeActive;                                          
};

 
struct UTurnBasedMatchInterface_OnMatchEnded_Params
{
	struct FString                                     Match;                                                     
};

}

