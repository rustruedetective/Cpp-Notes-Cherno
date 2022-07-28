#include "temp.h"
#include <windows.h>
#include <future>
#include <vector>

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
    count = x;
    logn( count )
}