#include "temp.h"
#include <thread>

// need c++14

// Logging threads via their ids

bool work = true;

void do_work(){
    logn( "Started New Thread: " << std::this_thread::get_id() )
    using namespace std::literals::chrono_literals;
    while(work){
        logn("I'm Walkin here! I'm Walkin here!");
        std::this_thread::sleep_for(1s);

    }
}

int main(void){
    logn( "Started Thread: " << std::this_thread::get_id() )

    std::thread worker(do_work);

    std::cin.get();
    work = false;
    logn( "Gone Back to Thread: " << std::this_thread::get_id() )

    worker.join();
    return 0;
}