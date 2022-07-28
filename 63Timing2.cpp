#include "temp.h"
#include <chrono>   // has time capabilities
#include <thread>

// For some reason alot of stuff doesnt work
// This might be because alot of stuff is compiler dependant

// This is more useful than a performance function taking in a function pointer
// Here we just create an object at start of program and when it ends... booom we automatically log the duration...as obj goes out of scope and deconstructor is called...funny things this scope
struct Timer{
    // std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000;
        logn( "Took: " << ms << " ms.")
    }
};

void fun(){
    Timer countObj;
    int x = 0;
    while(x < 1000000000)
        x++;
}

int main(void){
    fun();

    return 0;
}