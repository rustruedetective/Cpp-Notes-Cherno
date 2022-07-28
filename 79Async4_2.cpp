#include "temp.h"
#include <windows.h>
#include <future>
#include <vector>

// std::async
// future

// So here is a way around it!
// just use a global array to store them,
// or pass your own ref of array to store them*

void fun(std::vector<std::future<void>>&);
static void funToAsync(int t);

int main(void){
    std::vector<std::future<void>> threads;
    fun(threads);
    
    return 0;
}

void fun(std::vector<std::future<void>>& threads){
    for(int i = 0; i < 10; i++){
        threads.push_back(std::async(std::launch::async, funToAsync, 1000));   // first parameter is job type
        logn("Dip")
    }
}

static void funToAsync(int t){
    Sleep(t);
    logn("Blip ")
}