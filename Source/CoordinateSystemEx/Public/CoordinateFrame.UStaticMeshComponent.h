#pragma once



template <>
class TConstCoordinateFrame<UStaticMeshComponent>
{
public:
	TConstCoordinateFrame(const UStaticMeshComponent& Object)
		: Object(Object)
	{
	}



public:
	FORCEINLINE FVector GetRelativeLocation() const { return Object.RelativeLocation; }
	FORCEINLINE FRotator GetRelativeRotation() const { return Object.RelativeRotation; }
	FORCEINLINE FVector GetRelativeScale() const { return Object.RelativeScale3D; }
	FORCEINLINE FTransform GetRelativeTransform() const { return Object.GetRelativeTransform(); }
	FORCEINLINE FVector GetWorldLocation() const { return Object.GetComponentLocation(); }
	FORCEINLINE FRotator GetWorldRotation() const { return Object.GetComponentRotation(); }
	FORCEINLINE FVector GetWorldScale() const { return Object.GetComponentScale(); }
	FORCEINLINE FTransform GetWorldTransform() const { return Object.GetComponentTransform(); }



protected:
	const UStaticMeshComponent& Object;
};

template <>
class TCoordinateFrame<UStaticMeshComponent> : public TConstCoordinateFrame<UStaticMeshComponent>
{
public:
	TCoordinateFrame(UStaticMeshComponent& Object)
		: TConstCoordinateFrame<UStaticMeshComponent>(Object)
		, Object(Object)
	{
	}



public:
	FORCEINLINE void SetRelativeLocation(FVector NewLocation) { Object.SetRelativeLocation(NewLocation); }
	FORCEINLINE void SetRelativeRotation(FRotator NewRotation) { Object.SetRelativeRotation(NewRotation); }
	FORCEINLINE void SetRelativeScale(FVector NewScale) { Object.SetRelativeScale3D(NewScale); }
	FORCEINLINE void SetRelativeTransform(FTransform NewTransform) { Object.SetRelativeTransform(NewTransform); }
	FORCEINLINE void SetWorldLocation(FVector NewLocation);
	FORCEINLINE void SetWorldRotation(FRotator NewRotation);
	FORCEINLINE void SetWorldScale(FVector NewScale);
	FORCEINLINE void SetWorldTransform(FTransform NewTransform);



protected:
	UStaticMeshComponent& Object;
};
