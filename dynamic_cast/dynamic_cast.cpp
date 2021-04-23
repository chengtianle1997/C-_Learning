#include <iostream>
#include <string>

// dynamic_cast: used for casting between different class hierarchy.
// it can only be used for classes with virtual functions, and the type must be pointers or reference.
// if the casting is illegal, it will return a nullptr and throw an exception for reference.

// dynamic_cast can be used to check whether an object is the class we want or not.
// if it is not the specified class, it will return a null pointer.

class Entity
{
public:
	virtual void PrintName() {}  // dynamic_cast need a v_table established by virtual functions.
};

class Player : public Entity
{

};

class Enemy : public Entity
{

};

int main()
{
	Player* player = new Player();
	// implicit conversion
	Entity* actualPlayer = player;
	// However, we cannot do it the opposite way
	// Player* p = e;
	// This will cause an error.

	Entity* actualEnemy = new Enemy();

	Player* p = (Player*)actualEnemy;
	// This will not cause an error but not safe, because we do not know the exact class type of e1.
	// So, that's why we use dynamic_cast
	Player* p1 = dynamic_cast<Player*>(actualPlayer);
	if (p1)
	{
		std::cout << "p1 is actually a player!" << std::endl;
	}
	else
	{
		std::cout << "p1 is actually an enemy!" << std::endl;
	}
	Player* p2 = dynamic_cast<Player*>(actualEnemy);
	if (p2)
	{
		std::cout << "p2 is actually a player!" << std::endl;
	}
	else
	{
		std::cout << "p2 is actually an enemy!" << std::endl;
	}
	// we can see that p2 is NULL
	
	// Remember:
	// A. dynamic_cast actually takes time, it does runtime type check.
	// B. the program restore type information during runtime.
	//    Project properties -> C/C++ -> Language -> Enable Run-Time Type Information

	// We can turn off the Run-Time Type Information Option, and the dynamic_cast will throw an exception.

	return 0;
}