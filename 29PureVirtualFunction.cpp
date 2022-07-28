#include "temp.h"

// c++11 introduce the override keyword

// We use virtual functions just like interfaces in other languages
// Here we hav unimplemented base class function and derived classes will have their own implementations

class Entity
{
public:
    virtual std::string get_name() = 0;
};

class Player : public Entity
{
public:
    std::string Name;

    Player(std::string name) : Name(name) {}

    std::string get_name() override { return Name; }
};


int main(void)
{
    // Entity* e = new Entity;   //this is now impossible because we cant even make objects of abstract classes
    // logn( e->get_name() )   // this is now impossible because we cant call pure virtual functions
    
    Player* p = new Player("Bill");
    logn( p->get_name() )

    Entity* e2 = p;
    logn( e2->get_name() )   // Fixed due to virtual

    return 0;
}