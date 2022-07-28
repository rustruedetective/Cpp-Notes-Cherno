#include "temp.h"

// You can change their data type (if compatible with int)
//in -std=c++11 or -std=gnu++11

enum Example : char{
    A, B, C
};

enum Example2 : unsigned char{
    A1, B1, C1
};

int main(void){
    int value = A;

    if(value == A){
        logn("Equal")
    }
    if(value != B){
        logn("Not Equal")
    }
    
    return 0;
}