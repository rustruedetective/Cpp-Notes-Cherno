#include "temp.h"

// The default values are 0, 1, 2... for enums
// They increment values

//*You cannot re-assign same enum name in another group

// 0, 1, 2
enum Example{
    A, B, C
};

enum DiffValuesExample{
    A1=10, B1=20, C1=30
};

// 10, 11, 12
enum DiffValuesExample2{   //automatically increments next values
    A2=10, B2, C2
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