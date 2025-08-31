// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tablero.generated.h"

UCLASS()
class CANDYCRUSH_022025_API ATablero : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATablero();
protected:
	// Componente de malla para mostrar el tablero
	UPROPERTY(VisibleAnywhere, Category = "Tablero")
	UStaticMeshComponent* TableroMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Bloques")
	TSubclassOf<class ABoque> BloqueTipos[5]; // Guardamos las 5 clases hijas

	UPROPERTY(EditAnywhere, Category = "Tablero")
	int32 Columnas = 5;

	UPROPERTY(EditAnywhere, Category = "Tablero")
	int32 Filas = 4;

	UPROPERTY(EditAnywhere, Category = "Tablero")
	float Espaciado = 200.f; // separación entre bloques

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
