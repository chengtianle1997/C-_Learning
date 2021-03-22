#include <iostream>
#include <string>

class Example
{
public:
	Example()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	Example(int x)
	{
		std::cout << "Created Entity with " << x << "!" << std::endl;
	}
};

class Entity
{
private:
	int m_score;
	std::string m_name;
	Example m_example;  // Print "Created Entity!" if there is no intializing operation in the initializing list.
public:
	Entity()
		: m_score(0), m_name("Unknown"), m_example(Example(8))  // Print "Created Entity with 8!"
		// we can also just initialize m_example by : m_example(8), try it!
	{
		// m_example = Example(9);  // Print "Created Entity with 9!"
		// We can see that m_example is initialize twice, which is a waste of performance
		// The best way is initializing it by initializing list
		// So we add m_example(Example(8)) in the initializing list, and comment the code inside the constructor
	}
	// The initializing list initialize the member in the same order that we declare the member

	Entity(const std::string& name)
		: m_name(name) {}  // Print "Created Entity!" if there is no intializing operation in the initializing list.

	void PrintName()
	{
		std::cout << m_name << std::endl;
	}
};

int main()
{
	Entity e1 = Entity();
	e1.PrintName();

	std::cout << std::endl;

	Entity e2 = Entity("Tommy");
	e2.PrintName();

}