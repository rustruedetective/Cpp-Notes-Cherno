#include "temp.h"

// visibility does not affect performance at all!

// It is merely there for programmer's benefit
// to make sure other's do not access variables that are not supposed to be accessed outside
// e.g critical variables on which the whole system depends
// this way there are less chances of things breaking

// e.g there is a private function in the api, which the api/library uses but you calling it would break the library

// e.g in ui we changed position of x,y of a button
// but the proper way was using setx and sety functions,
// as teh functions would automatically update the screen as well

class Entity
{
public:
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
        X = 0;  //public can be inherited
        fun();
    }
};


int main(void){
    Entity obj;
    obj.X = 2;  //pubic can be accessed outside class
    obj.fun();

    return 0;
}