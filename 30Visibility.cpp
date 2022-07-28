#include "temp.h"

// visibility does not affect performance at all!

// struct is by default public
// class is by default private

class Entity
{
    int X, Y;
    void fun(){};
public:
    Entity(){
        X = 0;
        fun();
    };
};

class Player : public Entity
{
public:
    Player(){
        // X = 0;  //private cant be inherited
        // fun();
    }
};


int main(void){
    Entity obj;
    // obj.X = 2;  //private cant be accessed outside class
    // obj.fun();

    return 0;
}