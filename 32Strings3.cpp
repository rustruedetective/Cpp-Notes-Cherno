#include "temp.h"
#include <string>   //we cannot print strings without this, as operator<<'s operator overloaded function is here for strings

// C++ has a templated class called basic string
// std::string is a templated version of that class, templated with char
// template specialization of basic string class with char
// its a const char array

// It also has a constructor we can pass array of chars into:-  std::string str("input char array")

// wide string : wstring - 2 byte chars

int main(void){
    std::wstring wstr;
        
    // std::string str = "Hi" + " There";   //this is not allowed as "Hi" and " There" are actually char arrays and not strings
    std::string str = "Hi";
    str = str + " There";   //Now possible as string overloaded operator+ with char arrays
    //or
    str = std::string("Hi") + " There";   //we called string constructor on "Hi"
    return 0;
}