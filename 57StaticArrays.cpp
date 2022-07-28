#include "temp.h"
#include <array>

// stl static arrays
// they dont grow/change their size like std::vector arrays

// its very identical to previous normal c array

// advantages:-
// 1. size function keeps track of size
// 2. it supports an iterator so alot of stl algorithms compatible with it
// 3. stored in stack*
// 4. has optional bound checking if certain macros/debugging enabled

// disadvnatages:-
// 1. we need to input size of array, but we can use templates to get around that

// The size argument we provided is not stored anywhere seperately in memory, instead it is a template so doesnt occupy any memory

template <size_t T>   // int wont work
void print(const std::array<int , T>& data){
    for(auto i : data)
        log( i << " " )
    logn("")
}


int main(void){
    std::array<int, 5> arr = {1,2,3,4,5};
    arr[0] = 0;
    arr[4] = 4;
    print<5>(arr);

    return 0;
}