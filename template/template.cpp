#include <iostream>
#include <string>

/*
* In C++ this can be achieved using template parameters. 
* A template parameter is a special kind of parameter that can be used to pass a type as argument: 
* just like regular function parameters can be used to pass values to a function, template parameters 
* allow to pass also types to a function. These function templates can use these parameters as if they 
* were any other regular type.
*/


template<typename T>
// we can also write like:
// template<class T>
// which is just the same as the first line of code ('typename' == 'class' here), try it.
void Print(T value)
{
	std::cout << value << std::endl;
}
// This function is actually a template which is created when we call it.


template<int N>
class Array
{
private:
	int m_Array[N];
public:
	int GetSize() { return N; }
};

// more template this time
template<typename T, int N>
class ArrayT
{
private:
	T m_Array[N];
public:
	int GetSize() { return N; }
};

int main()
{
	Print(5);
	Print("Hello!");
	Print(5.5f);
	// When we call the function, 'T' become the specific type of the parameter.

	// we can also write like:
	Print<int>(5);
	Print<std::string>("Hello!");

	// Create class Array
	Array<10> array;
	std::cout << array.GetSize() << std::endl;
	ArrayT<std::string, 15> arrayT;
	std::cout << arrayT.GetSize() << std::endl;

}