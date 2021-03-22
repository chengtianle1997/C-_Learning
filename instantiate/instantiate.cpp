#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

int main()
{
	// The faster way to instatiate a class (on stack)
	Entity entity;
	std::cout << entity.GetName() << std::endl;  // Print "Unknown"

	Entity* e;
	{
		Entity entity1 = Entity("Tommy");
		e = &entity1;
		// std::cout << entity1.GetName() << std::endl;  // Print "Tommy"
	}
	std::cout << e->GetName() << std::endl;  // Print Nothing, because entity1 has been destroyed

	// Stack is limited, so from time to time, we have to instantiate a class on heap
	// We have to remember 2 things:
	// 1. Allocating on the heap takes longer.
	// 2. We need to delete the pointer we have allocated by 'new' keyword
	Entity* entity2 = new Entity();
	std::cout << entity2->GetName() << std::endl;  // Print "Unknown"

	Entity* e1;
	{
		Entity* entity3 = new Entity("Tommy");  
		e1 = entity3;
		// std::cout << entity2->GetName() << std::endl;  // Print "Tommy"

		// Try uncomment the code below and see what happens
		// delete entity3;
	}
	std::cout << e1->GetName() << std::endl;  // Print "Tommy"
	delete entity2;
}