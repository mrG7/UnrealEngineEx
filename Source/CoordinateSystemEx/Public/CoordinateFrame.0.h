#pragma once



template <typename T>
class TConstCoordinateFrame
{
public:
	TConstCoordinateFrame(const T& Object)
		: Object(Object)
	{
	}



public:
	FVector GetRelativeLocation() const;
	FRotator GetRelativeRotation() const;
	FVector GetRelativeScale() const;
	FTransform GetRelativeTransform() const;
	FVector GetWorldLocation() const;
	FRotator GetWorldRotation() const;
	FVector GetWorldScale() const;
	FTransform GetWorldTransform() const;



protected:
	const T& Object;
};

template <typename T>
class TCoordinateFrame : public TConstCoordinateFrame<T>
{
public:
	TCoordinateFrame(T& Object)
		: TConstCoordinateFrame<T>(Object)
		, Object(Object)
	{
	}



public:
	FORCEINLINE void SetRelativeLocation(FVector NewLocation);
	FORCEINLINE void SetRelativeRotation(FRotator NewRotation);
	FORCEINLINE void SetRelativeScale(FVector NewScale);
	FORCEINLINE void SetRelativeTransform(FTransform NewTransform);
	FORCEINLINE void SetWorldLocation(FVector NewLocation);
	FORCEINLINE void SetWorldRotation(FRotator NewRotation);
	FORCEINLINE void SetWorldScale(FVector NewScale);
	FORCEINLINE void SetWorldTransform(FTransform NewTransform);



protected:
	T& Object;
};



template<typename T>
static TConstCoordinateFrame<T> MakeCoordinateFrame(const T& Object)
{
	return TConstCoordinateFrame<T>(Object);
}

template<typename T>
static TConstCoordinateFrame<T> MakeCoordinateFrame(const T* Object)
{
	return TConstCoordinateFrame<T>(*Object);
}

template<typename T>
static TCoordinateFrame<T> MakeCoordinateFrame(T& Object)
{
	return TCoordinateFrame<T>(Object);
}

template<typename T>
static TCoordinateFrame<T> MakeCoordinateFrame(T* Object)
{
	return TCoordinateFrame<T>(*Object);
}
