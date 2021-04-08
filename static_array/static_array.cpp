#include <iostream>
#include <array>

// Use template when we do not know the exact size of the static array
// Instead of 'void Print(std::array<int, 5> data)'
template <typename T>
void Print(T data)
{
	for (int i = 0; i < data.size(); i++)
	{
		data[i] = 3;
	}
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	std::array<int, 5> data;
	data[0] = 2;
	std::cout << data.size() << std::endl;
	std::cout << data.max_size() << std::endl;
	std::cout << data[0] << std::endl;
	Print(data);
}