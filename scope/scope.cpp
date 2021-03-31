#include <iostream>

class Entity
{
private:
	int x;
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* e)
		: m_Ptr(e) {}
	~ScopedPtr()
	{
		// class ScopedPtr destroyed the m_Ptr on the heap by 'delete'
		delete m_Ptr;
	}
};

// This function is definitely wrong because array 'a' will be destroyed at the end of the function
int* CreateArrayWrong()
{
	int a[50];
	a[0] = 10;
	return a;
}
// If we want to do that correctly, we should:
// 1. Allocate the array on the heap
int* CreateArrayRight1()
{
	int* a = new int[50];
	a[0] = 10;
	return a;
}
// 2. Allocate the array on the stack but out of the function.
void CreateArrayRight2(int* a)
{
	// We can do something like assignment here.
	a[0] = 10;
}

int main()
{
	// Create Entity e on stack, it will be destroyed at the end of scope '}'
	{
		Entity e; // "Created Entity!"
	} // "Destroyed Entity!"
	std::cout << std::endl;
	// Create Entity e on heap, it will not be destroyed at the end of scope '}'
	{
		Entity* e = new Entity(); // "Created Entity!"
	}
	std::cout << std::endl;
	{
		ScopedPtr sp = new Entity();
		// Attention: we allocate a new Entity object on the heap, but allocate a ScopedPtr 'sp' on stack
		// 'sp' will be destroyed at the end of the scope '}' and call its destructor.
		// and the Entity on the heap will be detroyed by the destructor of 'sp'
	}
	std::cout << std::endl;
	// Create array function
	// This function is definitely wrong because array 'a' will be destroyed at the end of the function
	int* aw = CreateArrayWrong();
	// std::cout << aw[0] << std::endl;  // There is an interesting question occurs when we uncomment this line of code
	// If we want to do that correctly, we should:
	// 1. Allocate the array on the heap
	int* ar1 = CreateArrayRight1();
	// 2. Allocate the array on the stack but out of the function.
	int ar2[50];
	CreateArrayRight2(ar2);
	std::cout << aw[0] << std::endl; // We can see that 'a' in function CreateArrayWrong() is destroyed.
	std::cout << ar1[0] << std::endl;
	std::cout << ar2[0] << std::endl;
	return 0;
}