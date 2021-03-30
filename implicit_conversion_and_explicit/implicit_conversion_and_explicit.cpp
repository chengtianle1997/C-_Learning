#include <iostream>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		: m_Name(name), m_Age(-1) {}
	Entity(int age)
		: m_Name("Unknown"), m_Age(age) {}
	/*explicit Entity(int age)
		: m_Name("Unknown"), m_Age(age) {}*/

	void Print() const
	{
		std::cout << "Name:" << m_Name << " ,Age:" << m_Age << std::endl;
	}
};

void PrintEntity(const Entity& entity)
{
	entity.Print();
}

int main()
{
	Entity a("Tommy");
	PrintEntity(a);
	Entity b(22);
	PrintEntity(b);
	// The code above are just like:
	//Entity a = Entity("Tommy");
	//Entity b = Entity(22);

	std::cout << std::endl;

	// Implicit conversion
	Entity c = 22;
	PrintEntity(c);
	PrintEntity(22);
	// We can do these above, because we do have a constructor with int
	//Entity a = "Tommy";
	// We cannot do this because we can only do implicity once for one time
	// (const char* -> std::string -> Entity)
	Entity d = std::string("Tommy");
	PrintEntity(d);
	PrintEntity(std::string("Tommy"));

	std::cout << std::endl;

	// If we decorate the constructor with explicit keyword
	// we cannot do implicit conversion any more
	// try it in class Entity, and see errors line 40 and 42.

	// Use explicit keyword when we do not want implicit conversion happens
	// for example, when in math functions, we have to ensure the code is as safe as possible


}