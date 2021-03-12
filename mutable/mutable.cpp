# include <iostream>

// 1. The first thing about mutable is in "const" project:
// We can modify a member variable decorated with mutable in a const function

int main()
{
	// 2. More about mutable function
	int x = 8;
	// lambda function [=] means passing by value, [&] means passing by reference
	auto f = [=]() mutable
	{
		x++;
		std::cout << x << std::endl;
	};
	f();
	// However, we do not change the value x outside the function
	std::cout << x << std::endl;
	// What the mutable function actually do in the source code?
	// That's int y = x;  y++
	// So you cannot see x = 9 outside of the function

	// If mutable is not declared, we cannot change the value of x in the function
	// Let's try it 
	auto g = [=]()
	{
		// we cannot use x here without mutable declared, uncomment the code below will cause an error
		// return x++;
	};

}