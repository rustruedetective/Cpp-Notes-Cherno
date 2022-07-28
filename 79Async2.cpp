#include "temp.h"
#include <windows.h>
#include <future>

// std::async
// future

// the thread needs to be returned to some variable as "auto thread = std::async..."
// otherwise we get a warning:-
// warning: ignoring return value of ‘std::future<typename std::__invoke_result<typename std::decay<_Tp>::type, typename std::decay<_Args>::type ...>::type> std::async(std::launch, _Fn&&, _Args&& ...) [with _Fn = void (&)(int); _Args = {int}; typename std::__invoke_result<typename std::decay<_Tp>::type, typename std::decay<_Args>::type ...>::type = void; typename std::decay<_Tp>::type = void (*)(int)]’, declared with attribute ‘nodiscard’ [-Wunused-result]

// this did not work
// its because when we assigned the thread to a variable "auto thread = std::async..."
// the variable also went out of scope
// we need the variable alive until the thread completes
// or else the program will halt until the thread finishes

void fun();
static void funToAsync(int t, int i);

int main(void){
    fun();
    
    return 0;
}

void fun(){
    for(int i = 0; i < 10; i++){
        auto thread = std::async(std::launch::async, funToAsync, 1000, i);   // first parameter is job type
        logn("Dip")
    }
}

static void funToAsync(int t, int i){
    Sleep(t);
    logn("Blip " << i)
}