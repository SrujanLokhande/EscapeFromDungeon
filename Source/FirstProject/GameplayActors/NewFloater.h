// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewFloater.generated.h"

UCLASS()
class FIRSTPROJECT_API ANewFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewFloater();

	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;


	//Location used by SetActorLocation() when Beginplay() is called
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	FVector InitialLocation;

	// Location of the actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	FVector PlacedLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Floater Variables")
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere , BlueprintReadOnly, Category = "Floater Variables")
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly ,BlueprintReadWrite, Category = "Floater Variables")
	bool bInitializeFloaterLocations;

	UPROPERTY(EditInstanceOnly ,BlueprintReadWrite, Category = "Floater Variables")
	FVector InitialForce;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	FVector InitialTorque;

private:

		float RunningTime;
		float BaseZLocation;


public:
		//Amplitude how much we oscillate up an down
		UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Floater Variables")
		float A;


		//Period = 2*PI/ABS(B)
		UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Floater Variables")
		float B;

		//Phase Shift is C / B
		UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Floater Variables")
		float C;

		//Vertical Shift is D (vertical distance )
		UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Floater Variables")
		float D;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
