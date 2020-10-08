﻿// Copyright 2020 Yevhenii Selivanov

#pragma once

#include "Camera/CameraComponent.h"
#include "Bomber.h"
//---
#include "MyCameraComponent.generated.h"

/**
 * The main camera viewpoint of the game.
 */
UCLASS()
class BOMBER_API UMyCameraComponent final : public UCameraComponent
{
	GENERATED_BODY()

public:
	/** The minimal camera height. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++")
	float MinHeight = 1500.f; //[N]

	/** Sets default values for this actor's properties. */
	UMyCameraComponent();

	/** Set the maximum possible height. Called on construct and game start*/
	UFUNCTION(BlueprintCallable, Category = "C++")
    void UpdateMaxHeight();

	/**
	 * Set the location between players.
	 * @param DeltaTime Optional parameter, lerp if specified
	 * @return true for successful update
	 */
	UFUNCTION(BlueprintCallable, Category = "C++")
	bool UpdateLocation(float DeltaTime = 0.f);

protected:
	/** The maximal camera height. Is set dynamically by UMyCameraComponent::UpdateMaxHeights(). */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "C++", meta = (BlueprintProtected, DisplayName = "Max Height"))
	float MaxHeightInternal;//[G]

	/** Called every frame. */
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	/** Called when the game starts or when spawned. */
	virtual void BeginPlay() override;

	/** */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++", meta = (BlueprintProtected))
    void OnGameStateChanged(ECurrentGameState CurrentGameState);
};
