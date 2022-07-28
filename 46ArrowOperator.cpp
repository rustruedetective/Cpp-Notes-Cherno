#include "temp.h"

// The arrow operator just dereferences the pointer to its original object then calls the members
// I dont know if its just syntactic sugar or has underlying implications

class Entity{
public:
    void fun(){}
};

int main(void){
    Entity e;
    e.fun();

    Entity *ptr = &e;
    // ptr.fun();   // Now you cant do this

    // One way:-
    Entity & eref = *ptr;
    eref.fun();

    // Second way:-
    (*ptr).fun();   // yes we need to dereference inside () brackets otherwise operator precedence of . is more than of * so it would try to call function with ptr.fun() and dereference afterwards *(ptr.fun())

    // Third way:-
    ptr->fun();   // this is the arrow pointer way
    return 0;
}