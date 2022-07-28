#include "temp.h"
#include <memory>

// but what if we have multiple allocatoins? then it will get messy

// we could make an array to keep track of all
// or maybe just a class to have total allocated etc

// Practical e.g:
// you also want to minimize your memory allocations (heap) frame to frame while your game loop is running
// so you can do that

// Concept of MEMORY ARENA!!!

struct AllocatedMatrices{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage(){ return TotalAllocated - TotalFreed; }
};
static AllocatedMatrices s_AllocatedMatrices;

static void PrintMemoryUsage(){
    std::cout << "Allocation: " << s_AllocatedMatrices.CurrentUsage() << " bytes\n";
}

void * operator new(size_t size){
    // breakpoint, optionally
    s_AllocatedMatrices.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size){
    s_AllocatedMatrices.TotalFreed += size;
    free(memory);
}

struct Object{
    int x, y, z;
};

int main(void){
    PrintMemoryUsage();
    std::string string = "Hi there buddy where were you? I was looking for you!";
    PrintMemoryUsage();
    Object* obj = new Object;
    PrintMemoryUsage();
    std::unique_ptr<Object> ptrObj = std::make_unique<Object>();
    PrintMemoryUsage();

    return 0;
}