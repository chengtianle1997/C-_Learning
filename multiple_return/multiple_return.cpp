#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>

// 1. Use reference to return value of two types 
void reference_return(std::string& string, int& value)
{
	string[1] = 'i';
	value = 20;
}

// 2. Use pointer to return value of two types 
void pointer_return(std::string* string, int* value)
{
	(*string)[1] = 'a';
	*value = 30;
}

// 3. Use array to return multiple value of single type
std::string* array_return(std::string string)
{
	return new std::string[]{ string, string };
	// Note that we reallocate a string array on the heap (not recommended)
}
// Instead, we use std::array
std::array<std::string, 2> std_array_return(std::string string)
{
	std::array<std::string, 2> result;
	result[0] = string;
	result[1] = string;
	return result;
}
// Also, we can try vector
std::vector<std::string> std_vector_return(std::string string)
{
	std::vector<std::string> result;
	result.push_back(string);
	result.push_back(string);
	return result;
}

// 4. Use tuple to return different types of variables
std::tuple<std::string, int> tuple_return(std::string string, int value)
{
	string[1] = 'o';
	value = 40;
	return std::make_pair(string, value);
}
// Also, we can use pair
std::pair<std::string, int> pair_return(std::string string, int value)
{
	string[1] = 'i';
	value = 50;
	return std::make_pair(string, value);
}

// 5. Use struct to return value
struct returnParam
{
	std::string string;
	int value;
};

returnParam struct_return(std::string string, int value)
{
	string[0] = 'N';
	value = 60;
	return { string, value };
}

void Print(std::string string, int value)
{
	std::cout << string << ", " << value << std::endl;
}

int main()
{
	std::string string = "Tommy";
	int value = 10;

	std::cout << "Reference return:" << std::endl;
	reference_return(string, value);
	Print(string, value);

	std::cout << "Pointer return:" << std::endl;
	pointer_return(&string, &value);
	Print(string, value);

	std::cout << "Array return:" << std::endl;
	std::string* str_arr = array_return(string);
	std::cout << str_arr[0] << ", " << str_arr[1] << std::endl;
	std::cout << "Std Array return:" << std::endl;
	std::array<std::string, 2> res_arr = std_array_return(string);
	std::cout << res_arr[0] << ", " << res_arr[1] << std::endl;
	std::cout << "Std Vector return:" << std::endl;
	std::vector<std::string> res_vec = std_vector_return(string);
	std::cout << res_vec[0] << ", " << res_vec[1] << std::endl;

	std::cout << "Tuple return:" << std::endl;
	std::tuple<std::string, int> res_tup = tuple_return(string, value);
	Print(std::get<0>(res_tup), std::get<1>(res_tup));
	std::cout << "Pair return:" << std::endl;
	std::pair<std::string, int> res_pair = pair_return(string, value);
	Print(res_pair.first, res_pair.second);

	std::cout << "Struct return:" << std::endl;
	auto res_struct = struct_return(string, value);
	Print(res_struct.string, res_struct.value);
}