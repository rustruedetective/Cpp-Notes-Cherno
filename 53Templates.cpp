#include "temp.h"

// In Java and C# they are called Generics
// But C++ templates are alot better

// The compiler itself completes the code based on our templates

// The template function does not exist, until we call it in main, otherwise there is no code written for it by compiler

template <typename T>   // you can use class instead of typename
void print(T x){
    logn( x )
}

int main(void){
    // call method 1, compiler guessing the type
    print(5);
    print(5.5f);
    print('x');
    print("Go home!");

    // call method 2, explicitly telling compiler the type
    print<int>(5);
    print<float>(5.5f);
    print<char>('x');
    print<std::string>("Go home!");
    return 0;
}