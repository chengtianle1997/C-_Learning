#include <iostream>
#include <vector>

// lambda give us a way to define a function without having to define a function.
// lambda are usually used with a function pointer.

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

int main()
{
	// lambda function pass to another function by function pointer.
	std::vector<int> values = { 1, 2, 3, 4 };
	ForEach(values, [](int value) { std::cout << value << std::endl; });

	// use auto keyword
	auto lambda = [](int value) { std::cout << value << std::endl; };
	ForEach(values, lambda);
}