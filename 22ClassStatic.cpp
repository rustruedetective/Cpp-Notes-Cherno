#include <iostream>

//there is only 1 instance of class's static members shared across all instances
//so the object wont change the static member for itself but for everyone

//but a static member is the same as global static variable, so why use static members?
//for oragnizational purposes
//also then each class can have the global static advantage without cluttering the global space



struct Entity{
    static int x, y;
};

int Entity::x;   //yeah the static members need to be declared outside too
int Entity::y;

int main(void){
    Entity e;
    e.x = 10;
    e.y = 20;

    // Entity e2 = {2, 5};   //this syntax can be used with structs
    Entity e2;
    e2.x = 11;
    e2.y = 22;

    std::cout << e.x << ", " << e.y << std::endl;
    std::cout << e2.x << ", " << e2.y << std::endl;

    Entity::x = 100;
    Entity::y = 200;
    std::cout << Entity::x << ", " << Entity::y << std::endl;
    return 0;
}