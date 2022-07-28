#include "temp.h"

// We use heap allocation to keep our objects alive

// Allocation on heap consumes a little performance
// Allocation on heap takes longer, and it needs to be manually de allocated

// With Smart Pointers we can allocate on the heap giving us size advantage, without having to worry about deleting it later

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
        // the new keyword allocates memory on the heap, then the constructor of class is called, then new returns the pointer to this memory
        Entity* entity2 = new Entity("Some Name");
        entity = entity2;
        logn( "Inside: " << entity->getname() )
    }
    logn( "Outside: " << entity->getname() )

    delete entity;
    return 0;
}