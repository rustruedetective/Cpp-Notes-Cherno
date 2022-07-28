#include <iostream>
#include "abc.h"

// you need to compile both source files! so => gcc main.cpp abc.cpp
// i did not put ifdefs in the header file

int main(void){
    abc obj;
    obj.fun();

    return 0;
}