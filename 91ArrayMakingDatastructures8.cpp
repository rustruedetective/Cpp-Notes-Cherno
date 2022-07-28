#include "temp.h"
#include <array>
#include <cstring>

// we still dont have iterators

template <typename T,size_t S>
class Array{
    T m_Data[S];
public:
    constexpr size_t Size() const { return S; }
    T& operator[](size_t index){   // 3.
        if(!(index < S)){   // 4.
            // __debugbreak();   // msvc
            raise(SIGABRT);   // gcc
        }
        return m_Data[index];
    }
    const T& operator[](size_t index) const {   // 3.
        if(!(index < S)){   // 4.
            // __debugbreak();   // msvc
            raise(SIGABRT);   // gcc
        }
        return m_Data[index];
    }
    // 1.
    T* Data(){
        return m_Data;
    }
    const T* Data() const {
        return m_Data;
    }
};

int main(void){
    // look how this even works with strings
    Array<std::string, 5> data;
    data[0] = "abc";
    data[1] = "xyz";


    for(int i = 0; i < data.Size(); i++)
        logn( data[i] )
    
    // New Challenge: this causes segmentation faults...lol
    // memset(data.Data(), 0, data.Size() * sizeof(int));


    return 0;
}