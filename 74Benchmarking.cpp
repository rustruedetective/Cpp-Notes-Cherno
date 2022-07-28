#include "temp.h"
#include <memory>
#include <chrono>

class Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
public:
    Timer(){
        m_startTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        Stop();
    }
    void Stop(){
        auto m_endingTimePoint = std::chrono::high_resolution_clock::now();
        //or
        // std::chrono::time_point<std::chrono::high_resolution_clock> m_endingTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_endingTimePoint).time_since_epoch().count();

        auto duration = end - start;   // microseconds

        double ms_duration = duration * 0.001;   // milliseconds

        logn(duration << " us")
        logn(ms_duration << " ms")
    }
};

int main(void){
    int value = 0;
    {
        Timer timer;
        // code to measure performance:-
        for(int i = 0; i < 1000000; i++)
            value +=2;
    }
    
    return 0;
}