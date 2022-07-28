#include "temp.h"
#include <string>

// reducing allocations

// first look at the problem
// we need the characters...
// we need to view the original string's characters

// std::string_view is a new class that is a pointer to an existing memory/string with a size
// so you just look at memory instead of copying/allocating it
// and the pointer+size is passed around instead of the whole string

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
    std::string name = "Giby Polando";

    // viewing with string view:-
#if 0
    std::string firstName = name.substr(0, 4);
    std::string lastName = name.substr(5, 11);
#else
    std::string_view firstName(name.c_str(), 3);
    std::string_view lastName((name).c_str() + 5, 11);
#endif

    printName(name);
    printName(firstName);
    printName(lastName);
    
    logn("[Total times we allocated memory: " << s_allocCount << "]")
    return 0;
}