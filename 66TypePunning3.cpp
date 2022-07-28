#include "temp.h"

// Practical example

// Now struct's memory just hold its members in a continuous memory block
// So what we can do is access this memory block as an array or mabe simple int values etc

// Procedure:-
// 1. get that type as a pointer
// (get memory address with &)
// 2. cast it to a different type's pointer
// Cast it via type*, yeah pointer cast it

struct Entity{
    int x, y;
};

int main(void){
    Entity e = {5, 8};

    // struct member given to variable the boring copy way
    int x = e.x;

    // struct member given to variable the memory way, but useless
    int y = *(int*)&e.y;
    logn( x << " " << y )

    // struct member given to variable the memory way in the awesome way
    // this is the useful way
    int y2 = *(int*)((char*)&e+4);
    logn( x << " " << y2 )

    // struct as array the fancy memory way
    int* arr = (int*)(&e);
    logn( arr[0] << " " << arr[1] )

    return 0;
}