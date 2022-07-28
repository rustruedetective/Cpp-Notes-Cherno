#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <array>
#include <cmath>
#include "Instrumentor.h"

// doing shinanigans again: nested functions
// dont put spaces in the intrumentation timer's constructors

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

void testing(){
    InstrumentationTimer timer("TestingFunc");

    fun();
    fun2();
}

int main(void){
    Instrumentor::Get().BeginSession("Profile");
    testing();
    Instrumentor::Get().EndSession();

    return 0;
}