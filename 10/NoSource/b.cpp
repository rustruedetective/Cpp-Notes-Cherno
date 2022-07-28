#include <iostream>
#include "head.h"

//function defined here
int fun(int x, int y){
    return x + y;
}

int main(void){
    std::cout << fun(1, 2) << "\n";
    return 0;
}