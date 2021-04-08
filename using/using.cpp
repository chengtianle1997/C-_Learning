#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

// using namespace std;
// uncomment this line of code, and "Ctrl + H" to replace 'std::' with ''
// remember to use the option 'replace all', and we will find that everything works well.


void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}

namespace apple {
	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange {
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

namespace pear {
	void print(std::string text)
	{
		std::cout << "Hey, it's pear!" << std::endl;
	}
}

int main()
{
	// and we can use 'using namespace std;' here
	// using namespace std;

	std::vector<int> values = { 1, 2, 3, 4, 5 };
	auto lambda = [=](int value) { std::cout << value << std::endl; };
	ForEach(values, lambda);

	// However, by avoiding using namespace std, 
	// it is easier for us to know where those methods actually come from.
	apple::print("Hello!");
	orange::print("Hello!");
	// by using namespace
	using namespace apple;
	using namespace orange;
	print("Hello!"); // actually calling orange::print()
	// Because "Hello" is actually a const char* which is the same as orange::print(const char*),
	// it is a better match than convert const char* to std::string in apple::print(std::string).
	using namespace pear;
	// print(std::string("Hello")); // this line of code will cause an error.

	// Remember: never using namespace in the header file to avoid possible errors in future!
	//           if we do need to using namespace of our own namespace, try to use in the smallest scope,
	//           such as inside an if statement and inside a function.
}