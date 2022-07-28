#include <iostream>

int main(void){
    union{
        float a;
        int b;
    };
    a = 10;   // data is put in the memory allocated to the union, and it is put in the float format
    std::cout << a << ", " << b << std::endl;
    // here the a is in float format so a is giving correct output
    // but here, since int reads memory differently than float, it gives some weird value or basically float representation in decimals

    return 0;
}