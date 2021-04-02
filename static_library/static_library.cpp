#include <iostream>
#include <GLFW/glfw3.h>

// if the header file is in standard library or included by setting project properties, use <>
// if the header file is right in the project path, use ""

// Property settings
// include files: project properties -> VC++ directories -> Include directories.
// lib files: 
//    1. project properties -> Linker -> General -> Additional Library directories. (the lib path)
//    2. project properties -> Linker -> Input -> Additional Dependencies. (the lib name)

// About include files
// In fact, what the include files do is just declaring the function, like:
extern "C" int glfwInit();
// try to comment "#include <GLFW/glfw3.h>" in line 2, we can see that everything works well.
// the definition of the function that declared in header files is in static library files (.lib)

int main()
{
	int a = glfwInit();
	std::cout << a << std::endl;
}