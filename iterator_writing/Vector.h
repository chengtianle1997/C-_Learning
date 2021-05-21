#pragma once

template <typename Vector>
class VectorIterator {
public:
	// make our code simple to read
	using ValueType = typename Vector::ValueType;
	using PointerType = typename ValueType*;
	using ReferenceType = typename ValueType&;
public:
	VectorIterator(PointerType ptr)
	{

	}
};

template <typename T>
class Vector {
public:
	using ValueType = T;
public:
	Vector()
	{

	}
};