#include "temp.h"
#include <string>

// now add in string manip

// conclusion: it allocated memory on each string manip
// if we do this for every frame of our game...its going to hurt it

static uint32_t s_allocCount = 0;

void * operator new(size_t size){
    s_allocCount++;
    logn ("[Memory allocated at size: " << size << " bytes]")
    return malloc(size);
}

void printName(const std::string& name){
    logn(name)
}

int main(void){
    std::string name = "Giby Polando";

    // now add in string manip:-
    std::string firstName = name.substr(0, 4);
    std::string lastName = name.substr(5, 11);
    
    printName(name);
    printName(firstName);
    printName(lastName);
    
    logn("[Total times we allocated memory: " << s_allocCount << "]")
    return 0;
}