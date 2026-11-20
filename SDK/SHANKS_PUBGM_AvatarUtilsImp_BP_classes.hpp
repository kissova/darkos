// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAvatarUtilsImp_BP_C : public UAvatarBPUtils
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass AvatarUtilsImp_BP.AvatarUtilsImp_BP_C");
		return pStaticClass;
	}


	int GetAdjustWeaponBPID_Lobby(int* WeaponId);
	bool GetVehicleDefaultStyleID(int* InVehicleSkinID, TArray<int>* OutStyleIDList);
	struct FString GetVehicleBPPathBySkinID(int* InVehicleSkinID);
	int GetVehicleShapeBySkinID(int* InVehicleSkinID);
	void GetBPTableName(int Type, int TypeSpecificID, struct FString* BPTableName, int* SpecificID);
	class UItemHandleBase* CreateAvatarHandle(struct FItemDefineID* DefineID, class UObject** Outer, bool* bLobby);
	struct FString GetAvatarHandlePath(struct FItemDefineID* DefineID, bool* bLobby);
};


}

