#include "temp.h"

// creating them on the heap

int main(void){
    int ** array2d = new int*[50];
    for(int i = 0; i < 50; i++){
        array2d[i] = new int[50];
    }

    int *** array3d = new int**[50];
    for(int i = 0; i < 50; i++){
        array3d[i] = new int*[50];
        for(int j = 0; j < 50; j++){
            array3d[i][j] = new int[50];
        }
    }

    // accessing elements
    array2d[0][0] = 0;
    array2d[0][1] = 1;
    array2d[0][2] = 2;

    array3d[0][0][0] = 0;
    array3d[0][0][1] = 1;
    array3d[0][0][2] = 2;

    return 0;
}