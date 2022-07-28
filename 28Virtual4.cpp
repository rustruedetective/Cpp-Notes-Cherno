#include "temp.h"

// c++11 introduce the override keyword

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

    std::string get_name() override { return Name; }
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