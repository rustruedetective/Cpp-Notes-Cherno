#include "temp.h"
#include <thread>

// Not exactly related to threading
// But when we run a code, it consumes 100% of our cpu
// Which technically happens as the thread uses up all resources all the time

// How can we lower this?
// We use the this_thread's sleep_for function
// to add delays

bool work = true;

void do_work(){
    using namespace std::literals::chrono_literals;
    while(work){
        logn("I'm Walkin here! I'm Walkin here!");
        std::this_thread::sleep_for(1s);
    }
}

int main(void){
    // Starting
    std::thread worker(do_work);

    // halts the main thread, then turns work switch off
    std::cin.get();
    work = false;

    worker.join();
    logn("Finished.")
    return 0;
}