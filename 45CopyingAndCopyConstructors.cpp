#include "temp.h"

// Copying can be a bad thing as it affects performance

struct Vector2{
    float x, y;
};

int main(void){
    // copy by value
    int a = 2;   // created new one memory address and assigned value
    int b = a;   // created new memory address and copied value in it
    b = 3;   // memory of a is unaffected

    // copy by value also works on classes/structs
    Vector2 av = { 2, 3};
    Vector2 bv = av;
    bv.x = 3;   // av is unaffected
    bv.y = 4;

    // copy by value copies the pointer's address
    Vector2 * avp = new Vector2();
    Vector2 * bvp = avp;
    bvp++;   // this changes the bvp pointer's address itself nothing to do with avp
    bvp--;
    bvp->x = 2;   // this changes the avp's memory (its member)

    // So
    // = sign/operator always copies the exact data type, e.g address for pointers and value for primitive data types
    // Now except for references, where = sign automatically dereferences them as well and copies their value instead of address

    return 0;
}