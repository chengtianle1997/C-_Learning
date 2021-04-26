#include <iostream>
#include <tuple>
#include <string>

// Structured binding is a new feature in C++ 17.

// return a tuple
std::tuple<std::string, int> CreatePerson()
{
	return { "Tommy", 24 };
}

int main()
{
	std::tuple<std::string, int> person = CreatePerson();
	std::string& person_name = std::get<0>(person);
	int person_age = std::get<1>(person);

	std::string name;
	int age;
	std::tie(name, age) = CreatePerson();

	// structured binding: just keep returning a tuple
	// we do not need to define name_t and age_t.
	auto [name_t, age_t] = CreatePerson();
	std::cout << name_t << ", " << age_t << std::endl;
	// Remember to switch the compiler to C++ 17
	// Project property -> C/C++ -> Language -> C++ Language Standard -> Switch to 'C++ 17'

}