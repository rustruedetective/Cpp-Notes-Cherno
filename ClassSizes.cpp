#include "temp.h"

// Sizes of normal and inherited classes

// Class size is sum of all data member sizes it has

// function variables not included

// Objects hace same size as their classes

class Entity
{
public:
    int X, Y;

    void function()
    {
        logn(X << " " << Y)
    }
};

class Player
{
public:
    int X;

    void function()
    {
        int Y;
        logn(X);
    }
};

class Player2 : public Entity
{
public:
    int X;

    void function()
    {
        logn(X);
    }
};

int main(void)
{
    Entity entity;
    Player player;
    Player2 player2;

    logn( sizeof(Entity) )
    logn( sizeof(Player) )
    logn( sizeof(Player2) )

    logn("")

    logn( sizeof(entity) )
    logn( sizeof(player) )
    logn( sizeof(player2) )

    return 0;
}