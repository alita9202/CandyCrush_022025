// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boque.generated.h"

UCLASS()
class CANDYCRUSH_022025_API ABoque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoque();

protected:
	// Componente de malla para mostrar el bloque
	UPROPERTY(VisibleAnywhere, Category = "Bloque")
	UStaticMeshComponent* BloqueMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
