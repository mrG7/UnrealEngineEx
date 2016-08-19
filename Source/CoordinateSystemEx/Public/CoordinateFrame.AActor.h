#pragma once



template <>
class TConstCoordinateFrame<AActor>
{
public:
	TConstCoordinateFrame(const AActor& Object)
		: Object(Object)
	{
	}



public:
	FORCEINLINE FVector GetRelativeLocation() const;
	FORCEINLINE FRotator GetRelativeRotation() const;
	FORCEINLINE FVector GetRelativeScale() const;
	FORCEINLINE FTransform GetRelativeTransform() const;
	FORCEINLINE FVector GetWorldLocation() const { return Object.GetActorLocation(); }
	FORCEINLINE FRotator GetWorldRotation() const { return Object.GetActorRotation(); }
	FORCEINLINE FVector GetWorldScale() const { return Object.GetActorScale3D(); }
	FORCEINLINE FTransform GetWorldTransform() const { return Object.GetActorTransform(); }



protected:
	const AActor& Object;
};
