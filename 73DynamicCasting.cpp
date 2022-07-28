#include "temp.h"

// casting is actually just syntactic sugar, in reality we can cast any types memory to any other type's memory

// dynamic casting returns null when it fails to cast
// It runs at runtime (compiler does not preallocate the new memory to type but is calculated at run time)
// so there is an overhead

// dynamic cast is normally used for inheritance based casting***
// casting from base to child type or child type to base type

/*
    1. If we want to cast child to parent class
    its easy as child already is already associated with the parent
    (child has access to parent's scopes)

    2. If we want to cast parent to child
    here things get messy
    the parent pointer can be assigned any child, its ok
    but casting parent pointer's child2 to actual child1 is bad
    as actual child1 does not have access to the scope of child2 which will be cast onto it

    dynamic cast validates ifcmake cast is valid e.g parent pointer's child2 instance being casted to actual instance of child1
    so we get null pointer (0) when it fails
*/

class Entity{
public:
};

class Player : public Entity{
};

class Enemy : public Entity{
};

int main(void){
    Entity* objE;

    // parent type can get any type
    objE = new Player();
    // or
    objE = new Entity();

    // parent might be able to deal with this shinanigan (needs testing), here note that the enemy type is casted into player type which is completely wrong in itself...unless you know whats happening behind the hood
    objE = (Player*)(new Enemy());
    // but others cant deal with it, no one should take the wrong type from the parent
    Player *objP = (Player*)(new Enemy());
    // Dynamic casting will help prevent wrong casts

    return 0;
}