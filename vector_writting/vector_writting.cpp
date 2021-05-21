#include <iostream>
#include <vector>  // the vector in STL
#include "Vector.h"  // our self-written vector class
#include <string>

struct Vector3 {

	float x = 0.0f, y = 0.0f, z = 0.0f;

	Vector3() {}
	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar) {}
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z) {}
	//copy
	Vector3(const Vector3& other)
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copied\n";
	}
	// move
	Vector3(Vector3&& other) noexcept
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Moved\n";
	}
	// operator=
	Vector3& operator=(const Vector3& other)
	{
		std::cout << "Copied\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	Vector3& operator=(Vector3&& other) noexcept
	{
		std::cout << "Moved\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	// destroyed
	~Vector3()
	{
		std::cout << "Destroyed\n";
	}
};

template <typename T>
void PrintVector(const Vector<T>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void PrintVector(const Vector<Vector3>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i].x << " " << vector[i].y << " " << vector[i].z << std::endl;
	}
}

int main()
{
	Vector<std::string> vector;
	vector.push_back("Tommy");
	vector.push_back("C++");
	vector.push_back("Vector");
	vector.push_back("Vector");
	vector.push_back("Vector");
	vector.push_back("Vector");
	PrintVector(vector);

	Vector<Vector3> vector3;
#if 0  // push_back operations: although we use std::move, there are still some copy operations
	vector3.push_back(Vector3(1, 2, 3));
	vector3.push_back(Vector3(4));
	vector3.push_back(Vector3());
#else  // emplace_back operation: no copy operation, which is faster.
	vector3.emplace_back(1, 2, 3);
	vector3.emplace_back(4);
	vector3.emplace_back();
#endif
	PrintVector(vector3);
	vector3.pop_back();
	PrintVector(vector3);
	vector3.clear();
	PrintVector(vector3);
}