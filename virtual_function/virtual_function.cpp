#include <iostream>

// Caution:
// 1. non-member function cannot be virtual function
// 2. static function cannot be virtual function
// 3. constructor cannot be virtual function (v_table pointer is created after running the constructor)
// 4. inline function cannot be virtual function
// (inline -> compile period, virtual -> run period, in fact, inline virtual at the same time, 
// the complier will omit the inline feature and keep polymorphic(virtual function)

class Shape
{
public:
	virtual double calcArea()
	{
		std::cout << "This is the function of Shape class." << std::endl;
		return 0.0;
	}

	// deconstructor can be virtual function
	//virtual ~Shape();
};

class Circle : public Shape
{
public:
	// 'override' keyword is not required, but it makes the code more readable
	// and help you easily find bugs like spelling error.
	virtual double calcArea() override
	{
		std::cout << "This is the function of Circle class." << std::endl;
		return 0.0;
	}
};

// About pure virtual function: Differences between virtual function and pure virtual function
// Virtual function do not need to be overridden, but pure virtual function must be overriden to instantiate a child class
// A class with a pure virtual function is called an abstract class. This class cannot directly generate objects. It can only
// be used after being inherited and rewritting its virtual function. 
// After an abstract class is inherited, subclasses can continue to be abstract or ordinary class.
class A
{
public:
	// Declare a pure virtual function
	virtual void doA() = 0;
};

class B : public A
{
public:
	// Overwritting the pure funtion
	void doA() override
	{
		std::cout << "doA function calling success" << std::endl;
		return;
	}
};

int main()
{
	Shape* s = new Shape();
	Circle* c = new Circle();
	s->calcArea();
	c->calcArea();

	// Shape *a is actually a Circle class
	Shape* a = c;
	a->calcArea();
	// or like this:
	Shape* a_c = new Circle();
	a_c->calcArea();

	// However,
	Shape a_n = Circle();
	a_n.calcArea();
	// In this case, a_n is a Shape class

	// We cannot instantiate class A, because there is a pure virtual function in class A
	// decomment the code below will cause an error
	//A a = A();
	// However, we can instantiate class B after rewritting the pure virtual function
	B b = B();
	b.doA();
}