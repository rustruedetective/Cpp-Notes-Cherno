#include "temp.h"
#include <memory>

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
    {
        std::string string = "Hi there buddy where were you? I was looking for you!";
        PrintMemoryUsage();
        Object* obj = new Object;
        PrintMemoryUsage();
        std::unique_ptr<Object> ptrObj = std::make_unique<Object>();
    }
    PrintMemoryUsage();

    return 0;
}