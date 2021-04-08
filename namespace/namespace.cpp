#include <iostream>
#include <string>

// we can only use namespace in C++, not in C library.

namespace apple {
	namespace functions {
		int value = 10;
}
	void print(const char* text)
	{
		std::cout << text << std::endl;
	}

	void print_again() {}
}

namespace orange {
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

int main()
{
	std::cout << apple::functions::value << std::endl;
	apple::print("Hello!");
	orange::print("Hello!");

	// using the exact function of apple namespace
	using apple::print;
	print("Hello!");
	// print_again();
	apple::print_again();

	// pass namespace
	namespace a = apple;
	a::print("Hello!");

	// using namespace 
	using namespace apple::functions;
	std::cout << value << std::endl;

	namespace f = apple::functions;
	std::cout << f::value << std::endl;
}