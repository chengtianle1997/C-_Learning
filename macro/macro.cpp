#include <iostream>

#define WAIT std::cin.get()
#define WAIT_t std::cin.get();

// Project property settings
// C/C++ -> Preprocessor -> Preprocessor Definitions
// for 'Debug' mode: add 'PR_DEBUG'
// for 'Release' mode: add 'PR_RELEASE'

#ifdef PR_DEBUG  // macro for 'Debug' mode
#define LOG(x) std::cout << x << std::endl
#else           // macro for 'Release' mode
#define LOG(x)
#endif

// #define PR_DEBUG_VALUE 1
// we can also do this by set 'PR_DEBUG = 1' in property setting.
#if PR_DEBUG_VALUE == 1
#define LOG_T(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG_T(x)
#endif
// try to switch to the 'Release' mode

// make code invalid
#if 0
#define PI 3.14
#endif

#if 0
int main()
{
	WAIT;
	WAIT_t

	LOG("Hello!");

	LOG_T("Hello World!");

}
#endif

#if 1
// Multi-line macro for main function
#define MAIN int main() \
{\
	std::cout << "Main funtion here!" << std::endl;\
}

MAIN
#endif