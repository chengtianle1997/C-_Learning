#include <iostream>

// a union is a special class type that can hold one of its non-static data members at a time.

struct Vector2
{
	float x, y;
};

struct Vector4
{
	float x, y, z, w;

	Vector2& GetA()
	{
		return *(Vector2*)&x;
	}

	Vector2& GetB()
	{
		return *(Vector2*)&z;
	}
};

struct Vector4_u
{
	union
	{
		// Two ways of accessing x, y, z, w
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	struct Union{
		union
		{
			float a;
			int b;
		};
	};
	
	Union u;
	u.a = 2.0f;

	std::cout << u.a << ", " << u.b << std::endl;  // print: 2, 1073741824(actually the bytes for float 2.0f)
	// so unions are sometimes used for type punning
	std::cout << "------------------" << std::endl;
	// let's talk about a more useful example
	Vector4 vector4 = { 1.0f, 2.0f, 3.0f, 4.0f };
	PrintVector2(vector4.GetA());
	PrintVector2(vector4.GetB());
	std::cout << "------------------" << std::endl;
	Vector4_u vector4_u = { 1.0f, 2.0f, 3.0f, 4.0f };
	PrintVector2(vector4_u.a);
	PrintVector2(vector4_u.b);
	std::cout << "------------------" << std::endl;
	vector4_u.z = 500.0f;
	PrintVector2(vector4_u.a);
	PrintVector2(vector4_u.b);
	// In conclusion: union gives us different ways to access the same data,
	//                compared to type punning, union is more readable.

}