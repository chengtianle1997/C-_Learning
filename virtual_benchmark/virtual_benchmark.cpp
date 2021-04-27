#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

class Timer
{
public:
	Timer(const char* name)
		: m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << m_Name << ": " << ms << "ms\n";
	}

private:
	const char* m_Name;
	bool m_Stopped;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;

};

// Code above is a traditional timer
// Let's see Instrumentor class which record everything into a json profile
// and that profile can be visualized in chrome://tracing
#include "Instrumentor.h"
#define INST

#ifdef INST
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
// Get the function name automatically by preprocesser
// #define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__) 
// Get the function and input and output types
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#endif

void Function1()
{
#ifdef INST
	// InstrumentationTimer timer("Function1");
	// PROFILE_SCOPE("Function1");
	PROFILE_FUNCTION();
#elif TIMER
	Timer timer("Function1");
#endif
	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World #" << i << std::endl;
}

void Function2()
{
#ifdef INST
	// InstrumentationTimer timer("Function2");
	// PROFILE_SCOPE("Function2");
	PROFILE_FUNCTION();
#elif TIMER
	Timer timer("Function2");
#endif
	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World #" << sqrt(i) << std::endl;
}

void RunBenchmarks()
{
	// InstrumentationTimer timer("RunBenchmarks");
	// PROFILE_SCOPE("RunBenchmarks");
	PROFILE_FUNCTION();
	std::cout << "Run Benchmarks ... \n";
	Function1();
	Function2();
}

int main()
{
	Instrumentor::Get().BeginSession("result.json");
	Function1();
	Function2();
	RunBenchmarks();
	Instrumentor::Get().EndSession();

	// After running, we can find the result.json file in our directory
	// Now, drag it into the chrome://tracing and see the visualization result.

}
