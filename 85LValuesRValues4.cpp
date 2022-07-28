#include "temp.h"

void PrintName(std::string& name){
    logn( name )
}

void PrintName2(const std::string& name){
    logn( name )
}

int main(void){
    std::string firstName = "a";
    std::string lastName  = "b";

    // left side - fullName is lvalue
    // right side - is an rvalue
    // as its a temporary string literal resulting from addition of two lvalues
    std::string fullName = firstName + lastName;

    // rule 1.
    // now same logic goes here, we see that we have put in a temporary literal instead of a string reference
    // here we put an rvalue instead of lvalue, and ref can only be taken for a lvalue
    // PrintName(firstName + lastName);

    // rule 2.
    // SOLUTION: use const in the parameters
    PrintName2(firstName + lastName);

    return 0;
}