#include "temp.h"

// Methods to optimize:-
// 1. store your nxn 2d array in n*n 1d array

int main(void){
    int ** array2d = new int*[5];
    for(int i = 0; i < 5; i++){
        array2d[i] = new int[5];
    }
    for(int i = 0; i < 5; i++){
        delete[] array2d[i];
    }
    delete array2d;

    // 1. convert above into
    int* array2d_2 = new int[5 * 5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            array2d_2[i*5 + j] = 0;

    delete array2d_2;

    return 0;
}