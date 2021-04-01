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

	// C++ supplies us with a origin copy constructor
	String(const String& other) :
		m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}
	// if we make this constructor explicit, we cannot write code like 'String second = string;' in main function.
	// or try
	// String(const String& other) = delete;
	// and remember to commit the constructor we wrote above. We can see the error in the code 'String second = string;'
	// These two operations above are exactly what the unique pointer does, so we cannot copy unique_ptr.
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
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
		String string = "Tommy";
		String second = string;
		// shallow copy, the two String above has the same memory buffer
		std::cout << string << std::endl;
		std::cout << second << std::endl;
		std::cin.get();
	} // when we reach the end of scope '}', we delete the m_Buffer pointer twice, 
	  // so we crash here.

}