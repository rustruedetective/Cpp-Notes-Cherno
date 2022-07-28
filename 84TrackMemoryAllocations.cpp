#include "temp.h"

// Tracking allocations and deallocations of memory
// So what we do is record whereever the memory was allocated and deallocated so when we forget about it we can review this really quickly

void * operator new(size_t size){
    // we can also put a break point once in this function
    // and get stopped whenever memory is allocated
    logn("Allocated: " << size << " bytes")
    return malloc(size);
}

struct Object{
    int x, y, z;
};

int main(void){
    Object* obj = new Object;
    return 0;
}