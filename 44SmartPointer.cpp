#include "temp.h"
#include <memory>

// Smart pointer are a way to automate allocation and deallocation of memory on the heap
// e.g when we call new we dont have to call delete, or maybe we dont even need to call new
// It is a wrapper around a normal pointer

// 1. Unique pointer: they cannot be copied because we dont want two unique pointers pointing to same memory
// if that memory is deleted by one pointer the other is still pointing to it...

// Unique pointer makes the dynamic pointer into a stack allocated pointer!

// Remeber these pointers are allocated on the stack so are affected by scope!

class Entity{
public:
    Entity(){
        logn("Made Entity")
    }
    ~Entity(){
        logn("Destroyed Entity")
    }

    void fun(){}
};

int main(void){
    {
        // Syntax 1
        std::unique_ptr<Entity> entityUniquePtr(new Entity());   // it is now allocated on stack instead of heap

        // Syntax 2: this is for exception safety
        // std::unique_ptr<Entity> entityUniquePtr2 = std::make_unique<Entity>();
        // its not working as make_unique seems to be undefined here

        entityUniquePtr->fun();
        // entityUniquePtr2->fun();


        // Now you cant copy it
        // std::unique_ptr<Entity> entityUniquePtr3 = entityUniquePtr;   // cant copy
    }
    return 0;
}