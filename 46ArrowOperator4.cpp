#include "temp.h"

// We can use struct to keep track of member offset

// I dont know why my compiler wont run this
// Something about loosing precision when converting from float* to int

struct Vector3
{
    float x, y, z;
    //off:0, 1, 2;
    // offset of x is 0 bytes away
    // offset of y is 1*sizeof(float) bytes away
    // offset of z is 2*sizeof(float) bytes away

    // but later we may loose track of their offsets, so to keep them in mind:-
};

int main(void){
    ((Vector3*)0);   // cast zero to vector3 type, so we have address at 0
    ((Vector3*)0)->x;   // now we have value of x
    &( ((Vector3*)0)->x );   // now we have address of x
    // (int)&( ((Vector3*)0)->x );   // now we have offset in integer form in units of bytes

    // int offset = (int)&((Vector3*)0)->x;

    return 0;
}