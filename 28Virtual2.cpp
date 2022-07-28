#include "temp.h"

// Virtual functions allow us to change functions in child classes

// Problem arise when we want to use the parent type with child types
// Same problem with outside function arguments
// Here since we told function we expect Entity type, even when we provide Player type it goes back to original type


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

void function(Entity* obj){
    logn( obj->get_name() )
}

int main(void)
{
    Entity* e = new Entity;
    function(e);
    
    Player* p = new Player("Bill");
    function(p);
    // Here since we told function we expect Entity type, even when we provide Player type it goes back to original type

    return 0;
}