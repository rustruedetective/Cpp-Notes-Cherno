#include "temp.h"
#include <array>

// 1. problems with index overload
// we are only returning by value, so we cant return a string type's address
// we cant assign anything to this operator index overloaded operator

// simple solution: return ref, solves both problems

// 2. if we assign the data to a const ref
// we wont be able to read anything

// 3. we need to change the index types from int to size_t
// also for size function

// 4. we can also add an if statement so that if index outside the bounds of size has been entered or not

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
};

int main(void){
    Array<int, 5> data;

    // 1.
    for(size_t i = 0; i < data.Size(); i++){
        data[i] = 2;
    }

    // 2.
    const auto& refData = data;
    // refData[1];   // cant read

    // after overlaoding index operator with a const return type we can read
    refData[1];
    return 0;
}