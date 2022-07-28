#include "temp.h"
#include <array>

// Array data structure: the one used in the standard library, its implementation:-
// benefits: it is allocated on the stack instead of heap so its very fast
// properties: 1. fix size, 2. stack allocated

// alloca() allows us to allocate memory on the stack
// this is extrememly useful

// we dont use the alloca() approach as we are trying to optimize this here

class Array{
    // int m_Data[];   // what do we do now?
    int * m_Data;
public:
    Array(int size){
        m_Data = (int*)alloca(size);   // this will fix all issues, but it has issues like compiler does not know the size so it cant optimize
    }
};

int main(void){
    

    return 0;
}