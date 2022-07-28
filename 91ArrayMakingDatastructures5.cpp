#include "temp.h"
#include <array>

// 1. problems with index overload
// we are only returning by value, so we cant return a string type's address
// we cant assign anything to this operator index overloaded operator

template <typename T,size_t S>
class Array{
    T m_Data[S];
public:
    constexpr int Size() const { return S; }
    T operator[](int index){
        return m_Data[index];
    }
};

int main(void){
    Array<int, 5> data;

    // now how do we index the private member of Array?
    // we need to overload the index operator
    for(int i = 0; i < data.Size(); i++){
        data[i];
    }
    // However this has problems

    return 0;
}