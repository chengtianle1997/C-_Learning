#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// lambda give us a way to define a function without having to define a function.
// lambda are usually used with a function pointer.

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

// class template function
void ForEach_a(const std::vector<int>& values, const std::function<void(int)>& func) 
{
	for (int value : values)
		func(value);
}

int main()
{
	// lambda function pass to another function by function pointer.
	std::vector<int> values = { 1, 2, 3, 4 };
	ForEach(values, [](int value) { std::cout << value << std::endl; });
	// [] captures nothing
	// [=] captures all by value
	// [&] captures all by reference
	// [a, &b] captures a by value, b by reference
	// [this] captures the current object (*this) by reference

	// use auto keyword
	auto lambda = [](int value) { std::cout << value << std::endl; };
	ForEach(values, lambda);

	std::cout << std::endl;
	// when we try to use variables outside the lambda function
	int a = 5;
	auto lambda_a = [=](int value) { std::cout << a << std::endl; };
	auto lambda_b = [&](int value) { a = 10; std::cout << a << std::endl; };
	auto lambda_c = [&a](int value) { a = 10; std::cout << a << std::endl; };
	lambda_a(1);  // Print '5'
	lambda_b(1);  // Print '10'
	lambda_c(1); // Print '10'
	// ForEach(values, lambda_a);  // this line of code will cause an error.
	ForEach_a(values, lambda_a); // Print '5 5 5 5'

	// get the first value >= 3 of the vector
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value >= 3; });
	std::cout << *it << std::endl;  // Print '3'

}