#include "temp.h"

// this is very similar to how stl's array works

// this is kind of meta programming

/*
Uses:-
    You can use this is in a logging system
    one function, every type logged

    Material/Rendering system where the buffer can contain multiple types

    This is compiler writing code for us
    
Avoid:-
    Dont use templates everywhere
*/

template <typename U, int T>
class Array{
private:
    U arr[T];
};

int main(void){
    Array<int, 5> obj;
    Array<std::string, 5> obj;
    return 0;
}