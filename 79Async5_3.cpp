#include "temp.h"
#include <windows.h>
#include <future>
#include <vector>

// No mutex is not ur data type which is locked...its a lock that locks all code below it in scope

static std::mutex CountMutex;
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
        threads.push_back(std::async(std::launch::async, funToAsync, i));
    }
}

static void funToAsync(int x){
    std::lock_guard<std::mutex> lock(CountMutex);
    // the CountMutex locks all code below... it is not the data type itself
    // CountMutex = x;
    // logn( CountMutex )

    //this will be locked
    count = x;
    logn( count )
}