#include "temp.h"

// c++11 needed

// We can change the return data type of this function without having to change below code
std::string getSomeData(){   // e.g char* instead of std::string
    return "This is a string";
}

// Bad Use case:
// 1. when return data type is not very clear to you (DONT THOUGH)

// Pros:-
// 1. You can keep your code same even if return data types of api's change

// Cons:-
// 1. Your code might break as the new data type returned from api might not be have same member functions you used

int main(void){
    // 1. we know the data type here so we should use data type
    char a = 'a';
    // however if return type is obstuse you may use auto
    auto b = getSomeData();
    b.size();   // this function only works with string and not char*

    return 0;
}