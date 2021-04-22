#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor\n"; }
	~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived Constructor\n"; }
	~Derived() { std::cout << "Derived Destructor\n"; }
};

// class with virtual destructor
class Base_v
{
public:
	Base_v() { std::cout << "Base Constructor\n"; }
	virtual ~Base_v() { std::cout << "Base Destructor\n"; }
};

class Derived_v : public Base_v
{
public:
	Derived_v() { std::cout << "Derived Constructor\n"; }
	~Derived_v() { std::cout << "Derived Destructor\n"; }
};

int main()
{
	Base* base = new Base();
	delete base;

	/*
	Base Constructor
	Base Destructor
	*/
	

	std::cout << "---------------------" << std::endl;

	Derived* derived = new Derived();
	delete derived;

	/*
	Base Constructor
	Derived Constructor
	Derived Destructor
	Base Destructor
	*/

	std::cout << "---------------------" << std::endl;

	Base* poly = new Derived();
	delete poly;

	/*
	Base Constructor
	Derived Constructor
	Base Destructor
	*/
	// This time, Derived Destructor is not called as expected, this will cause memory leak.

	// So let's try virtual destructors for the Base class
	// Making base class destructor virtual guarantees that the object of derived class is destructed properly, 
	// both base class and derived class destructors are called.

	std::cout << "---------------------" << std::endl;

	Base_v* poly_v = new Derived_v();
	delete poly_v;

	/*
	Base Constructor
	Derived Constructor
	Derived Destructor
	Base Destructor
	*/

	// The virtual destructor tells the delete operation: 
	// hey, you need to call the destructor of the child class first.
}