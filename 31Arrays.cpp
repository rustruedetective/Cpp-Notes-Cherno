#include "temp.h"

// Memory access violation error: occurs when we try access unpriviledged memory, e.g indices of array outside its length
// This error comes in debug mode and not production mode
// So in production mode array[-1] would end up writing to some other space inside your program, e.g some other variable

// Arrays go good with for loops
// < lengthofarray is better than <= lengthofarray-1 because <= does two comparisons and < only does one

// Array is just a pointer
// Its a pointer to a length of memory of size = sizeoftype*lengthofarray

int main(void){
    int array[5];
    int *ptr = array;

    // now pointer arithmetic is fine for normal
    array[3] = 1;
    logn(array[3]);
    *(ptr + 3) = 2;   // here 3 means 3*4 = 12 bytes moved, where 4 is size of integer
    logn(array[3]);
    // but if our pointer's type is different we actually have to put how many bytes that moves
    *((char*)ptr + 12) = 3;   //here we need to put this at 12th memory byte, as char only moves 1 byte => 1*12 = 12 bytes
    logn(array[3]);


    // This is how array on heap is allocated
    // We use dynamic memory arrays for lifetime
    // They live until their memory is on purpose deleted
    int * arrayOnHeap = new int[5];
    delete[] arrayOnHeap;
    
    return 0;
}