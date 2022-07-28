#include "temp.h"

// deleting them from the heap

// need to delete all pointers that were allocated

// A simpler method is like a stack last to get allocated needs to be deleted first

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

    /*-----------------*/

    for(int i = 0; i < 50; i++){
        delete[] array2d[i];
    }
    delete array2d;

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            delete[] array3d[i][j];
        }
        delete[] array3d[i];
    }
    delete array3d;

    return 0;
}