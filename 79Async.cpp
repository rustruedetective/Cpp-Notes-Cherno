#include "temp.h"
#include <windows.h>

// std::async
// future

void fun();

int main(void){
    fun();
    
    return 0;
}

void fun(){
    for(int i = 0; i < 10; i++){
        Sleep(1000);
        logn("Blip")
    }
}