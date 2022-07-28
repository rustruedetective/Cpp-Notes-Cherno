#include <iostream>
#include "abc.cpp"

// here we dont need to => g++ mainn.cpp abc.cpp, only => g++ mainn.cpp

int main(void){
    std::cout << fun(3, 4) << "\n";
    return 0;
}