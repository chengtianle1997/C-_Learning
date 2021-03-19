#include <iostream>
#include <string>

// Interface Printable: guaranteed that the class has the 'GetClassName' function.
class Printable
{
public:
	virtual std::string GetClassName() = 0;
};
// Interfaces are just a class with pure virtual function in C++.

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }

	std::string GetClassName() override { return "Entity"; }
};

//class Player : public Entity, Printable  
// -->  we do not need Printable here for Entity is Printable.
class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}
	
	std::string GetName() override { return m_Name; }
	std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{
	Entity* entity = new Entity();
	PrintName(entity);

	Player* player = new Player("Tommy");
	PrintName(player);

	Print(entity);
	Print(player);
	
}