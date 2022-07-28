#include "temp.h"

// Type system due to cpp being strongly typed language

// The types are actually memory, so you can directly access memory
// So you have initialized a variable as int but you on purpose use it as a float
// You will get totally different result but the memory is the same and can be interpreted as different data types

// e.g you want to print your class's memory as a string
// You can just interpret the class as a byte array

// 

int main(void){
    // 1. MEMEORY KEPT SAME
    int a = 10;   // memory stored data in int format, only int data types can interpret this memory correctly
    double* b = (double*)&a;   // double gets the same exact memory without copying
    logn(a << " " << *b)   // double tries to interpret the same memory as a double and fucks up

    // 2. MEMORY CHANGED
    double c = a;   // this is copying the memory of a and interpreted as an int then converted to double and stored as a double in new memory (copying)
    logn(a << " " << c)   // so ofc c is interpreting memory stored as double and doing a good job

    // In case two the implicit conversion is actually:-
    c = (double)a;   // this is happening behind the scenes

    return 0;
}