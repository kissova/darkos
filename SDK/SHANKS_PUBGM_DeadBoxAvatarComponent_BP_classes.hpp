// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UDeadBoxAvatarComponent_BP_C : public UDeadBoxAvatarComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass DeadBoxAvatarComponent_BP.DeadBoxAvatarComponent_BP_C");
		return pStaticClass;
	}


	void GetVehicleDiedPath(int ItemId, struct FString* Path);
	void IsVehicleAvatarID(int ItemId, bool* IsVehicleAvatarID);
	struct FString GetItemAvatarHandlePath(int* ItemId);
	class UBackpackCommonAvatarHandle* GetItemAvatarHandle(int* ItemId);
};


}

