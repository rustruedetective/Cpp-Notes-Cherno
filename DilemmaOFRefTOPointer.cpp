#include "temp.h"

// Proof that no matter how we assign a ref its address, it will always be alias of same variable address

class Entity{
    int x;
public:
    Entity() : x(0) {}
    Entity(int xIn) : x(xIn) {}
    void print(){
        logn( x )
    }
};

int main(void){
    Entity e = 1;
    Entity e2 = 2;
    e.print();
    e2.print();
    logn("")

    // I try to set alias/ref via pointer and then change pointer
    // But the ref still stuck to original address
    Entity *ptr = &e;
    Entity & eref = *ptr;
    eref.print();

    ptr = &e2;
    eref.print();

    return 0;
}