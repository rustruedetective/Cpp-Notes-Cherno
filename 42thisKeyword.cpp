#include "temp.h"

// only non static member functions/methods of classes have the keyword this in them

// objects needs to be instantiated before using member/non static functions that have 'this' keyword

// 'this' is a pointer to its object (method's object)

class Entity{
public:
    int x, y;

    Entity(int x, int y){
        Entity* const e = this;
        
        e->x = x;  // same as this->x = x;
        e->y = y;  // same as this->y = y;

        //other options
        // *(this).x = x;
        // *(this).y = y;
    }

    int getx() const {
        const Entity* e = this;   // the const says we cant change the values of things the pointer points to
        const Entity& e2 = *this;
        // e = NULL;   // we can change the pointer
        // e->x = 0;   // but not the values it points to
    }
};

int main(void){

    return 0;
}