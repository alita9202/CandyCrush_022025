// Fill out your copyright notice in the Description page of Project Settings.


#include "Tablero.h"
#include "Bloque1.h"
#include "Bloque2.h"
#include "Bloque3.h"
#include "Bloque4.h"
#include "Bloque5.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ATablero::ATablero()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Crear el componente de malla
	TableroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableroMesh"));
	RootComponent = TableroMesh;

	// 👉 Aquí cargamos un Static Mesh por defecto (ejemplo: un cubo)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TableroMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	if (TableroMeshAsset.Succeeded())
	{
		TableroMesh->SetStaticMesh(TableroMeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ATablero::BeginPlay()
{
	Super::BeginPlay();

    BloqueTipos[0] = ABloque1::StaticClass();
    BloqueTipos[1] = ABloque2::StaticClass();
    BloqueTipos[2] = ABloque3::StaticClass();
    BloqueTipos[3] = ABloque4::StaticClass();
    BloqueTipos[4] = ABloque5::StaticClass();

    // 📌 Calcular desplazamiento para centrar el tablero
    float OffsetX = (Columnas - 1) * Espaciado * 0.5f;
    float OffsetY = (Filas - 1) * Espaciado * 0.5f;

    // Crear tablero
    for (int32 f = 0; f < Filas; f++)
    {
        for (int32 c = 0; c < Columnas; c++)
        {
            int32 TipoAleatorio = FMath::RandRange(0, 4);

            FVector Posicion = FVector(c * Espaciado - OffsetX, f * Espaciado - OffsetY, 0);

            GetWorld()->SpawnActor<ABoque>(
                BloqueTipos[TipoAleatorio],
                Posicion,
                FRotator::ZeroRotator
            );
        }
    }
	
}

// Called every frame
void ATablero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

