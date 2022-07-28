#include "temp.h"

// function
void fun(){
    logn( "Function Called" )
}

int main(void){
    // assigning function to variable method 1
    auto x = fun;   // c++11
    x();

    
    // assigning function to variable method 2
    void (*y)() = fun;   // the y is our variable
    y();
    
    return 0;
}