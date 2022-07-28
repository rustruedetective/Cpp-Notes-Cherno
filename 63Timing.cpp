#include "temp.h"
#include <chrono>   // has time capabilities
#include <thread>

// Time how long something takes

// C++11 has Chrono (platform indep.)

// Otherwise you need to call the os/platform specific library/modules
// e.g Windows has: Query performance counter in "Win32 library"

int main(void){
    // using namespace std::literals::chrono_literals;   // need c++14
    
    auto start = std::chrono::high_resolution_clock::now();

    // std::this_thread::sleep_for(5s);

    int x = 0;
    while(x < 1000000000)
        x++;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;

    logn( duration.count() )

    return 0;
}