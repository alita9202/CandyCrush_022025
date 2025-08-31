// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque4.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ABloque4::ABloque4()
{
    // Asignar el Mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BloqueMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (BloqueMeshAsset.Succeeded())
    {
        BloqueMesh->SetStaticMesh(BloqueMeshAsset.Object);
    }

    // Asignar el Material
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));
    if (MaterialAsset.Succeeded())
    {
        BloqueMesh->SetMaterial(0, MaterialAsset.Object);
    }
}
