#include "temp.h"
#include <string>

static uint32_t s_allocCount = 0;

void * operator new(size_t size){
    s_allocCount++;
    logn ("[Memory allocated at size: " << size << " bytes]")
    return malloc(size);
}

void printName(std::string_view name){
    logn(name)
}

int main(void){
    // std::string_view also does not allow the allocations to happen even with function calls
    printName("Tron Jon");   // no more allocation
    
    logn("[Total times we allocated memory: " << s_allocCount << "]")
    return 0;
}