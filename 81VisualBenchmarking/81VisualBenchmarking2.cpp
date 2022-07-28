#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <array>
#include <cmath>
#include "Instrumentor.h"

// with visualization
// the header file has a json making class

void fun(){
    InstrumentationTimer timer("Fun");

    for(int i = 0; i < 1000; i++)
        std::cout << "Hi there\n";
}

void fun2(){
    InstrumentationTimer timer("Fun2");

    for(int i = 0; i < 1000; i++)
        std::cout << "Hi there" << sqrt(i) << "\n";
}

int main(void){
    Instrumentor::Get().BeginSession("Profile");
    fun();
    fun2();
    Instrumentor::Get().EndSession();

    return 0;
}