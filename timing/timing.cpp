#include <iostream>
#include <chrono>
#include <thread>

// In Windows, we have a precise timer called "query_performance_counter"

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer Spent: " << ms << "ms" << std::endl;
	}
};

void Function()
{
	Timer timer;
	for (int i = 0; i < 100; i++)
	{
		// std::cout << "Hello!" << std::endl; // 120 - 150ms, because std::endl is quite slow.
		std::cout << "Hello!\n";  // 50 - 80ms
	}
}

int main()
{
	using namespace std::literals::chrono_literals; // for operator 's'

	auto start = std::chrono::high_resolution_clock::now();

	std::this_thread::sleep_for(1s);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;

	std::cout << "Time Spent: " << duration.count() << "s" << std::endl;

	// Use struct Timer
	Function();

}