#include <iostream>
#include <GLFW/glfw3.h>

// Static library: Linking while compiling. (compile time linking)
// Dynamic library: Linking while running. (runtime linking)

// Property settings
// include files: project properties -> VC++ directories -> Include directories.
// lib files: 
//    1. project properties -> Linker -> General -> Additional Library directories. (the lib path)
//    2. project properties -> Linker -> Input -> Additional Dependencies. (the lib name)
// Remember: we use glfw3dll.lib this time.

// The last thing to do: put the .dll file to the directory of .exe executable file.

int main()
{
	int a = glfwInit();
	std::cout << a << std::endl;
}