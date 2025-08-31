// Fill out your copyright notice in the Description page of Project Settings.


#include "Boque.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABoque::ABoque()
{
	// Crear el componente de malla
	BloqueMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BloqueMesh"));
	RootComponent = BloqueMesh;

	// 👉 Aquí cargamos un Static Mesh por defecto (ejemplo: un cubo)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BloqueMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (BloqueMeshAsset.Succeeded())
	{
		BloqueMesh->SetStaticMesh(BloqueMeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ABoque::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

