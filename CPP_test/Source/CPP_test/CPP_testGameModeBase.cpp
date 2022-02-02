// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_testGameModeBase.h"
#include "MyPawn.h"


ACPP_testGameModeBase::ACPP_testGameModeBase() {
	DefaultPawnClass = AMyPawn::StaticClass();
}