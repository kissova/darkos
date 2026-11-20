// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
class UAndroidMediaSettings : public UObject
{
public:
	bool                                               CacheableVideoSampleBuffers;                               
	unsigned char                                      UnknownData00[0x7];                                        

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AndroidMediaFactory.AndroidMediaSettings");
		return pStaticClass;
	}

};


}

