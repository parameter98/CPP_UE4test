// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNEWWWActor.h"

// Sets default values
AMyNEWWWActor::AMyNEWWWActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyNEWWWActor::BeginPlay()
{
	Super::BeginPlay();

	// category �̸� ,verbosity �߿䵵 �α����, ���� , ����
	UE_LOG(LogTemp,Error, TEXT("BeginPlay %d"), 3);
	
}

// Called every frame
void AMyNEWWWActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// category �� ���ϸ� �� category�θ� log�� �� �� ����.
	UE_LOG(LogTemp,Warning,TEXT("Logging now %f"),DeltaTime);

}

