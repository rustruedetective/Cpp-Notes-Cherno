#include "temp.h"

// Virtual functions allow us to change functions in child classes

// Fix problem with virtual functions

// Virtual functions introduce Dynamic Dispatch which is implemented by a V table

// There are two costs to the virtual function
// 1. The V table needs a memory of its own along with a pointer that points to the functions inside it so this is a storage penalty
// 2. Whenever this V table is looked up it goes through the entire table linearly so this is a performance penalty
// Although these penalties are so minute they wont even be a problem unless you are on a very shady small low performance machine

class Entity
{
public:
    virtual std::string get_name(){ return "Entity"; }
};

class Player : public Entity
{
public:
    std::string Name;

    Player(std::string name) : Name(name) {}

    std::string get_name(){ return Name; }
};

void function(Entity* obj){
    logn( obj->get_name() )
}


int main(void)
{
    Entity* e = new Entity;
    logn( e->get_name() )
    function(e);
    
    Player* p = new Player("Bill");
    logn( p->get_name() )
    function(p);   // Fixed due to virtual

    Entity* e2 = p;
    logn( e2->get_name() )   // Fixed due to virtual

    return 0;
}