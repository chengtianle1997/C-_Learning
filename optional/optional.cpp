#include <iostream>
#include <fstream>
#include <optional>

std::string ReadFileAsString(const std::string& filepath, bool& outSuccess)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		outSuccess = true;
		return result;
	}
	outSuccess = false;
	return std::string();
}

// std::optional is a new feature in C++ 17
// Remember to switch the compiler to C++ 17
// Project property -> C/C++ -> Language -> C++ Language Standard -> Switch to 'C++ 17'
std::optional<std::string> ReadFileAsString_t(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		return result;
	}
	return {};
}

int main()
{
	bool fileOpenedSuccessfully;
	std::string data = ReadFileAsString("data.txt", fileOpenedSuccessfully);
	if (fileOpenedSuccessfully)
	{
		std::cout << "File read successfully:" << data << std::endl;
	}
	else
	{
		std::cout << "File could not be opened!\n";
	}

	std::optional<std::string> data_t = ReadFileAsString_t("data.txt");
	if (data_t.has_value())
	{
		std::string data_s = *data_t;
		// or
		data_s = data_t.value();

		std::cout << "File read successfully:" << data_s << std::endl;
	}
	else
	{
		std::cout << "File could not be opened!\n";
	}
	// or just 
	if (data_t)
	{
		std::string data_s = *data_t;
		std::cout << "File read successfully:" << data_s << std::endl;
	}
	else
	{
		std::cout << "File could not be opened!\n";
	}

	// set default: Delete the file 'data.txt' and run it again.
	std::string value = data_t.value_or("Not Present");
	std::cout << value << std::endl;
}