#include "temp.h"
#include <windows.h>
#include <future>
#include <vector>

// std::async
// future

// previous example no.2 didnt work bcz we need to put the threads into an seperate variables
// in previous example we initialized a new variable each time with a new thread

// i think its because the threads themselves need a place to live
// and std::future is the variable that handles this...
// if the threads go out of scope the program halts until the thread finishes

// So here is a way around it!
// just use a global array to store them*
// or pass your own ref of array to store them

std::vector<std::future<void>> threads;
void fun();
static void funToAsync(int t);

int main(void){
    fun();
    
    return 0;
}

void fun(){
    for(int i = 0; i < 10; i++){
        threads.push_back(std::async(std::launch::async, funToAsync, 1000));   // first parameter is job type
        logn("Dip")
    }
}

static void funToAsync(int t){
    Sleep(t);
    logn("Blip ")
}