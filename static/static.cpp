# include <iostream>

// First, static variable in a function
void Function()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

// Second, static member in a class
class Entity
{
public:
	static int x, y;
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
	static void Print_static()
	{
		std::cout << x << "," << y << std::endl;
	}
};

// And we have to declare x and y
int Entity::x;
int Entity::y;

// Third, static global functions and variables can only be used in the file which it is defined
// for example, there is a declaration of a function OtherFile() in static_other.cpp
// and we cannot call it from this file (static.cpp)
// uncomment the code below will cause an linking error
//void OtherFile();
// Successfully non-static function call from other files
void OtherFile_nonstatic();


int main()
{
	// Call Function() several times
	Function();
	Function();
	Function();
	Function();
	Function();
	// We can see i increase from 1 to 5
	// That means static variable in a function can be used just like a global variable

	Entity::x = 2;
	Entity::y = 3;
	// Have to do this, because Print() function is non-static
	Entity e;
	e.Print();
	// If Print() is a static function, we can call it directly
	Entity::Print_static();

	// Call function from other file
	// uncomment the code below will cause an linking error
	//OtherFile();
	// Successfully non-static function call from other files
	OtherFile_nonstatic();
	
	// In conclusion, 
	// static variable and static function make the struct or class like a 'namespace',
	// 'Entity::Print_static' kind of like 'std::cout'.
}