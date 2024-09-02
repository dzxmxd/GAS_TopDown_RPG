// Copyright Santa.Wang


#include "AI/BTService_FindNearestPlayer.h"

#include "AIController.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UBTService_FindNearestPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	const APawn* OwningPawn = AIOwner->GetPawn();

	const FName TargetTag = OwningPawn->ActorHasTag(FName("Player")) ? FName("Enemy") : FName("Player");

	TArray<AActor*> ActorsWithTags;
	UGameplayStatics::GetAllActorsWithTag(OwningPawn, TargetTag, ActorsWithTags);

	float ClosestDistance = TNumericLimits<float>::Max();
	AActor* ClosestActor = nullptr;
	for (auto* CurActor : ActorsWithTags)
	{
		if (IsValid(CurActor) && IsValid(OwningPawn))
		{
			const float CurActorDistance = OwningPawn->GetDistanceTo(CurActor);
			if (CurActorDistance < ClosestDistance)
			{
				ClosestDistance = CurActorDistance;
				ClosestActor = CurActor;
			}
		}
	}

	UBTFunctionLibrary::SetBlackboardValueAsObject(this, TargetFollowSelector, ClosestActor);
	UBTFunctionLibrary::SetBlackboardValueAsFloat(this, DistanceToTargetSelector, ClosestDistance);
}
