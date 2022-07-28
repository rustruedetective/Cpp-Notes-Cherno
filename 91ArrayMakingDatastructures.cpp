#include "temp.h"
#include <array>

// Array data structure: the one used in the standard library, its implementation:-
// benefits: it is allocated on the stack instead of heap so its very fast
// properties: 1. fix size, 2. stack allocated

int main(void){
    // stack allocated
    // its automatically delete when stack frame is popped
    int array[5];

    // heap allocated (thus its dynamic, we can have varying size initialization)
    int size = 5;
    int * heaparray = new int[size];
    // we also need to delete the heap allocated memory
    delete[] heaparray;



    // now c++ provides us with a standard array
    std::array<int, 10> collection = {0};

    // we can use iterator loop
    for(int i : collection)
        logn(i) 

    return 0;
}