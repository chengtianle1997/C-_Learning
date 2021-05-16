#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// iterator is a new feature in C++ 11.

int main()
{
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

	std::unordered_map<std::string, int> map;
	map["Tommy"] = 1;
	map["apple"] = 2;
	map["banana"] = 3;
	for (std::unordered_map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
	for (auto key_value : map)
	{
		std::cout << key_value.first << ": " << key_value.second << std::endl;
	}
	// in C++ 17
	for (auto [key, value] : map)
	{
		std::cout << key << ": " << value << std::endl;
	}
}