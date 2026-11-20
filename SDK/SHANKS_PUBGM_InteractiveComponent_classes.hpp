// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UInteractiveComponent_C : public UInteractiveComponentBase
{
public:
	struct FSoftObjectPath                             BtnImage;                                                  
	int                                                TextId;                                                    
	unsigned char                                      UnknownData00[0x4];                                        
	struct FSoftObjectPath                             DisabledMaterial;                                          
	struct FSoftObjectPath                             DefaultMaterial;                                           
	struct FSoftObjectPath                             AudioEvent;                                                
	bool                                               AutoStandWhenInteract;                                     
	bool                                               bShowGuide;                                                
	unsigned char                                      UnknownData01[0x2];                                        
	int                                                ButtonPriority;                                            

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass InteractiveComponent.InteractiveComponent_C");
		return pStaticClass;
	}

};


}

