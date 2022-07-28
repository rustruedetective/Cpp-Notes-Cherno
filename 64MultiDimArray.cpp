#include "temp.h"

// 2d array of arrays
// 3d array of arrays of arrays

// Just view ints as memory, nothing more

int main(void){
    // 1d
    int * array = new int[50];   // an array (int) of 200 bytes allocated to the pointer
    // 2d
    int ** array2d = new int*[50];   // an array (of pointers to int) of 50 bytes allocated to the pointer

    array[0];   // this is an integer
    array2d[0];   // this is an integer pointer
    // array2d[0][0];   // this is an integer but we never assigned it any ints

    return 0;
}