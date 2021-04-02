#include "Engine.h"

// 1. Set additional include directories to $(SolutionDir)Engine
// 2. Right click project -> Add -> Reference -> "Engine"
// 3. Clean Solution -> Build "Game"
// we can see that we actually build the "Engine" firstly and then the "Game".
// 4. Run "Game", we can see "Hello World" is printed out successfully.

int main()
{
	engine::PrintMessage();
}