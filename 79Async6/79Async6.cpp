#include "header.h"

// 2 changes
// 1. why not use the preprocessor directives to enable or disable the async
// 2. using precompiled header as windows.h takes too long to compile


#define ASYNC 1

#if ASYNC
static std::mutex CountMutex;
void fun(std::vector<std::future<void>>&);
#else
void fun();
#endif

static int count = 0;
static void funToAsync(int t);

int main(void){
    std::vector<std::future<void>> threads;
    fun(threads);
    
    return 0;
}

void fun(std::vector<std::future<void>>& threads){
    for(int i = 0; i < 10; i++){
#if ASYNC
        threads.push_back(std::async(std::launch::async, funToAsync, i));
#else
        funToAsync(i);
#endif
    }
}

static void funToAsync(int x){
#if ASYNC
    std::lock_guard<std::mutex> lock(CountMutex);
#endif
    count = x;
    logn( count )
}