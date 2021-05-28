#include <iostream>
#include <vector>  // the vector in STL
#include <string>
#include "Vector.h"  // our self-written vector class


int main()
{
#if 0
	std::vector<int> values = { 1, 2, 3, 4, 5 };
	for (int i : values)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (std::vector<int>::iterator it = values.begin(); it < values.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
#else
	Vector<int> values;
	values.emplace_back(1);
	values.emplace_back(2);
	values.emplace_back(3);
	values.emplace_back(4);
	values.emplace_back(5);
	for (int i : values)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (Vector<int>::iterator it = values.begin(); it != values.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (int value : values)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;

	Vector<std::string> string_vector;
	string_vector.push_back("C++");
	string_vector.push_back("Tommy");
	string_vector.push_back("Vector");
	for (std::string str : string_vector)
	{
		std::cout << str << std::endl;
	}
#endif
}