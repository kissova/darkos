// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UPlayerEventForPet_C : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass PlayerEventForPet.PlayerEventForPet_C");
		return pStaticClass;
	}


	void PlayerStateChange(EPawnState State, TEnumAsByte<EPawnStateChangeType> ChangeType);
};


}

