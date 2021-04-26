#include <iostream>
#include <future>
#include <thread>


// multi-threading: make C++ run faster

int task_func()
{
	return 7;
}

int async_func()
{
	return 8;
}

void prom_func(std::promise<int> p)
{
	p.set_value(9);
}

int main()
{
	// first, let's talk about std::future
	// std::future provides a mechanism to access the result of asynchronous operations.
	std::packaged_task<int()> task([] { return 7; }); // wrap the function (lambda function)
	// or
	std::packaged_task<int()> task_f(task_func); // wrap the function

	// get a future from a packaged_task
	std::future<int> f1 = task.get_future();

	// launch on a thread
	std::thread t(std::move(task));
	std::thread tf(std::move(task_f));

	f1.wait();
	std::cout << f1.get() << std::endl;  // 7

	t.join();
	tf.join();

	// future from an async()
	std::future<int> f2 = std::async(std::launch::async, async_func);
	f2.wait();
	std::cout << f2.get() << std::endl;  // 8

	// future from a promise
	std::promise<int> p;
	std::future<int> f3 = p.get_future();
	std::thread tp(prom_func, std::move(p)); // see the definition of void prom_func()
	f3.wait();
	std::cout << f3.get() << std::endl;  // 9
	tp.join();
}


