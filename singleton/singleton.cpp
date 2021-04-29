#include <iostream>

// Singleton: 
//    a software design pattern that restricts the instantiation of a class to one single instance.

class Singleton
{
public:
	// delete the copy constructor to avoid copy
	Singleton(const Singleton&) = delete;

	static Singleton& Get()
	{
		return s_Instance;
	}
	void Function()
	{

	}
private:
	Singleton() {} 
	// we make the constructor private to ensure that it cannot be instantiate outside the class

	static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

// The code above shows what a singleton class like, let's try an example.
class Random
{
public:
	Random(const Random&) = delete;
	
	static Random& Get()
	{
		// we can just define the instance in static type here.
		static Random s_random;
		return s_random;
	}

	float Float() { return m_RandomGenerator; };

	// or we can do like this (Part A, go and see Part B)
	static float sFloat() { return Get().IFloat(); }

private:
	Random() {};

	float m_RandomGenerator = 0.5f;

	// or we can do like this (Part B, go and see Part C)
	float IFloat() { return m_RandomGenerator; }
};

// the namespace which is identical to the singleton class
namespace RandomClass {
	static float s_RandomGenerator = 0.5f;
	static float Float() { return s_RandomGenerator; }
}


int main()
{
	// we cannot copy the instance after we deleting the copy constructor
	// Singleton instance = Singleton::Get();
	Singleton& instance = Singleton::Get();
	instance.Function();

	std::cout << Random::Get().Float() << std::endl;

	// or we can do like this: (Part C)
	std::cout << Random::sFloat() << std::endl;

	// So, let's have a look about what we have in a singleton class
	// 1. delete copy constructor:  Singleton(const Singleton&) = delete;
	// 2. Get() Function.
	// 3. Actual function.
	// 4. make constructor private.
	// 5. static instance and remember to initialize it outside of the class  
	//    or  just define a static instance in Get() function.
	// e.g.: private: static Singleton s_Instance; in class.
	//   and Singleton Singleton::s_Instance; outside of class.
	//   or  static Singleton s_Instance; in Get() function.


}
