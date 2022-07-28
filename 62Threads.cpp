#include "temp.h"
#include <thread>

void do_work(){

}

int main(void){
    // Starting
    std::thread worker(do_work);   // the thread object needs a function pointer, this is the funtion it would execute

    // Halting main thread to join subthread to Process
    worker.join();

    return 0;
}