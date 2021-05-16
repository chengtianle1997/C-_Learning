#include <iostream>
#include <string>

class String {
public:
	String() = default;
	// Constructor
	String(const char* string)
	{
		std::cout << "Created!\n";
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	// Copy Operation
	String(const String& other)
	{
		std::cout << "Copied!\n";
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}
	// Move operation added: copy the rvalue directly (&& is the reference for rvalue) ---Removed for Step 1
	String(String&& other) noexcept
	{
		std::cout << "Moved!\n";
		m_Size = other.m_Size;
		m_Data = other.m_Data;
		// to avoid the 'other' String destroyed
		other.m_Size = 0;
		other.m_Data = nullptr; // delete nullptr will not affect anything.
	}
	// Move assignment operator
	String& operator=(String&& other) noexcept
	{
		std::cout << "Assigned!\n";

		// if we do something like: string = string
		if (this == &other)
			return *this;

		delete[] m_Data; // delete the old data to avoid memory leak.

		m_Size = other.m_Size;
		m_Data = other.m_Data;
		// to avoid the 'other' String destroyed
		other.m_Size = 0;
		other.m_Data = nullptr; // delete nullptr will not affect anything.
	}
	// Destructor
	~String()
	{
		std::cout << "Destroyed!\n";
		delete m_Data;
	}
	// Print function
	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			std::cout << m_Data[i];
		std::cout << std::endl;
	}

private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity {
public:
	// Constructor
	Entity(const String& name)
		: m_Name(name) {}
	// Move constructor      ---Removed for Step 1
	/*Entity(String&& name)
		: m_Name((String&&)name) {}*/
	// instead, we use std::move
	Entity(String&& name)
		: m_Name(std::move(name)) {}
	// Print function
	void PrintName()
	{
		m_Name.Print();
	}

private:
	String m_Name;
};

int main()
{
	String string = "Hello"; // Created.
	String dest = (String&&)string; // Moved.
	
	// Instead, we can use std::move
	String desta(std::move(string)); // Moved.
	// Or like this
	String destb = std::move(string); // Moved

	// Assignment operator
	String tommy = "Tommy"; // Created
	std::cout << "dest: ";
	dest.Print(); // Hello
	std::cout << "tommy: ";
	tommy.Print(); // Tommy
	dest = std::move(tommy); // Assigned
	std::cout << "dest: ";
	dest.Print(); // Hello
	std::cout << "tommy: ";
	tommy.Print(); // (NULL)
	
	Entity entity("Tommy");
	entity.PrintName();

	// std::move works for actual string and any other objects
	std::string a = "apple";
	std::string b = std::move(a);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl;
	std::string c = "chip";
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	b = std::move(c);
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
}