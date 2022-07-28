#include "temp.h"

// c++11 needed

// Suppose Api changes return type std::string to const char *
const char* getSomeData(){
    return "This is a string";
}

int main(void){
    auto b = getSomeData();
    // b.size();   // this code breaks as it only works for std::string type

    return 0;
}