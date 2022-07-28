#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <array>
#include <cmath>
#include "Instrumentor.h"

// adding thread
// so the functions start at the same time in the chrome tracing charts

#if true
#define TIMER_OBJ(x) InstrumentationTimer timer(x);
#else
#define TIMER_OBJ(x) 0;
#endif

void fun(){
    TIMER_OBJ("Fun");

    for(int i = 0; i < 1000; i++)
        std::cout << "Hi there\n";
}

void fun2(){
    TIMER_OBJ("Fun2");

    for(int i = 0; i < 1000; i++)
        std::cout << "Hi there" << sqrt(i) << "\n";
}

void testing(){
    TIMER_OBJ("TestingFunc");

    // different methods for threading
    // 1.
    // std::thread threadA(std::bind(fun));
    // std::thread threadB(std::bind(fun2));
    // threadA.join();
    // threadB.join();

    // 2.
    std::thread threadA([](){fun();});
    std::thread threadB([](){fun2();});
    threadA.join();
    threadB.join();
}

int main(void){
    Instrumentor::Get().BeginSession("Profile");
    testing();
    Instrumentor::Get().EndSession();

    return 0;
}