#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <array>
#include <cmath>
#include "Instrumentor.h"

// real shinanigans: putting timer object in macro to turn it on or off at will

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

    fun();
    fun2();
}

int main(void){
    Instrumentor::Get().BeginSession("Profile");
    testing();
    Instrumentor::Get().EndSession();

    return 0;
}