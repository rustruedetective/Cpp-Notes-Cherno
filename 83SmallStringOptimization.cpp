#include "temp.h"

// SSO: small string optimization

// strings are in general very slow and also memory allocation heavy
// (c++) + (heap allocations) = bad

// stl optimized strings...
// they made small strings allocated on the stack instead of heap
// now what length is this small string depends on the compiler
// e.g on 15 char length string on visual studio is allocated on the stack

int main(void){
    // this is allocated on the stack (most probably dep on ur compiler)
    std::string name = "goody";
    // so no need to do this
    // const char * name2 = "goody";

    return 0;
}