#include "temp.h"

void PrintName(std::string& name){
    logn( name )
}

// here we have a function that only accepts rvalues
void PrintName2(std::string&& name){
    logn( name )
}

int main(void){
    std::string firstName = "a";
    std::string lastName  = "b";
    std::string fullName = firstName + lastName;

    PrintName(fullName);
    PrintName2(firstName + lastName);

    // PrintName2(fullName);   // only rvlaues allowed

    return 0;
}