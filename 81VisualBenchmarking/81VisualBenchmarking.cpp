#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <array>
#include <cmath>

// no visualization
// we need to find our benchmark logs in this mess

class Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
    std::string name;
    bool stopped;
public:
    Timer(std::string nameIN) : name(nameIN), stopped(false){
        m_startTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        if(!stopped)
            Stop();
    }
    void Stop(){
        auto m_endingTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_startTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(m_endingTimePoint).time_since_epoch().count();

        std::cout << name << ": " << (end - start) << " ms\n";
        stopped = true;
    }
};

void fun(){
    Timer timer("Fun");

    for(int i = 0; i < 1000; i++)
        std::cout << "Hi there\n";
}

void fun2(){
    Timer timer("Fun2");

    for(int i = 0; i < 1000; i++)
        std::cout << "Hi there" << sqrt(i) << "\n";
}

int main(void){
    fun();
    fun2();

    return 0;
}