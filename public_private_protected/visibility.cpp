#include <iostream>
#include <string>

class Entity
{
// 'private' keyword means: only member in this class (or friends) can access to these members
private: 
	int X, Y;
	void Print() {}
// 'protected' keyword means: member in this class and its inherited class can access to these members
protected:
	int M, N;
	void PrintN() {}
// 'public' keyword means: member in this class and outside this class can access to these members
public:
	int A, B;
	Entity()
	{
		// we can call private member in this class
		X = 0;
		Print();
		// we can call protected member in this class
		M = 0;
		PrintN();
	}
};

// 'public' keyword here means public inheritance, 
// all access right remain the same: public->public, protected->protected, private->private
class Player : public Entity  
{
public:
	Player()
	{
		// we cannot call private member of Entity here like:
		// X = 2;
		// Print();
		// we can call protected member of Entity here
		M = 0;
		PrintN();
	}
};

// 'protected' keyword here means protected inheritance
// access rights change like: public->protected, protected->protected, private->private
class Gamer : protected Entity
{
public:
	Gamer()
	{
		M = 0;
		PrintN();
	}
};

// 'private' keyword here means private inheritance,
// all access rights are turned to be private: public->private, protected->private, private->private
class NPC : private Entity
{
public:
	NPC()
	{
		M = 0;
		PrintN();
	}
};

int main()
{
	// Visibility in class
	Entity *e = new Entity();
	// we cannot call the private member from outside the class like:
	// e->X = 2;
	// e.Print();
	// we cannot call the protected member from outside the class and its inherited class like:
	// e->M = 0;
	// e.PrintN();
	
	// Visibility in inheritance
	// For Player, public inherited from Entity
	Player *p = new Player();
	// public member in Entity is still public in Gamer, we can call them from outside like:
	p->A = 1;
	// protected member in Entity is still protected in Gamer, we cannot call them from outside like:
	// p->M = 1;
	// private member in Entity is still private in Gamer, we cannot call them from outside like:
	// p->X = 1;

	// For Gamer, protected inherited from Entity
	Gamer *g = new Gamer();
	// public member in Entity is now protected in Gamer, we cannot call them from outside like:
	// g->A = 1;
	// protected member in Entity is still protected in Gamer, we cannot call them from outside like:
	// g->M = 1;
	// private member in Entity is still private in Gamer, we cannot call them from outside like:
	// g->X = 1;

	// For NPC, private inherited from Entity
	NPC *n = new NPC();
	// public member in Entity is now private in NPC we cannot call them from outside like:
	// n->A = 1;
	// protected member in Entity is now private in NPC, we cannot call them from outside like:
	// n->M = 1;
	// private member in Entity is still private in NPC, we cannot call them from outside like:
	// n->X = 1;

}