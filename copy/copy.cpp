#include <iostream>

struct Vector2
{
	float x, y;
};

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	~String()
	{
		delete[] m_Buffer;
	}

	// declare a friend that can access the private member outside the class
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	// operator [] overload
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	// C++ supplies us with a origin copy constructor
	// Part 1
	/*String(const String& other):
		m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}*/
	

	// if we make this constructor explicit, we cannot write code like 'String second = string;' in main function.
	// or try
	// String(const String& other) = delete;
	// and remember to commit the constructor we wrote above. We can see the error in the code 'String second = string;'
	// These two operations above are exactly what the unique pointer does, so we cannot copy unique_ptr.

	// So, let's write a deep copy constructor for String
	// Part 2
	String(const String& other) :
		m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size);
		m_Buffer[m_Size] = 0;
		std::cout << "String Copied!" << std::endl;
	}

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(String string)
{
	std::cout << "Print String:" << string << std::endl;
}

void PrintStringRef(const String& string)
{
	std::cout << "Print String Reference:" << string << std::endl;
}

void PrintStringRef1(const String& string)
{
	std::cout << "Print String Reference:" << string << std::endl;
	// if we do want to copy string or change string, we can do like:
	String string_copy = string; // "String Copied" here
	string_copy[1] = 'a';
	std::cout << "Print String Original:" << string << std::endl;
	std::cout << "Print String Copy:" << string_copy << std::endl;
}

int main()
{
	Vector2* a = new Vector2();
	Vector2* b = a;
	// In this way, we only copy the pointer, not the struct Vector2 struct.
	// When we change b, a is not affected
	b++;
	std::cout << a << "," << b << std::endl;
	// we can see that a and b are diffirent pointer
	b = a; // reset b = a

	// When we change the momery that b points to
	b->x = 10;
	std::cout << a->x << "," << b->x << std::endl;
	// we can see that a->x is also modified.

	{
		// Uncomment Part 1 in class Entity first, and run the code below:
		String string = "Tommy";
		String second = string;
		// change a single char in the String
		second[1] = 'a';

		// shallow copy, the two String above has the same memory buffer
		std::cout << string << std::endl;  // Part 1: Tammy, Part 2: Tommy
		std::cout << second << std::endl;  // Part 1: Tammy, Part 2: Tammy
		std::cin.get();
	} // when we reach the end of scope '}', we delete the m_Buffer pointer twice, 
	  // so we crash here.

	// Now, uncomment Part 2 in class Entity, and comment Part 1, and run the code again.
	// we can see that the error has gone.
	// Keep uncomment Part 2, and run the code below
	{
		String string = "Tommy";
		String second = string; // "String Copied!"
		PrintString(string); // "String Copied!", "Print String: Tommy"
		// we can see that we have copied the String twice, 
		// which is unnecessary and a waste of memory and performance.

		PrintStringRef(string); // "Print String: Tommy" only
		// This time, string is not copied because it is passing by reference.

		std::cout << std::endl;

		// Advice: always pass the object by constant reference like PrintStringRef does.
		// and use the object like PrintStringRef1 does.
		PrintStringRef1(string);
	}

}