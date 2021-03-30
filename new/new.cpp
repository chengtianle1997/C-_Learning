#include <iostream>

class Entity
{
private:
	std::string m_Name;
public:
	Entity() :
		m_Name("Unknown") {}
	Entity(std::string name) :
		m_Name(name) {}
	std::string GetName()
	{
		return m_Name;
	}
};

int main()
{
	int a = 2;
	int* b = new int[50]; // 200 bytes

	// The new keyword actually called malloc() function in C
	Entity* e = new Entity(); // new keyword allocate the memory and call the constructor
	//Entity* f = (Entity*)malloc(sizeof(Entity));  // cannot call the constructor, use new keyword in C++
	
	// We have to use free
	delete e;
	// which is equal to
	//free(f); // in C

	// For arrays
	delete[] b;

	// Finally, remember that new and delete are also operators.

	// we will talk about this line of code later.
	// Entity* h = new(b) Entity();
	return 0;
}