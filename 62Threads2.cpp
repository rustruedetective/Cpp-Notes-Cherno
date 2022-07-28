#include "temp.h"
#include <thread>

// Stopping one process using another

bool work = true;

void do_work(){
    // halts the sub thread, as long as work switch is on
    while(work){
        logn("I'm Walkin here! I'm Walkin here!");
    }
}

int main(void){
    // Starting
    std::thread worker(do_work);

    // halts the main thread, then turns work switch off
    std::cin.get();
    work = false;

    worker.join();
    return 0;
}