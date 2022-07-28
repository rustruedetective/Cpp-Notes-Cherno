#include "temp.h"
#include <stdlib.h>

// The new keyword is actually an operator, if you go to its declaration/definition u will see
// So you can actaully overload it in a class

// The new keyword returns a 'void pointer'*

using String = std::string;

class Entity{
    String name;
public:
    Entity() : name("Unkown") {}
    Entity(const String & n) : name(n) {}

    const String & getname() const { return name; }
};

int main(void){
    Entity * ptr = new Entity();   // this will also call the constructor
    // the above is equivalent to this line below
    Entity * ptr2 = (Entity*)malloc(sizeof(Entity));   // this will purely give us memory and not call the constructor

    delete ptr;
    free(ptr2);

    return 0;
}