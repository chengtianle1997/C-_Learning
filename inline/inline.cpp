#include <iostream>

// Inline function is equivalent to writting the contents of the inline function at the call of the inline function
// It is equivalent to directly execute the function body without executing the steps of entering the function
// Equivalent to a macro(#define), but with more type checking, it really has function characteristics
// The complier generally does not inline functions that include complex operations like loops, recursion, and switch
// Functions defined in class declarations, other than virtual functions, are automatically implicitly treated as inline functions

// inline function
inline int Print(int a, int b);

inline int Print(int a, int b)
{
	std::cout << a << "," << b << std::endl;
	return a;
}

// inside class definition, implicitly inline
class A
{
	int doA() // actually inline function defined implicitly
	{
		return 0;
	}
};

// outside class definition, need to be explicitly inlined
class B
{
	int doB();
};

inline int B::doB()
{
	return 0;
}

int main()
{
	Print(2, 3);
}

// Remember, inline functions are just suggestions to the compiler. The decision whether to inline functions
// is up to the compiler.