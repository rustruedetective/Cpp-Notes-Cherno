#include "temp.h"

// local static effects
// 1. lifetime of variable
// 2. scope of variable

// 1. lifetime of local variable until program ends
// 2. scope limited to function or { brackets } or class

// the difference in class local static and function local static
// class one can be accessed by all members
// function one is limited to function's scope

// *Certain people discourage this

// here the static local will automatically be initilialized to zero
void function(){
    static int i = 0; 
    i++;
    logn(i);
}

int main(void){
    function();
    // i =29;   // i cant access it, its local to function
    function();
    function();
    return 0;
}