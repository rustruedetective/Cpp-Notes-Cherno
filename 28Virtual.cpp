#include "temp.h"

// Virtual functions allow us to change functions in child classes

// Problem arise when we want to use the parent type with child types
// Now the e2 is assigned p but still it refers to its old class's function instead of the type we assigned it


class Entity
{
public:
    std::string get_name(){ return "Entity"; }
};

class Player : public Entity
{
public:
    std::string Name;

    Player(std::string name) : Name(name) {}

    std::string get_name(){ return Name; }
};

int main(void)
{
    Entity* e = new Entity;
    logn( e->get_name() )
    

    Player* p = new Player("Bill");
    logn( p->get_name() )

    // Problem here:-
    Entity* e2 = p;
    logn( e2->get_name() )
    // Now the e2 is assigned p but still it refers to its old class's function instead of the type we assigned it
    
    return 0;
}