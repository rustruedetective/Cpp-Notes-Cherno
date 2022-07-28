#include "temp.h"

// In c++ the block scopes also have their own stack

using String = std::string;   // c++11, use -std=c++11 in gcc

class Entity{
    String name;
public:
    Entity() : name("Unknown") {}
    Entity(const String & name) : name(name) {}

    const String & getname() const { return name; }
};

int main(void){
    Entity *entity;
    {
        // This is local memory stack, it wont exit outside this block
        Entity entity2("Some Name");
        entity = &entity2;
        logn( entity->getname() )
    }   // entity2 is now destroyed
    // logn( entity->getname() )   // The pointer now points to the same memory address but that memory address has garbage
    
    return 0;
}