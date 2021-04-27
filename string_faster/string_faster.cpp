#include <iostream>

static uint32_t s_AllocCount = 0;

// count the times we allocate new memory
void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}

void PrintName(std::string_view name)
{
	std::cout << name << std::endl;
}

void PrintName(const char* name)
{
	std::cout << name << std::endl;
}

int main()
{
	std::string name = "Tommy";  // s_AllocCount + 1

	std::string firstName = name.substr(0, 2); // s_AllocCount + 1
	std::string lastName = name.substr(2, 4); // s_AllocCount + 1
	// It is unneccesary for us to create a new string for the substring view.
	
	PrintName(firstName);
	PrintName(lastName);
	PrintName(name);

	std::cout << s_AllocCount << " allocations" << std::endl; // 3 allocations

	// So, there is a new feature in C++ 17 called string view
	std::cout << "---------------------------------------" << std::endl;
	s_AllocCount = 0;

	std::string name_v = "Tommy";
	std::string_view firstName_v(name_v.c_str(), 2); // get the 'const char*' by name.c_str()
	std::string_view lastName_v(name_v.c_str() + 2, 4);

	PrintName(firstName_v);
	PrintName(lastName_v);
	PrintName(name_v);

	std::cout << s_AllocCount << " allocations" << std::endl; // 1 allocation

	// Actually, we can do more to make it faster
	std::cout << "---------------------------------------" << std::endl;
	s_AllocCount = 0;

	const char* name_p = "Tommy";
	std::string_view firstName_p(name_p, 2);
	std::string_view lastName_p(name_p + 2, 4);

	PrintName(firstName_p);
	PrintName(lastName_p);
	PrintName(name_p);

	// because of we pass the string by string_view, so there is still 0 allocation
	PrintName("Tommy"); 

	std::cout << s_AllocCount << " allocations" << std::endl; // 0 allocation
}