// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
#include "../SDK.hpp"

namespace SDK
{
 
 
 

 
struct UCustomMeshLoaderBPLibrary_LoadSModelFromMemory_Params
{
	TArray<unsigned char>                              Data;                                                      
	struct FString                                     MeshName;                                                  
	TArray<class UMaterialInstance*>                   Materials;                                                 
	class UStaticMesh*                                 ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_LoadSModelFileAsync_Params
{
	struct FString                                     FilePath;                                                  
	struct FString                                     MeshName;                                                  
	struct FScriptDelegate                             OnComplete;                                                
};

 
struct UCustomMeshLoaderBPLibrary_LoadSModelFile_Params
{
	struct FString                                     FilePath;                                                  
	struct FString                                     MeshName;                                                  
	class UStaticMesh*                                 ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_LoadSKModelFromMemory_Params
{
	TArray<unsigned char>                              Data;                                                      
	struct FString                                     MeshName;                                                  
	TArray<class UMaterialInterface*>                  Materials;                                                 
	class USkeletalMesh*                               ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_LoadSKModelFileToAsset_Params
{
	struct FString                                     FilePath;                                                  
	struct FString                                     AssetPath;                                                 
	TArray<class UMaterialInterface*>                  Materials;                                                 
	class USkeletalMesh*                               ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_LoadSKModelFile_Params
{
	struct FString                                     FilePath;                                                  
	struct FString                                     MeshName;                                                  
	TArray<class UMaterialInterface*>                  Materials;                                                 
	class USkeletalMesh*                               ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_IsValidSModelFile_Params
{
	struct FString                                     FilePath;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_IsValidSKModelFile_Params
{
	struct FString                                     FilePath;                                                  
	bool                                               ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_GetSModelFileInfo_Params
{
	struct FString                                     FilePath;                                                  
	int                                                OutSectionCount;                                           
	int                                                OutMaterialCount;                                          
	int                                                OutVertexCount;                                            
	bool                                               ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpStaticMeshVertexDataByPath_Params
{
	struct FString                                     MeshAssetPath;                                             
	struct FString                                     OutputFilePath;                                            
	int                                                LODIndex;                                                  
	int                                                MaxVertices;                                               
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpStaticMeshVertexData_Params
{
	class UStaticMesh*                                 Mesh;                                                      
	struct FString                                     OutputFilePath;                                            
	int                                                LODIndex;                                                  
	int                                                MaxVertices;                                               
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpSKModelVertexData_Params
{
	struct FString                                     SKModelPath;                                               
	struct FString                                     OutputFilePath;                                            
	int                                                LODIndex;                                                  
	int                                                MaxVertices;                                               
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpSkeletonDataFromMesh_Params
{
	class USkeletalMesh*                               Mesh;                                                      
	struct FString                                     OutputFilePath;                                            
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpSkeletonData_Params
{
	class USkeleton*                                   Skeleton;                                                  
	struct FString                                     OutputFilePath;                                            
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpSkeletalMeshVertexDataByPath_Params
{
	struct FString                                     MeshAssetPath;                                             
	struct FString                                     OutputFilePath;                                            
	int                                                LODIndex;                                                  
	int                                                MaxVertices;                                               
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpSkeletalMeshVertexData_Params
{
	class USkeletalMesh*                               Mesh;                                                      
	struct FString                                     OutputFilePath;                                            
	int                                                LODIndex;                                                  
	int                                                MaxVertices;                                               
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpAnimSequenceDataByPath_Params
{
	struct FString                                     AnimAssetPath;                                             
	struct FString                                     OutputFilePath;                                            
	struct FString                                     ReturnValue;                                               
};

 
struct UCustomMeshLoaderBPLibrary_DumpAnimSequenceData_Params
{
	class UAnimSequence*                               AnimSequence;                                              
	struct FString                                     OutputFilePath;                                            
	struct FString                                     ReturnValue;                                               
};

}

