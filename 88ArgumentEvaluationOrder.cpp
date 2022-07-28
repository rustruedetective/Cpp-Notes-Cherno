#include "temp.h"

void PrintSum(int a, int b){
    logn( a << " + " << b << " = " << (a+b) )
}

int main(void){
    int value = 0;
    PrintSum(value++, value++);
    // a.
    // 1 + 0 = 1 for debug mode in g++ on windows (c++17)
    // 1 + 0 = 1 for release mode in g++ on windows (c++17)

    // b.
    // 1 + 0 = 1 for debug mode in vs compiler (c++11)
    // 0 + 0 = 0 for release mode in vs compiler (c++11)

    // 1 + 0 = 1 for debug mode in vs compiler (c++17)
    // 1 + 0 = 1 for release mode in vs compiler (c++17)

    // c.
    // 0 + 1 = 0 for clang

    PrintSum(++value, ++value);
    // d.
    // 4 + 4 = 8 for debug mode in g++ on windows (c++17)
    // 4 + 4 = 8 for release mode in g++ on windows (c++17)

    // e.
    // 2 + 2 = 4 for debug mode in vs compiler (c++11)
    // 2 + 2 = 4 for release mode in vs compiler (c++11)

    return 0;
}