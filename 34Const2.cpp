#include "temp.h"

// We can break constant promises using pointers

int main(void){
    const int a = 5;

    // breaking constant with pointer:-
    int * ptr = new int;
    ptr = (int*)&a;   // now the pointer points to a
    logn( *ptr )
    *ptr = 2;
    logn( *ptr )

    //stopping breaking of constant with pointer:-
    const int * ptr2 = &a;
    logn( *ptr2 )

    //tidbit
    const int * ptrX;
    int const * ptrY;
    //both ptrX and ptrY are the same, both point to a const int
    int * const ptrZ = new int;
    // this is differernt, ptrZ is a constant pointer, it will only point to one address and cannot be changed to point to anything else

    return 0;
}