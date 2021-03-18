#include <iostream>

// Struct and Class
// In general, struct is more suitable as an implementation of a data structure
// and class is more suitable as an implementation of an object

// The most essential difference is the default access control
// 1. Default inherited access rights, struct is public and class is private
// 2. Default data access control of struct is public, 
//    Default member variable access control is private

struct Ball
{
	int x = 10, y = 10;

	void Move(int m_x, int m_y)
	{
		x += m_x;
		y += m_y;
	}
};

struct SpecialBall:Ball
{
	int size = x * y;
	
	void PrintSize()
	{
		std::cout << size << std::endl;
	}
};

class Player
{
public:
	// Remember: every class has its default constructor like this:
	//Player();
	//Player() = default;
	// If we do not need a constructor in class, write like this:
	//Player() = delete;

	int x = 10, y = 10;

	void Move(int m_x, int m_y)
	{
		x += m_x;
		y += m_y;
	}
};

class SpecialPlayer : public Player
{
public:
	// We can access x and y here without public inherited the parent class
	int size = x * y;
	// But we cannot access x and y outside of the class without public inherited

	void PrintSize()
	{
		std::cout << size << std::endl;
	}
};

int main()
{
	// You can see that struct and class are almost the same
	Ball ball;
	Player player;
	std::cout << ball.x << "," << ball.y << std::endl;
	std::cout << player.x << "," << player.y << std::endl;
	ball.Move(1, 1);
	player.Move(1, 1);
	std::cout << ball.x << "," << ball.y << std::endl;
	std::cout << player.x << "," << player.y << std::endl;
	// The difference: we need to declare a public in the class to make
	// its member variable accessible

	SpecialBall s_ball;
	SpecialPlayer s_player;
	std::cout << s_ball.x << "," << s_ball.y << std::endl;
	std::cout << s_player.x << "," << s_player.y << std::endl;
	s_ball.Move(10, 10);
	s_player.Move(10, 10);
	std::cout << s_ball.x << "," << s_ball.y << std::endl;
	std::cout << s_player.x << "," << s_player.y << std::endl;
	s_ball.PrintSize();
	s_player.PrintSize();

}