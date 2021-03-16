#include <iostream>
#include <vector>

// 'this' pointer is a special pointer hidden in every non-static member function.

// When we calling a member function on an object, the complier first assigns the address of the object to the this pointer,
// and then calls the member function. Each time the member function accesses a data member, the 'this' pointer is implicitly used

// The 'this pointer is implicitly declared as 'Classname* const this', which means the 'this' pointer cannot be assigned
// In the const member function of the class, the type of 'this' pointer is 'const Classname* const this', which means the object
// pointed to by the 'this' pointer cannot be modified (that is, the data members of such objects cannot be assigned)

// 'this' is not a regular variable, but an rvalue(right-value, opposite for lvalue(left-value)), so we cannot get the address of 'this',
// which means we cannot use '&this'

// It is often necessary to explicitly reference the 'this' pointer in three conditions:

// 1. To implement a chained reference to an object
class Person
{
public:
	int age;
	Person& AddAge(int p_age)
	{
		age += p_age;
		return *this;
	}
};

// 2. When implementing some data structures, such as list
struct Node
{
	int value;
	Node* next;

	void insertAfter(Node* prev)
	{
		next = prev->next;
		prev->next = this;
	}
};

// 3. To avoid performing assignments on the same object
class Entity; // Forward declaration for class Entity
void PrintEntity(Entity* e);

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		this->x = x;
		this->y = y;
		// We cannot write as 'x = x;' 

		PrintEntity(this);
	}

	int GetX() const
	{
		// 'this' pointer is actually const Entity* type in const member function
		const Entity* e = this;
		const Entity& ee = *this;
	}
};

void PrintEntity(Entity* e)
{
	std::cout << e->x << "," << e->y << std::endl;
}

int main()
{
	// 1. To implement a chained reference to an object
	Person p;
	p.age = 20;
	p.AddAge(1).AddAge(1).AddAge(1);
	std::cout << p.age << std::endl;

	// 3. To avoid performing assignments on the same object
	Entity e(2, 3);

}