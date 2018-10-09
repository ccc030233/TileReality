//
// Copyright 2018 Adam Horvath - AR.UPLUGINS.COM - info@uplugins.com - All Rights Reserved.
//

#pragma once

#include "ARToolkitFunctionLibrary.h"
#include "ARToolkitComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FMarkerLoadedDelegate, const FString, MarkerName, const uint8, Number, const uint8, TotalNumber, const FString, MarkerType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNFTCompleteDelegate);

UCLASS(ClassGroup = ARToolkit, BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class UARToolkitComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()
		

public:
	
	
	


	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetMarker(uint8 markerId, FVector& Position, FRotator& Rotation, FVector& CameraPosition, FRotator& CameraRotation, bool& Visible);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetMarkerNFT(uint8 markerId, FVector& Position, FRotator& Rotation, FVector& CameraPosition, FRotator& CameraRotation,bool& Visible);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetMarkerMATRIX(uint8 markerId, FVector& Position, FRotator& Rotation, FVector& CameraPosition, FRotator& CameraRotation, bool& Visible);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	UTexture2D* GetCameraFrame();

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	bool Init(bool showPIN, uint8 devNum, EDeviceOrientation deviceOrientation,EArPatternDetectionMode detectionMode, int32& WebcamResX, int32& WebcamResY, bool&FirstRunIOS);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void Cleanup();

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void SetDebugMode(bool DebugMode);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void SetThresholdMode(EArLabelingThresholdMode mode);
	
	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void SetFilter(bool enabled, uint8 sampleRate, uint8 cutOffFreq);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetFilter(bool& enabled, uint8& sampleRate, uint8& cutOffFreq);
    
	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void SetThreshold(uint8 threshold);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetThreshold(uint8& threshold);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetCameraResolution(int32& WebcamResX, int32& WebcamResY);

	
	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetRelativeTransformation(uint8 MarkerID1, uint8 MarkerID2, FVector& RelativePos, FRotator& RelativeRot, bool& result);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void GetRelativeTransformationNFT(uint8 MarkerID1, uint8 MarkerID_NFT, FVector& RelativePos, FRotator& RelativeRot, bool& result);

    UFUNCTION(BlueprintCallable, Category = ARToolkit)
    void TogglePause();

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	bool LoadMarkers(TArray<FString> markers);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	bool LoadMarkersNFT(TArray<FString> markers);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	UMaterialInstanceDynamic* CreateDynamicMaterialInstance(UStaticMeshComponent* Mesh, UMaterial* SourceMaterial);

	UFUNCTION(BlueprintCallable, Category = ARToolkit)
	void SetTextureParameterValue(UMaterialInstanceDynamic* SourceMaterial, UTexture2D* Texture, FName Param);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = ARToolkit)
	EDeviceOrientation GetDeviceOrientation();

	UPROPERTY(BlueprintAssignable, Category = ARToolkit)
    FMarkerLoadedDelegate OnMarkerLoaded;

	UPROPERTY(BlueprintAssignable, Category = ARToolkit)
	FNFTCompleteDelegate OnNFTReady;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);
	
	
	
protected:

	void ProcessMarker(FMarker* marker, FVector& Position, FRotator& Rotation, FVector& CameraPosition, FRotator& CameraRotation, bool& Visible);
	
};
