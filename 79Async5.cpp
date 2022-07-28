#include "temp.h"
#include <windows.h>
#include <future>
#include <vector>

// std::async
// future

// Now for actual problems...
// The scoping out of resources in main function and the locking of shared resources

// the resource count needs to be protected from multiple access...so we need to lock it
static int count = 0;
void fun(std::vector<std::future<void>>&);
static void funToAsync(int t);

int main(void){
    std::vector<std::future<void>> threads;
    fun(threads);
    
    return 0;
}

void fun(std::vector<std::future<void>>& threads){
    for(int i = 0; i < 10; i++){
        threads.push_back(std::async(std::launch::async, funToAsync, i));   // first parameter is job type
    }
}

static void funToAsync(int x){
    // std::lock_guard<std::mutex> lock(count);   // as soon as this function exits the lock is unlocked as the lock's deconstructor is called when lock dies due to going out of scope
    count = x;
    logn( count )
}