#include "temp.h"

// testing

// but in debug mode there is no SSO
// we need to put it in production mode
// ...lol even this didnt work in gcc

void * operator new(size_t size){
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

int main(void){
    std::string name = "goody";

    return 0;
}