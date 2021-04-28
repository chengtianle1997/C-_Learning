#include <iostream>
#include <string>

int GetValue()
{
	return 10;
}

int& GetLValue()
{
	int value = 10;
	return value;
}

void SetValue(int value)
{

}

void SetValueRef(int& value)
{

}

void PrintName(std::string& name) // we use reference pass here to distinguish rvalue
{
	std::cout << name << std::endl;
}

void PrintNameAll(const std::string& name) // compatible to both lvalue and rvalue
{
	std::cout << name << std::endl;
}

// and actually, we have a way to only get the rvalue reference
void PrintNameRvalue(std::string&& name)
{
	std::cout << name << std::endl;
}

// overload function for both lvalue and rvalue reference
void PrintNameCheck(const std::string& name)
{
	std::cout << "[lvalue]" << name << std::endl;
}

void PrintNameCheck(std::string&& name)
{
	std::cout << "[rvalue]" << name << std::endl;
}
// and these two functions is a way to detect temporary values (rvalue) and do something special

int main()
{
	int i = 10;
	// i is the left value on the left side of the equal sign
	// 10 is the right value on the right side of the equal sign

	// left value has a location
	// so 10 (as an integer) cannot be a left value
	// and we cannot write like: 10 = i;

	int a = i;
	// here, we assign the left value 'a' with another left value 'i'
	// we can see that the equal sign not always make sense to help us 
	// distinguish the left value with the right value.

	i = GetValue();
	// GetValue() returns a right value, it is not an integer variable with an address
	// it is just '10', which is an right value, and we cannot write like: GetValue() = 5;

	GetLValue() = 5; // with reference, we can make that function a lvalue, see GetLValue() definition.

	SetValue(i);
	SetValue(10);   // we can convert a right value to a left value here.

	SetValueRef(i);
	// SetValueRef(10);  // we cannot convert a right value to a non-const left value reference

	// as we mentioned above about non-const
	// actually, we can convert a right value to a const left value reference
	const int& b = 10;
	// but we cannot convert a right value to a non-const left value reference
	// int& c = 10;  // this line of code will cause an error

	// but we can do like:
	int temp = 10;
	int& d = temp;
	// here, we change a rvalue to a lvalue
	// and then change a lvalue to a lvalue reference

	// Then, let's talk about std::string
	std::string firstName = "Tommy";
	std::string lastName = "Jerry";
	std::string fullName = firstName + lastName;

	PrintName(firstName); // firstName is lvalue
	PrintName(lastName); // lastName is lvalue
	PrintName(fullName); // fullName is lvalue
	// PrintName(firstName + lastName);  // firstName + lastName is rvalue

	PrintNameAll(firstName);
	PrintNameAll(lastName);
	PrintNameAll(fullName);
	PrintNameAll(firstName + lastName); // pass by const reference

	// and actually, we have a way to only get the rvalue reference
	// PrintNameRvalue(fullName);  // here, we cannot convert a left value to a right value reference
	PrintNameRvalue(firstName + lastName);

	PrintNameCheck(fullName);
	PrintNameCheck(firstName + lastName);
}