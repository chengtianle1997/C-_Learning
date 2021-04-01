#include <iostream>

class Entity
{
public:
	void Print() const
	{
		std::cout << "Hello!" << std::endl;
	}
};

int main()
{
	// instance to a class
	Entity e;
	e.Print();

	// Pointer to a class
	Entity* eptr = &e;
}