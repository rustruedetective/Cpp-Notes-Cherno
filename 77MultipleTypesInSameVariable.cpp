#include "temp.h"
#include <variant>

// c++17
// a new class in it

// std::variant

// you want to store data in a variable
// but you dont know the type of the variable
// so you make a variant and give it a all the possible types it can be
// and select what the actual type is later

int main(void){

    std::variant<std::string, int> data;   // so data variable can be a string or an int we dont know for sure yet
    
    data = "abc";
    logn(std::get<std::string>(data))
    data = 2;
    logn(std::get<int>(data))

    // data = false;   // dont assign type that was not told of before

    return 0;
}