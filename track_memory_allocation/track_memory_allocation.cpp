#include <iostream>
#include <memory>

// a struct to track memory usage
struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage()
	{
		return TotalAllocated - TotalFreed;
	}
};

static AllocationMetrics s_AllocationMetrics;

void PrintMemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

// overload 'new' operator
void* operator new(size_t size)
{
	s_AllocationMetrics.TotalAllocated += size;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}
// overload 'delete' pointer
//void operator delete(void* memory)
//{
//	free(memory);
//}

void operator delete(void* memory, size_t size)
{
	s_AllocationMetrics.TotalFreed += size;
	std::cout << "Free " << size << " bytes\n";
	free(memory);
}

struct Object
{
	int x, y, z;

};

int main()
{
	{
		Object* obj = new Object;  // 12 bytes

		std::string string = "Tommy"; // 8 bytes

		// if we use smart pointers like unique pointer
		std::unique_ptr<Object> obj_smrt = std::make_unique<Object>(); // 12 bytes
		std::shared_ptr<Object> obj_shar = std::make_shared<Object>(); // 24 bytes

		delete obj; // we need to delete the pointer manually.
	}

	PrintMemoryUsage();
}