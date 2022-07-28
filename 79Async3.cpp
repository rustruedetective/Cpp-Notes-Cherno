#include "temp.h"
#include <windows.h>
#include <future>

// std::async
// future

// if the threads go out of scope the program halts until the thread finishes

void fun();
static void funToAsync(int x);

int main(void){
    fun();
    logn("The main function after fun() ended")
    
    return 0;
}

void fun(){
    std::future<void> thread = std::async(std::launch::async, funToAsync, 1);
    std::future<void> thread2 = std::async(std::launch::async, funToAsync, 2);
    logn("This fun()'s scope is ending")
}

static void funToAsync(int x){
    Sleep(x*1000);
    logn("Blip " << x)
}