#include "temp.h"

// c++11 needed

// c++ can automatically deduce the type of data we are assigning or initializing
// Using the "auto" keyword

// e.g a function returning string we can assign to a variable with "auto" data type
// "auto" will automatically deduce the data type

// auto CANNOT be used as a data type receiving any data type any time
// once it deduces type it wont change

// Pros:-

// Cons:-

int main(void){
    int a = 5;
    auto b = a;   //int deduced
    logn( b )

    auto x = 10;   //int deduced
    auto x2 = 10L;   //long deduced
    auto x3 = 10.1f;   //float detected
    logs(x) logs(x2) log(x3)
    logn("")

    // e.g here once its deduced that var is int, it cant be reassigned to other types
    auto var = 10;
    // var = "Stringy guy";   // this gives invalid conversion error

    return 0;
}