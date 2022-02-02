// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyNEWWWActor.generated.h"

UCLASS()
class CPP_TEST_API AMyNEWWWActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyNEWWWActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere) //it means unreal property
	UStaticMeshComponent* Mesh; //pointer meter
	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 HP;
	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 MP; 


};
  