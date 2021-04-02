#include <iostream>

class Entity
{
public:
	void Print()
	{
		std::cout << "Hello!" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity) {}
	~ScopedPtr()
	{
		delete m_Obj;
	}
	// overload the arrow operator
	Entity* operator->()
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;
};

int main()
{
	// instance to a class
	Entity e;
	// we use its method by dot '.'
	e.Print(); // "Hello!"

	// Pointer to a class
	Entity* eptr = &e;
	// we use its method by arrow '->'
	eptr->Print(); // "Hello!"
	// or turn it into a reference
	Entity& er = *eptr;
	er.Print(); // "Hello!"
	// or more directly
	(*eptr).Print(); // "Hello!"
	// Attention: do not write like:
	// *eptr.Print();
	// it means that *(eptr.Print())

	// Arrow operator overload
	ScopedPtr entity = new Entity();
	// we can do this for the arrow operator overload in class ScopedPtr.
	entity->Print();

	// let's try the line of code below
	int offsetx = (int)&((Vector3*)nullptr)->x;
	int offsety = (int)&((Vector3*)nullptr)->y;
	int offsetz = (int)&((Vector3*)nullptr)->z;
	std::cout << "offsetx: " << offsetx << std::endl;
	std::cout << "offsety: " << offsety << std::endl;
	std::cout << "offsetz: " << offsetz << std::endl;

}