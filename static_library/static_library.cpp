#include <iostream>
#include <GLFW/glfw3.h>

// if the header file is in standard library or included by setting project properties, use <>
// if the header file is right in the project path, use ""

// Property settings
// include files: project properties -> VC++ directories -> Include directories.
// lib files: 
//    1. project properties -> Linker -> General -> Additional Library directories. (the lib path)
//    2. project properties -> Linker -> Input -> Additional Dependencies. (the lib name)

int main()
{
	int a = glfwInit();
}