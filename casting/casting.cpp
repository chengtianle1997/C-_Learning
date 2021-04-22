#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor\n"; }
	virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived Constructor\n"; }
	~Derived() { std::cout << "Derived Destructor\n"; }
};

int main()
{
	int a = 5;
	double value = a; // implicit conversion
	std::cout << value << std::endl;
	double value_a = (double)a;  // explicit conversion
	std::cout << value_a << std::endl;

	double t = 5.25;
	double b = (int)t + 5.3;
	double s = static_cast<int>(value) + 5.3;
	std::cout << b << ", " << s << std::endl;

	// static_cast: used for implicit conversion (non-const -> const, void* -> int*)
	// we can use static_cast to cast upwards, but cast downwards is not safe.
	const int a_const = static_cast<const int>(a);
	void* p = nullptr;
	int* a_s = static_cast<int*>(p);
	Derived* derived = new Derived();
	Base* base_a = static_cast<Base*>(derived);

	// const_cast: used for adding const and removing const
	// the type in const_cast must be a reference, a pointer or pointer to member to an object type
	int& a_nonconst = const_cast<int&>(a_const); // remember to use reference here.
	const int* a_const_ptr = const_cast<const int*>(&a);

	// dynamic_cast: used for casting between different class hierarchy.
	// it can only be used for classes with virtual functions, and the type must be pointers or reference.
	// if the casting is illegal, it will return a nullptr and throw an exception for reference.

	// cast upwards: from child class the base class
	Base* base_d = dynamic_cast<Base*>(derived);
	// cast downwards: from base class to child class (Base class must have virtual functions)
	Derived* derived_d = dynamic_cast<Derived*>(base_a);

	// reinterpret_cast: deal with almost all the conversions
	// reinterpret_cast just reinterpret the block of memory in another way.

	return 0;

}