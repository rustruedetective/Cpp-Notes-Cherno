#include "temp.h"
#include <string>

static uint32_t s_allocCount = 0;

// we overlaod the new operator...
// so we can see its call in our debugger...huwi huwi huwi...naughty cherno
void * operator new(size_t size){
    s_allocCount++;
    logn ("[Memory allocated at size: " << size << " bytes]")
    return malloc(size);
}

void printName(const std::string& name){
    logn(name)
}

int main(void){
    std::string name = "Giby Polando";   // ofc this allocated memory
    printName(name);
    printName("Poko Sama");   // even this allocates memory
    
    logn("[Total times we allocated memory: " << s_allocCount << "]")
    return 0;
}