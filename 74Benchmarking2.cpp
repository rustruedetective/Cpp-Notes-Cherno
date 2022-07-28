#include "temp.h"
#include <memory>
#include <chrono>
#include <array>

// Performance of shared pointer vs unique pointer

// gcc in release mode: -O2 -s -DNDEBUG

class Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
public:
    Timer(){
        m_startTimePoint = std::chrono::high_resolution_clock::now();
    }
    Timer(std::string paragraph){
        std::cout << paragraph << ":-\n";
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
    struct Vector2{
        float x, y;
    };
    
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer("Shared Pointer (make_shared)");
        for(int i = 0; i < sharedPtrs.size(); i++){
            sharedPtrs[i] = std::make_shared<Vector2>();
        }
    }

    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer("Shared Pointer (new)");
        for(int i = 0; i < sharedPtrs.size(); i++){
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }

    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer timer("Unique Pointer (make_shared)");
        for(int i = 0; i < uniquePtrs.size(); i++){
            uniquePtrs[i] = std::make_unique<Vector2>();
        }
    }

    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer timer("Unique Pointer (new)");
        for(int i = 0; i < uniquePtrs.size(); i++){
            uniquePtrs[i] = std::unique_ptr<Vector2>(new Vector2());
        }
    }

    return 0;
}