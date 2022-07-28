#include "temp.h"
#include <array>

// Array data structure: the one used in the standard library, its implementation:-
// benefits: it is allocated on the stack instead of heap so its very fast
// properties: 1. fix size, 2. stack allocated

// alloca() allows us to allocate memory on the stack
// this is extrememly useful

// we dont use the alloca() approach as we are trying to optimize this here

// we use the template approach

template <typename T,size_t S>
class Array{
    T m_Data[S];
public:
    int Size() const { return S; }
};

int main(void){
    Array<int, 5> data;

    // now we have a get size function
    data.Size();

    return 0;
}