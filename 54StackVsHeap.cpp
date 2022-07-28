#include "temp.h"

struct Vector3{
    float x, y, z;
    Vector3(int xi, int yi, int zi) : x(xi), y(yi), z(zi) {}
};

int main(void){
    // allocated memory on stack
    int value = 5;
    int valueArr[5] = {1,2,3,4,5};
    Vector3 vec(1,2,3);

    // allocated memory on heap
    int * h_value = new int;
    *h_value = 5;
    int * h_valueArr = new int[5] {1,2,3,4,5};   // c++11 syntax
    Vector3 * h_vec = new Vector3(1,2,3);



    // Stack allocation addresses
    // Its in a continuous memory lane
    logn( &value )   // at bottom of stack memory
    logn("------------")
    logn( &valueArr[0] )   // in middle of stack memory
    logn( &valueArr[1] )
    logn( &valueArr[2] )
    logn( &valueArr[3] )
    logn( &valueArr[4] )
    logn("------------")
    logn( &vec.x )   // at top of stack memory
    logn( &vec.y )
    logn( &vec.z )



    // Heap allocation addresses
    // It just scatters wherever it can find space to fit them
    logn( &h_value )   // This is...somewhere
    logn("------------")
    logn( &h_valueArr[0] )   // Not even near first
    logn( &h_valueArr[1] )
    logn( &h_valueArr[2] )
    logn( &h_valueArr[3] )
    logn( &h_valueArr[4] )
    logn("------------")
    logn( &h_vec->x )   // Somewhere else
    logn( &h_vec->y )
    logn( &h_vec->z )

    delete h_value;
    delete[] h_valueArr;
    delete h_vec;

    return 0;
}