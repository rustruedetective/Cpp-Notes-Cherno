#include "temp.h"
#include <string>

// just sugarifying the code in this file

#define STRING_VIEW true

static uint32_t s_allocCount = 0;

void * operator new(size_t size){
    s_allocCount++;
    logn ("[Memory allocated at size: " << size << " bytes]")
    return malloc(size);
}

#if STRING_VIEW
void printName(std::string_view name){
    logn(name)
}
#else
void printName(const std::string& name){
    logn(name)
}
#endif

int main(void){
    std::string name = "Giby Polando";

#if STRING_VIEW
    std::string_view firstName(name.c_str(), 3);
    std::string_view lastName((name).c_str() + 5, 11);
#else
    std::string firstName = name.substr(0, 4);
    std::string lastName = name.substr(5, 11);
#endif

    printName(name);
    printName(firstName);
    printName(lastName);
    
    logn("[Total times we allocated memory: " << s_allocCount << "]")
    return 0;
}