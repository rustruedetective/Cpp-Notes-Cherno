#include "temp.h"

void PrintName(std::string& name){
    logn( "lvalue " << name )
}

// no worry here about chaning value or memory management
void PrintName(std::string&& name){
    name = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabc";
    logn( "rvalue " << name )
}

int main(void){
    std::string firstName = "a";
    std::string lastName  = "b";
    std::string fullName = firstName + lastName;

    PrintName(fullName);
    PrintName(firstName + lastName);

    return 0;
}