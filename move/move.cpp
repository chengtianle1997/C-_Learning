#include <iostream>

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
	Entity(String&& name)
		: m_Name((String&&) name) {}
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
	Entity entity("Tommy");
	entity.PrintName();
	// Step 1: remove all code marked as '---Removed for Step 1'
	// Here, we get Created, Copied and finally print Tommy, Destroyed.

	// Step 2: add all code marked as '---Removed for Step 1'
	// This time, we get Created, Copied, Destroyed, Tommy and final Destroyed.

	// Step 3: Change the input parameter of the Move constructor of Entity class to (String&&) 
	// and we will finally call the move constructor.
	// This time, we get Created, Moved, Destroyed, Tommy and final Destroyed.
	// we actually allocate the memory once when Created and move them to the destination without copying.

}