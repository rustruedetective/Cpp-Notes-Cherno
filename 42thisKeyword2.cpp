#include "temp.h"

// example a function being called from outside Entity but being passed the object as parameter

class Entity;   // yeah class prototype, lol

void printEnt(Entity *e);
void printEnt2(const Entity &e);

class Entity{
public:
    int x, y;

    Entity(int x, int y){
        printEnt(this);
        printEnt2(*this);
    }
};

int main(void){

    return 0;
}

void printEnt(Entity *e){}
void printEnt2(const Entity &e){}