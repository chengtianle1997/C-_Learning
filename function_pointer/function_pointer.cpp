#include <iostream>
#include <vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void PrintValue(int a)
{
	std::cout << "Value: " << a << std::endl;
}

// pass the function pointer
void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

int main()
{
	// function pointer
	auto function = HelloWorld;
	// we get the memory address of the function here.

	// call my function like:
	function();

	// However, what is the exact type of auto
	void(*func)();
	func = HelloWorld;
	func();
	// by typedef
	typedef void(*hellofunc) ();
	hellofunc hello_world = HelloWorld;
	hello_world();

	// function with input parameter
	typedef void(*printfunc) (int);
	printfunc print = PrintValue;
	print(10);

	// pass a function pointer to another function
	std::cout << "pass function pointer:" << std::endl;
	std::vector<int> values = { 1, 2, 3, 4 };
	ForEach(values, PrintValue);

	// pass a lambda to function
	std::cout << "pass lambda:" << std::endl;
	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
}