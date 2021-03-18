#include <iostream>

// Polymorphism
// C++ polymorphism classification and implementation
// 1.Ad-hoc polymorphism (during compiling): function overload, operator overload
// 2. Subtype polymorphism (during runtime): virtual function
// 3. Parametric polymorphism (during compiling): class template, function template
// 4. Coercion polymorphism (during compiling / runtime): basic type conversion, custom type conversion

// Let's talk about static polymorphism (compile time / early binding)
// Function overload
class Entity
{
public:
	void Print(int a)
	{
		std::cout << "Integer value:" << a << std::endl;
	}
	void Print(float a)
	{
		std::cout << "Float value:" << a << std::endl;
	}
};

// Operator overload
class Box
{
private:
	double x, y, z;
public:
	Box(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	// Overload operator +
	Box operator+(const Box& b)
	{
		Box box(0, 0, 0);
		box.x = this->x + b.x;
		box.y = this->y + b.y;
		box.z = this->z + b.z;
		return box;
	}

	void Print()
	{
		std::cout << x << "," << y << "," << z << std::endl;
	}

};

int main()
{
	// Function overload
	Entity e;
	int a1 = 1;
	float a2 = 2.0f;
	e.Print(a1);
	e.Print(a2);

	// Operator overload
	Box box1(1, 1, 1);
	Box box2(2, 2, 2);
	Box box = box1 + box2;
	box1.Print();
	box2.Print();
	box.Print();
}