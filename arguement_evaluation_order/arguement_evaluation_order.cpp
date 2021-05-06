#include <iostream>

void PrintSum(int a, int b)
{
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

int main()
{
	int value = 0;
	PrintSum(value++, value++); 
	// Debug mode: 1 + 0 = 1, 
	// the result may varies for different settings and compilers
	// For example, let's try the Release mode
	// 0 + 0 = 0

	value = 0;
	PrintSum(++value, ++value);
	// Debug mode: 2 + 2 = 4
	// Release mode: 2 + 2 = 4

	// in C++ 17, there is a new instruction:
	// The postfix-expression is sequenced before each expression in the
	// experssion-list and any default argument. The initialization of a
	// parameter, including every associated value computation and side 
	// effect, is indeterminately sequenced with respect to that of any 
	// other parameter.

	// try line 11 in Wandbox (an online compiler) https://wandbox.org/
	// use both gcc and clang compiler, we will see different result.

	// In conclusion, the result of those lines of code is "undefined"
	// because it depends on the setting and the compiler, and we cannot
	// do that from C++ 17, we are supposed to initialize the parameter
	// first and pass them to the function.
}