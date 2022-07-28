#include "temp.h"
#include <chrono>   // has time capabilities
#include <functional>

std::chrono::duration<float> measurePerformance(const std::function<void(void)>& func){
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;   // is this heap allocated? lol
    return duration;
}

int main(void){

    logn( measurePerformance( 
        [](){
        int x = 0;
        while(x < 1000000000)
            x++;
        }
    ).count() )

    return 0;
}