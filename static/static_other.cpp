#include <iostream>
static void OtherFile()
{
	std::cout << "This is the static function from other file." << std::endl;
	return;
}

void OtherFile_nonstatic()
{
	std::cout << "This is the non-static function from other file." << std::endl;
	return;
}