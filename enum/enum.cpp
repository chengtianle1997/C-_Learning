#include <iostream>

// Scoped enumeration type: safe type, cannot be implicitly converted to an integer
enum class color {white, black, red};

// Unscoped enumeration type
enum operation {add, minus, multiply, divide};

enum day {Mon=1, Tue, Wed, Thu, Fri, Sat=100, Sun};

int main()
{
	// enum class can be converted to an integer explicitly
	std::cout << int(color::white) << std::endl;

	// We cannot compare the enum class with other int value
	// However, we can compare enum with other int value
	
	// Uncommenting the line below will cause an error
	// if (color::white < 1)
	if (add < 1)
	{
		std::cout << "The value of enum type add is less than one" << std::endl;
	}
	std::cout << add << std::endl;

	std::cout << Mon << std::endl;
	std::cout << Sat << std::endl;
	std::cout << Sun << std::endl;

}