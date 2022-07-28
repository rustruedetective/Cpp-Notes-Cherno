#include "temp.h"
#include <thread>

// Not exactly related to threading
// But when we run a code, it consumes 100% of our cpu
// Which technically happens as the thread uses up all resources all the time

// How can we lower this?
// We use the this_thread's sleep_for function
// to add delays

// need c++14

int main(void){
    using namespace std::literals::chrono_literals;
    while(1){
        logn("I'm Walkin here! I'm Walkin here!");
        std::this_thread::sleep_for(1s);
    }
}