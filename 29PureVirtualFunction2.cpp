#include "temp.h"

// c++11 introduce the override keyword

class Parent
{
    public:
        virtual std::string GetCLassName() = 0;
};

class Entity : public Parent
{
public:
    virtual std::string GetCLassName() { return "Entity"; }
};

class Player : public Entity
{
public:
    std::string GetCLassName() { return "Player"; }
};


int main(void)
{
    Entity* e = new Entity;
    logn( e->GetCLassName() )

    Player* p = new Player;
    logn( p->GetCLassName() )

    Entity* e2 = p;
    logn( e2->GetCLassName() )

    return 0;
}