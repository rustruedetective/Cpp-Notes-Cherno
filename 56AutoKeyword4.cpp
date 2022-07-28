#include "temp.h"
#include <vector>

// c++11 needed

// Good use case:
// 1. instead of using a massive type use auto

int main(void){
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    // 1. autoing massive types
    // whao
    for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++){
        logn( *it )
    }

    // auto it up
    for(auto it = strings.begin(); it != strings.end(); it++){
        logn( *it )
    }
    return 0;
}