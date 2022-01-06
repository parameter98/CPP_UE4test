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

	// category 이름 ,verbosity 중요도 로깅수준, 형식 , 인자
	UE_LOG(LogTemp,Error, TEXT("BeginPlay %d"), 3);
	
}

// Called every frame
void AMyNEWWWActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// category 를 정하면 그 category로만 log를 쓸 수 있음.
	UE_LOG(LogTemp,Warning,TEXT("Logging now %f"),DeltaTime);

}

