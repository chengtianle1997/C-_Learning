# include <iostream>

class Entity
{
public:
	// We can only initialize the const variable in the initialization list
	const int a;  // Can not initialize a here
	// Constructor function: initialize const a here, and a cannot be modify from this line
	Entity() : a(0) { };
	// Or
	Entity(int x) : a(x) { };

	// Use const to distinguish function from its overloaded function
	int getValue()
	{
		return a;
	}
	// Const function, must not modify the value of any data member in class
	int getValue() const
	{
		return a;
	}

	// If we do have to change data member in const function
	// Use mutable
	mutable int b = 0;
	int getValue_const() const
	{
		b = 1; // b is mutable, mutable meas that can change
		return b;
	}

	// For test in main function
	int getValue_nonconst()
	{
		return a;
	}

};

void function()
{
	// Const object
	Entity e; // Ordinary object, can call all member functions, and update constant member variables
	const Entity e_const; // Constant object, can only call constant member functions
	const Entity* p = &e_const; // Pointer that points to a constant object
	const Entity& d = e_const; // Reference to constant object

	// Const pointer
	char greeting[] = "Hello";
	char* p1 = greeting; // Pointer that points to a character array
	const char* p2 = greeting; // Pointer that points to a const character array
	char* const p3 = greeting; // Const pointer that points to a character array
	const char* const p4 = greeting; // Const pointer that points to a const character array
	// Attention: const char* p is equal to char const* p, they are all pointers points to const variable
	//			  However, char* const p is different, it is a const pointer
}

int main()
{
	// Although cosnt function in a class cannot change any data member,
	// it is useful when a const entity of a class is needed. 
	// We can only call const function of the const entity.
	const Entity e = Entity();
	std::cout << e.getValue_const() << std::endl;
	// We cannot call non-const function of the const entity, uncomment the line below will cause an error
	// e.getValue_nonconst();
}