#include "temp.h"
#include <string>

// Usefulness of scope?

// We can write scope based classes, pointers, lock

// most basic scoped pointer: a class which is a wrapper over a pointer which on construction heap allocates the pointer
// and on destruction deletes the pointer
// aka self managed memory

class Entity{
    //Class scope
public:
    Entity(){
        logn("Hi")
    }
    ~Entity(){
        logn("Bye")
    }
};

class scopedPointer{
    Entity* ptr;
public:
    scopedPointer(Entity *ptr) : ptr(ptr){

    }
    ~scopedPointer(){
        delete ptr;
    }
};

int main(void){
    
    {
        // Now the scoped pointer is allocated on the stack
        // While the Entity is on the heap
        scopedPointer e = new Entity(); // same as:- scopedPointer e( new Entity() )
    }

    return 0;
}