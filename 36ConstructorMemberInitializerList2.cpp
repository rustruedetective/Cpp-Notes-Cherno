#include "temp.h"

// there is a reason to use these initializer lists
// it impacts performance
// e.g if the member is initialized inside the constructor the member is first constructed by default constructor, then when your constructor runs, the member is constructed again
// so we make two members for each member we constructed

// demonstrated below is what constructing two times means

class Example{
public:
    Example(){
        logn( "Created Entity" )
    }

    Example(int x){
        logn( "Created Entity with " << x)
    }
};

class Entity{
    Example obj;
public:
    Entity()
    {
        obj = Example(1);   // initializing inside constructor
    }
};

class Entity2{
    Example obj;
public:
    Entity2() : obj(2)   // initializer list
    {

    }
};
// or
class Entity3{
    Example obj;
public:
    Entity3() : obj( Example(3) )   // initializer list
    {

    }
};

int main(void){
    Entity obj;
    logn("")
    Entity2 obj2;
    Entity3 obj3;   // Another way to initialize objects
    return 0;
}