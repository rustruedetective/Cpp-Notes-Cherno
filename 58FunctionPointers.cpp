#include "temp.h"

// function pointers in C

// they are to make a function assign to a variable

// C++ implicitly takes address of function so no need to put &function, c++ puts the & itself

/*
Theory:
functions are stored in memory, so they have addresses too
*/

// function
void fun(){
    logn( "Function Called" )
}

int main(void){
    // normal call
    fun();

    // assign function's address to variable
    auto x = fun;   // c++11
    // or
    x = &fun;   // but we dont need this as c++ implicitly takes address of function
    x();   // function call
    
    return 0;
}