#include <iostream>

struct Entity
{
	int x, y;

	int* GetPositions()
	{
		return &x;
	}
};

int main()
{
	int a = 50;
	double value = a;
	std::cout << value << std::endl;
	std::cout << &a << ", " << &value << std::endl;
	// variable 'a' and 'value' are actually on two blocks of memory

	// However, what if we want they are on the same memory?
	int b = 50;
	double* value_b = (double*)&b;
	std::cout << *value_b << std::endl;  // this time, we cannot can the correct double value 50
	std::cout << &b << ", " << value_b << std::endl;
	// see Memory window when the program is interupted

	Entity e = { 5, 8 };
	int* position = (int*)&e;
	std::cout << position[0] << ", " << position[1] << std::endl;
	// more crazy
	int y = *(int*)((char*)&e + 4);
	std::cout << y << std::endl;
	// e.GetPositions() function
	int* position_t = e.GetPositions();
	std::cout << position_t[0] << ", " << position_t[1] << std::endl;

	return 0;
}