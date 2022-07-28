#include<iostream>

// Improved version of 3, use this in real world
// It is the best way as it grants more control

#define DEBUGMODE 0

#if DEBUGMODE == 1
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