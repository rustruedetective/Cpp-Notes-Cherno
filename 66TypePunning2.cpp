#include "temp.h"

int main(void){
    // This is TYPE PUNNING

    int a = 10;
    double* b = (double*)&a;   // giving the other type the exact memory's address
    logn(a << " " << *b)

    // alternate
    int a = 10;
    double& b2 = *(double*)&a;   // giving the other type the exact memory's address
    logn(a << " " << b2)



/*
    This below code is a horrible mistake
    We have given a 4 byte integer's memory to an 8 byte double
    So the double will look 4 bytes past the 4 bytes of integer...oops
    now if we change this memory which is not ours...system could crash
*/

    // alternate
    // double c = *(double*)&a;   // this is very bad, as it would copy 4 byte memory into 8 byte memory of which 4 byte is not even ours
    // logn(a << " " << c)

    return 0;
}