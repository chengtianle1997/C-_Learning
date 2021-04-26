#include <iostream>
#include <future>

// The function template async runs the function f asynchronously 
// (potentially in a separate thread which might be a part of a thread pool) 
// and returns a std::future that will eventually hold the result of that function call.

int async_func(int val)
{
	return val;
}

int main()
{
	std::future<int> f = std::async(std::launch::async, async_func, 5);
	f.wait();
	std::cout << f.get() << std::endl;

	// About std::launch
	/*
	* std::launch::async -- a new thread is launched to execute the task asynchronously
	* std::launch::deferred -- the task is executed on the calling thread the first time its result is requested (lazy evaluation)
	*/
}