#include <iostream>

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
	int count_heap = sizeof(a); // sizeof(example) is the size of an integer pointer, so it's 4
	// if you do the same thing like this:
	count_heap = sizeof(a) / sizeof(int); // sizeof(a) is 5, sizeof(int) is 4, so the result is 1
	std::cout << count_heap << std::endl;
}