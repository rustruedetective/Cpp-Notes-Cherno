#include<iostream>

// Now this is all manual...
#define DEBUGMODE false

// This example is better than the next one

// Cancelling logging in Production Mode
#if DEBUGMODE
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
    logn("hi" << " " << "There")
    return 0;
}