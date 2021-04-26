#include <iostream>
#include <any>

// std::any is a new feature in C++ 17
// Remember to switch the compiler to C++ 17
// Project property -> C/C++ -> Language -> C++ Language Standard -> Switch to 'C++ 17'

int main()
{
	std::any data;
	data = 2;
	data = "Tommy"; // const char*
	
	std::string string_a = std::any_cast<std::string>(data);
	// or by reference:
	std::string& string_b = std::any_cast<std::string&>(data); // this will not allocate anything

}