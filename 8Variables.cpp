#include <iostream>

int main(void){
    int a = 8;   // declaration+definition+initialization, it is a signed integer variable.
    a = 3;   // reassignment

    unsigned int b = 98;   // it is an unsigned integer variable

    // theres no distinction here, data types can be used by programmer in anyway
    char c = 'A';
    short d = 65;
    std::cout << c << " " << d << std::endl;

    float e = 5.6;   // will become double
    float f = 5.7f;   // this will remain float
    float g = 5.8F;   // this will remain float

    bool h = true;

    std::cout << sizeof(bool) << std::endl;

    return 0;
}