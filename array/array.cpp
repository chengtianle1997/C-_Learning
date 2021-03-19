#include <iostream>
#include <array>

// See the content in main function first.
class Entity
{
public:
	// The type of exampleSize must be static const here
	static const int exampleSize = 5;
	int example[exampleSize];

	// In C++ 11, there is a new array implement
	std::array<int, 5> another;
	Entity()
	{
		// The special use of .size for new array in C++ 11
		for (int i = 0; i < another.size(); i++)
			another[i] = 2;
	}
};

int main()
{
	// Array on the stack
	int example[5];
	// Array on the heap
	int* a = new int[5];

	// Get the size of an array
	int count = sizeof(example) / sizeof(int); // sizeof(example) is 20, sizeof(int) is 4
	std::cout << count << std::endl;
	// However, we cannot get the size of an array which is on the heap
	int count_heap = sizeof(a); 
	// sizeof(a) is the size of an integer pointer, so it's 4 for a 32bit (4 Byte = 32 bit) system
	// if you change the option 'x86' to 'x64', sizeof(a) will be 8 (8 Byte = 64 bit). (1 Byte = 8 bit)
	// Note: the sizeof a pointer is decided by the compiler and OS, not the type of the pointer.

	// if you do the same thing like this:
	count_heap = sizeof(a) / sizeof(int); // sizeof(a) is 5, sizeof(int) is 4, so the result is 1
	std::cout << count_heap << std::endl;

	// Then, let's talk about other features about array
	const int exampleSize = 5;
	int example_int[exampleSize];
	// The type of exampleSize can be const or static const here.
	// Now, See the content in class Entity
	Entity e;
}