#include <iostream>

struct Entity{
    static int x, y;

    static void Print(){
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

int main(void){
    Entity e;
    e.x = 10;
    e.y = 20;

    Entity e2;
    e2.x = 11;
    e2.y = 22;

    e.Print();
    e2.Print();
    Entity::Print();

    Entity::x = 100;
    Entity::y = 200;
    Entity::Print();
    return 0;
}