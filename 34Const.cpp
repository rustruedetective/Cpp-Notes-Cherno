#include "temp.h"

// Const doesnt change the generated code
// It merely modifies visibility

// Its like a promise, which can be broken
// e.g we declare something constant but change it later

int main(void){
    int a = 5;
    a = 2;

    const int b = 5;
    // b = 2;   // cannot be changed

    const int Max_AGE = 90;   //we could use const here, so keep a value fixed for reference, or simply to not change it throughout the program
    
    return 0;
}