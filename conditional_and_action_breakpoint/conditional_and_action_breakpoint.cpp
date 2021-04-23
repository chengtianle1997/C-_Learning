#include <iostream>

// Breakpoints triggered by certain condition
// 1. Add a breakpoint and click on the 'setting icon' button.
// 2. Set the condition or action.

int main()
{
	int a = 10;
	int b = 5;  // condition breakpoint a == 5
	a = 5;   // action breakpoint: the value of a is {a}
	return 0;  // condition breakpoint a == 5
}