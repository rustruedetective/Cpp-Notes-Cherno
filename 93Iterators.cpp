#include "temp.h"
#include <vector>

// Iterators:
// they are usually used to iterate in data structures
// but they can be used to do other stuff as well... just like operator overlaoding...e.g different data structures will have different ways to be traversed

// you can write a class and put iterators in it

// Iterator inner working:
/*
    a range based for loop works when the vector class provides a begin and an end function which returns an iterator at a particular position
    Note that the iterator these functions return is a type of data called iterator which the collections have
    the iterator data type can be dreferenced (overloaded) to give the current element of collection
    so the 1. is a short hand version of 2.
*/

// why would you use 2. if you already have 1.?
// well you have control over the iterator
// you could erase/insert etc some value and change the iterators current location etc all the while keep iterating over the collection

int main(void){
    // for traversing
    std::vector<int> values = {1,2,3,4,5};

    // 1.
    logn("Short version: ")
    for(int i : values)   // ranged based for loop: c++11
        logs(i)
    logn("")

    // 2.
    logn("Long version: ")
    for(std::vector<int>::iterator it = values.begin(); it < values.end(); it++)
        logs(*it)
    logn("")

    return 0;
}