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

void print(Parent *obj){
    logn( obj->GetCLassName());
}

int main(void)
{
    Entity* e = new Entity;
    print(e);

    Player* p = new Player;
    print(p);

    Entity* e2 = p;
    print(e2);

    return 0;
}