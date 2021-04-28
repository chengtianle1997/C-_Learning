#include <iostream>
#include <string>

void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

int main()
{
	std::string name = "Tommy";
	// The string usually allocate memory on the heap.
	// However, there are still some exceptions called:
	// Small String Criterion
	// if the string length is less than or equal to 15 buffers, it will
	// be restored on the stack allocated buffer.
	
	// Now, in Debug mode, we see in the console: "Allocating 8 bytes"
	// Then, we switch to the Release mode, we can see there is nothing in the console.
	// we can see that there is no heap allcation for the small string
	
	// and let's have a try
	// std::string str_short = "123456789012345"; // no allocation
	// std::string str__long = "1234567890123456"; // allocating 32 bytes
}