#include "temp.h"
#include <string>

// Stack based variables get destroyed when they go out of scope
// Where as heap allocated vairables stay even after scope ends

// It seems program termination does not delete heap allocated memory
// But Os takes care of it when program ends, not while its ending itself

class Entity{
    //Class scope
public:
    Entity(){
        logn("Hi")
    }
    ~Entity(){
        logn("Bye")
    }
};

int main(void){
    logn("Block scope starts")
    {
        Entity e;
    }
    logn("Block scope ends")

    logn("Block scope starts")
    {
        Entity* e = new Entity();
    }
    logn("Block scope ends")

    return 0;
}