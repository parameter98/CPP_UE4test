// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis("Pitch", this, &AMyPawn::Pitch);
	PlayerInputComponent->BindAxis("Yaw", this, &AMyPawn::Yaw);
}

void AMyPawn::MoveForward(float amount) {
	if (Controller && amount) {
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
		//AddMovementInput�� ȣ���� ������ �÷��̾ 'fwd'�������� 'amount'��ŭ �̵���Ŵ.
	}
}
void AMyPawn::MoveRight(float amount) {
	if (Controller && amount) {
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
		//AddMovementInput�� ȣ���� ������ �÷��̾ 'fwd'�������� 'amount'��ŭ �̵���Ŵ.
	}
}

void AMyPawn::Yaw(float amount) {
	AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds());
} /*GetWorld()->GetDeltaSeconds()�� ���� �����Ӱ� ���� ������ ������ ����
�ð��� ��ȯ 60fps�϶� 16ms����. */

void AMyPawn::Pitch(float amount) {
	AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}