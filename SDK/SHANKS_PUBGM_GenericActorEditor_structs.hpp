// HMOOD__TG@i_8_f
 

#pragma once

 
 
 
 
namespace SDK
{
 
 
 

 
 
struct FActorEditorCharacterMovementSyncData
{
	float                                              MaxAcceleration;                                           
	float                                              BrakingFriction;                                           
	float                                              MaxWalkSpeed;                                              
	float                                              MaxWalkSpeedCrouched;                                      
	float                                              MaxSwimSpeed;                                              
	float                                              MaxFlySpeed;                                               
	float                                              MaxCustomMovementSpeed;                                    
	float                                              JumpZVelocity;                                             
	float                                              GravityScale;                                              
	float                                              AirControl;                                                
	float                                              FallingLateralFriction;                                    
	float                                              BrakingDecelerationWalking;                                
	float                                              BrakingDecelerationFalling;                                
	float                                              BrakingDecelerationFlying;                                 
	float                                              BrakingDecelerationSwimming;                               
	float                                              GroundFriction;                                            
	bool                                               bOrientRotationToMovement;                                 
	bool                                               bUseControllerDesiredRotation;                             
	unsigned char                                      UnknownData00[0x2];                                        
	struct FRotator                                    RotationRate;                                              
};

}

