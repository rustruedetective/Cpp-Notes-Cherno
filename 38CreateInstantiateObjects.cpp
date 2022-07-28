#include "temp.h"

// When we write an object it needs to occupy some space where is this memory?

// empty classes occupy 1 byte

// Stack objects have automatic lifespan
// When they go out of scope they are destroyed

// Heap objects once created are there until we free them
// Do they get freed if program is terminated?

using String = std::string;   // c++11, use -std=c++11 in gcc

class Entity{
    String name;
public:
    Entity() : name("Unknown") {}
    Entity(const String & name) : name(name) {}

    const String & getname() const { return name; }
};

//these variables and objects limited to this this function's stack and life
void function(){
    int a = 2;
    Entity entity = Entity("Some Name");
}

int main(void){
    // First way:-
    Entity entity;   //called first constructor
    logn( entity.getname() )

    Entity entity2("abc");   //called second constructor
    logn( entity2.getname() )

    // The second way:-
    Entity entity3 = Entity("xyz");
    logn( entity3.getname() )
    
    return 0;
}