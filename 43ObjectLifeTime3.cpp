#include "temp.h"
#include <string>

int* createArray(){
    // This does not work
    // As the array is allocated on the stack
    // When we return the array's address it points to nothingness
    // The memory was destroyed when function scope ended
    int array[50];
    return array;
}

// Workarounds
// 1. Heap allocation
int* createArray2(){
    int* array = new int[50];
    return array;
}
// 2. Pass your own memory here
int* createArray3(int* array){
    // do something to our array
    return array;
}

int main(void){
    

    return 0;
}