#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <array>
#include <cmath>
#include "Instrumentor.h"

// why not add the namespace shinanigan to differentiate our benchmarking functions

#if true
#define TIMER_OBJ InstrumentationTimer timer(__FUNCSIG__);   // only in windows compilers i think
#else
#define TIMER_OBJ 0;
#endif

namespace benchmark{
    void fun(){
        TIMER_OBJ;

        for(int i = 0; i < 1000; i++)
            std::cout << "Hi there\n";
    }

    void fun2(){
        TIMER_OBJ;

        for(int i = 0; i < 1000; i++)
            std::cout << "Hi there" << sqrt(i) << "\n";
    }

    void testing(){
        TIMER_OBJ;

        fun();
        fun2();
    }
}

int main(void){
    Instrumentor::Get().BeginSession("Profile");
    benchmark::testing();
    Instrumentor::Get().EndSession();

    return 0;
}