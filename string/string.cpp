#include <iostream>
#include <string>

// Use string parameter in a function, 
// using 'const string&' to avoid string copying
// to get good performance, string copy is slow
void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}
// Modify string in a function
void AddString(std::string& string)
{
	string += " hello!";
}

int main()
{
	const char* name = "Tommy";
	char name2[5] = { 'T', 'o', 'm', 'm', 'y' };
	std::cout << name << std::endl; // Tommy
	std::cout << name2 << std::endl;  //Tommy*****

	std::cin.get(); // Set an interuption point here
	// Open Debug->Window->Memory or Press Alt + 6 when debugging
	// Check name and name2 in the memory window, 
	// we will find there is several '0' after name
	// and we will find there is several 'cc' after name2
	// That's why std::cout cannot get the end of name2 and print *** out

	// So let's add a '\0' after name2
	char name3[6] = { 'T', 'o', 'm', 'm', 'y', '\0' };
	// or
	char name4[6] = { 'T', 'o', 'm', 'm', 'y', 0 };
	std::cout << name3 << std::endl;  //Tommy
	std::cout << name4 << std::endl;  //Tommy
	// That's how string array works

	// In standard C++ library
	std::string name5 = "Tommy";
	std::cout << name5 << std::endl;  //Tommy
	std::cout << name5.size() << std::endl; //5
	std::cout << name5.find("my") << std::endl; //3
	bool contains = name5.find("lo") != std::string::npos;
	std::cout << contains << std::endl; //0

	// If we want to use a string parameter in a function
	// Remember to use 'const string&' to avoid string copy to get good performance
	// String copying is slow
	AddString(name5);
	PrintString(name5);

	// String literals: The read-only section of memory
	// Tommy is actually 5 characters, but there is a '\0' after them.
	const char name6[6] = "Tommy";
	// We cannot change the character in const char
	char *name7 = (char*)"Tommy";
	// name7[2] = 'a';  // This line of code will cause a runtime error, try uncomment it and run the code
	std::cout << name7 << std::endl;
	// The use of other char type
	const char* name8 = u8"Tommy";  // 1 Byte
	const wchar_t* name9 = L"Tommy"; // Decide by complier, 2 Bytes for Windows, 4 Bytes for Linux/Mac
	const char16_t* name10 = u"Tommy"; // 2 Bytes
	const char32_t* name11 = U"Tommy"; // 4 Bytes

	// The new feature of string literals in C++ 14
	using namespace std::string_literals;
	std::string name12 = "Tommy"s + " hello!";
	// Before C++ 14, we have to write like:
	std::string name13 = std::string("Tommy") + " hello!";
	std::cout << name12 << std::endl;

	// And there are more new features in C++ 14 like:
	std::wstring name14 = L"Tommy"s + L" hello!";
	std::u16string name15 = u"Tommy"s + u" hello!";
	std::u32string name16 = U"Tommy"s + U" hello!";
	const char* string0 = R"(Line1
		Line2
		Line3
		Line4)";
	const char* string1 = "Line1\n"
		"Line2\n"
		"Line3\n"
		"Line4\n";
	std::cout << string0 << std::endl;
	std::cout << string1 << std::endl;
}