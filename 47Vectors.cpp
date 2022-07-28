#include "temp.h"

// Stored on the heap, and then copied to stack or not?

// The stl is full of containers of various types
// And its called template lib as you can template stuff into anything

// You provide the data type the data structures/containers handle

// std::vector is actually a dynamic array and not a mathematical vector, it has nothing do with actuall vectors
// std::array is actually a mathematical vector

// std::vector does not have a fixed size, you dont even need to specify its size, you just put stuff in it and it resizes itself
// you can initialize it with a specific size though

// The usual structures in stl are not fast, we can make our own faster and efficient structures
// The stl ones didnt prioritize speed

// The std::vector makes an array and when the size changes it makes a new array of that size and copies all elements and deletes the old one

int main(void){

    return 0;
}