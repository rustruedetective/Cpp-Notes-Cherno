#include "temp.h"
#include <any>

// c++17

// std::any

int main(void){
    // Declare/Init
    // std::any data = std::make_any();
    std::any data;

    // Assign
    data = 2;
    data = "abc";   // const char*
    data = std::string("abc2");   // string obj

    // Retrieve (you need to know the data type it currently is)
    logn( std::any_cast<std::string>(data) )

    return 0;
}