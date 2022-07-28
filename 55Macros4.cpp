#include <iostream>

// Now this is automatic
// #define DEBUGMODE   // commenting out is same as not defined in settings

// This is good when you have an ide like vs
// And you have defined Preprocessor Macros in settings
// e.g macro for debug mode or for release mode

// But this is a bit bad compared to previous example

// Cancelling logging in Production Mode
#ifdef DEBUGMODE
#define log(x) std::cout << x;
#define logs(x) std::cout << x << " ";
#define logn(x) std::cout << x << std::endl;
#else
#define log(x) 0;
#define logs(x) 0;
#define logn(x) 0;
#endif

int main(void)
{
    logn("hi"
         << " "
         << "There") return 0;
}