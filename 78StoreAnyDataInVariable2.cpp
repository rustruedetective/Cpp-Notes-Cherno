#include "temp.h"
#include <any>

// this is to be checked in the call stack
// if called then std::any just allocated on the heap
// yes this is a neat way of debugging
void* operator new(size_t size){
    return malloc(size);
}

struct CustomStringVec
{
    std::string s0, s1;
};


int main(void){
    std::any data;
    // no heap allocations, as size is less than 32 bytes
    data = std::string("Hi im a lad");
    std::string& string = std::any_cast<std::string&>(data);

    // now as size is greater than 32 bytes the new will be called (heap allocation)
    data = CustomStringVec();

    return 0;
}