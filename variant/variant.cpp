#include <iostream>
#include <variant>
#include <string>

// std::variant is a new feature in C++ 17
// variant represents a type-safe union, an instance of variant at any given
// time either holds a value of its alternative types, or in the case of error - no value
// remember: variant is not permitted to hold references, arrays or the type 'void'

enum class ErrorCode
{
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, int> ReadFileAsString()
{
	return {}; // we can return ErrorCode here with more detail like ErrorCode.
}

int main()
{
	std::variant<std::string, int> data;
	data = "Tommy";
	std::cout << std::get<std::string>(data) << std::endl;
	data = 2;
	// Then, how do we know the exact type of data?
	// data.index() shows the index of the type in the type list created when we initialize it.
	// for example, data.index() = 0 means the type is std::string.
	if (data.index() == 0) 
		std::cout << std::get<std::string>(data) << std::endl;
	else
		std::cout << std::get<int>(data) << std::endl;
	// Actually, there is a better way:
	auto* value = std::get_if<std::string>(&data);
	// if data is a string, it will give us the value, and if not, it will give us a nullptr
	if (!value)
		std::cout << "data is not a string!" << std::endl;
	auto* int_value = std::get_if<int>(&data);
	if (int_value)
		std::cout << "data is a int value: " << *int_value << std::endl;

	// The size of union is equal to the max size of the types in the union.
	union data_t
	{
		double a; // 8 bytes
		float b;  // 4 bytes
	};
	std::cout << sizeof(double) << std::endl; // 8 bytes
	std::cout << sizeof(float) << std::endl; // 4 bytes
	std::cout << sizeof(data_t) << std::endl;  // 8 bytes
	// what about the size of a variant
	std::variant<double, float> data_v;
	std::cout << sizeof(data_v) << std::endl;  // 16 bytes
	std::cout << sizeof(std::string) << std::endl; // 28 bytes
	std::cout << sizeof(data) << std::endl; // 32 bytes
	// variant occupies more memory than union, when we do not care about such things like type-safe,
	// union is more efficient.

	// let's talk about the use of variant
	// see line 10 to line 18.
}