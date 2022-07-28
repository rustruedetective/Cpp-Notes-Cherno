#include "temp.h"
#include <string>

// eliminating all allocations

// now we dont want any allocation at all...so we dont use string at all lol

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
    // get rid of string... so no more heap allocation...
    const char* name = "Giby Polando";

#if 0
    std::string firstName = name.substr(0, 4);
    std::string lastName = name.substr(5, 11);
#else
    std::string_view firstName(name, 3);
    std::string_view lastName((name) + 5, 11);
#endif

    printName(name);
    printName(firstName);
    printName(lastName);
    
    logn("[Total times we allocated memory: " << s_allocCount << "]")
    return 0;
}