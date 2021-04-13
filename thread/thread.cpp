#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		std::cout << "Working...\n";
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::thread worker(DoWork); // Here, we takes in the function pointer of DoWork

	std::cin.get();
	s_Finished = true;
	std::cout << "Finished!" << std::endl;
	std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
	
	worker.join(); // Wait for the thread to be joining on and block the current thread (main thread)
}