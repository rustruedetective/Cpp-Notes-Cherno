#include "temp.h"

class Entity{
private:
    int x, *y;
public:
    // this method cannot modify any class member
    int getX() const{   // this only works inside a class
        // x = 30;   this wont happen as we have made the method a constant
        return x;
    }
    void setX(int inX){
        x = inX;
    }
    const int * const getY() const{   // unmodifyable data type of an unmodifiable pointer, inside a function that cant modify
        return y;
    }
};

// 1. pointer so we dont have to copy the object which is slow
// 2. const so nobody changes my object
// but the pointer to the object can be changed!
void printEntity(const Entity* e){
    e = nullptr;
    logn( e->getX() )
}

// instead if we have a reference, then we cant change
// as the reference points directly to the value
// and we have said data type is const so value cannot be changed
void printEntity2(const Entity& e){
    // e = nullptr;   // just says that the object e does not have any function of operator= overloading
    logn(e.getX())
}

int main(void){
    
    return 0;
}