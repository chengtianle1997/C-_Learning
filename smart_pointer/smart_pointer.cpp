#include <iostream>

// for smart pointers
#include <memory>

// Summary: 
// smart pointers are used to make sure that an object is deleted if it is no longer used (referenced).

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print()
	{

	}
};

int main()
{
	// unique pointer: make sure that only one copy of an object exists
	std::cout << "Unique pointer:" << std::endl;
	{
		std::unique_ptr<Entity> entity(new Entity());  // "Created Entity!"
		entity->Print();

		// unique_ptr() is decorated by explicit, so we cannot use implicit conversion like:
		// std::unique_ptr<Entity> entity = new Entity();

		// We cannot copy unique pointer like:
		// std::unique_ptr<Entity> e0 = entity;
		// Because in <memory> these operators and method are deleted as below:
		//   unique_ptr(const unique_ptr&) = delete;
		//   unique_ptr& operator=(const unique_ptr&) = delete;

		// Another way to declare a unique pointer: (recommended)
		std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
		// by this way, 
		// the program can call both the constructor of Entity and the constructor of unique_ptr at the same time,
		// which is a lot more efficient.
		// make_unique is in C++ 14, and make_shared is in C++ 11
		
	} // "Destroyed Entity!", smart pointer destroyed at the end of scope '}'

	std::cout << std::endl;

	// shared pointer: it is a reference counting smart pointer that can be used to store
	// and pass a reference beyond the scope of a function.
	std::cout << "Shared pointer:" << std::endl;
	{
		std::shared_ptr<Entity> e0;
		std::cout << e0.use_count() << std::endl; // 0: e0 does not point to any memory
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // "Created Entity!"
			e0 = sharedEntity;	// e0 hold a reference to sharedEntity
			e0->Print();
			std::cout << e0.use_count() << std::endl;  // 2: e0 and sharedEntity points to the same memory
			std::cout << sharedEntity.use_count() << std::endl;  // 2: e0 and sharedEntity points to the same memory
		} 
		std::cout << e0.use_count() << std::endl;  // 1: e0 points to the memory and sharedEntity has been destroyed
		std::cin.get();
	} // "Destroyed Entity!", smart pointer destroyed at the end of scope '}'
	
	std::cout << std::endl;

	// weak pointer: it is a smart pointer that holds a non-owning (weak) reference to an object that is managed by shared pointer
	// it must be converted to shared pointer in order to access the reference object
	std::cout << "Weak pointer:" << std::endl;
	{
		std::weak_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // "Created Entity!"
			e0 = sharedEntity;  // shared pointer can be used to assign weak and shared pointer
			// e0->Print(); // we cannot access the reference object of weak pointer
			e0.lock()->Print(); // we can only access the reference object of weak pointer by lock()
			std::cout << sharedEntity.use_count() << std::endl;  // 1: weak pointer cannot increase the reference counting
		} // "Destroyed Entity!"
		std::cin.get();
	}
	// weak pointer models temporary ownership: when an object needs to be accessed if it exists, and it may
	// be deleted at any time by someone else, weak pointer is used to track the object, and it is converted
	// to shared pointer to assume temporary ownership. If the shared pointer is destroyed at this time, the
	// object's lifetime is extended until the temporary shared pointer is destroyed as well.

}