#include "temp.h"
#include <array>
#include <cstring>

// 1. we can also return data member

// 2. with 1. we can set the data member's value completely to 0
// without having to loop/iterate over the whole elements

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
    // this wont work as we dont have a constructor for this
    // Array<int, 5> data = {1, 2, 3, 4, 5};
    Array<int, 5> data;
    data[0] = 10;
    data[1] = 20;
    data[2] = 30;
    data[3] = 40;
    data[4] = 50;

    for(int i = 0; i < data.Size(); i++)
        logn( data[i] )

    // 2.
    memset(data.Data(), 0, data.Size() * sizeof(int));
    // or
    memset(&data[0], 0, data.Size() * sizeof(int));

    for(int i = 0; i < data.Size(); i++)
        logn( data[i] )

    return 0;
}