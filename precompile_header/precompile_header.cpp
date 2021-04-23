#include "pch.h"

// Precompile header is actually a binary file which contains the 
// compiling result of the header files like <vector>, <string> and <iostream>.
// It definitely makes the compiling process faster. However, do not put any frequent changing 
// files such as out own files into a PCH, because it will need to be recompiled for changes in our own code.

// Step 1: Project Properties -> C/C++ -> Preprocessor -> Process to a File -> Switch to 'Yes(/P)' £¨This may cause error, just ignore it!£©
// Step 2: Right Click 'pch.cpp' -> Properties -> C/C++ -> Precompiled Headers -> Precompiled Header -> Switch to 'Create'
// Step 3: Project Properties -> C/C++ -> Precompiled Headers -> Precompiled Header -> Switch to 'Use'
//                                                            -> Precompiled Header File -> 'pch.h'
// Step 4: Tools -> Project and Solutions -> VC++ Project Settings -> Build - Build Timing -> Switch to 'Yes'

// Let's check it out: Remember to only build the project (Ctrl + B), not the whole solution (F7).
// A. Firstly, we return to Step 3 and choose NOT to USE Precompiled header.
//    a. Clean the project and Build it.  // it takes about 2.3 seconds
//    b. Add a line of code and Build it again. // it takes about 1.26 seconds

// B. Secondly, we return to Step 3 and choose to USE Precompiled header.
//    a. Clean the project and Build it.  // it takes about 1.49 seconds
//    b. Add a line of code and Build it again. // it takes about 0.4 seconds

// We can see that when we use the precompile headers, the compile time is less than the other,
// and it is about three times faster.


int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello World!" << std::endl;
}