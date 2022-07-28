#include "temp.h"

// The destructor can be used to uninitialize members
// e.g the members who got memory in the heap,
// e.g member = new int; this wont automatically delete when the object goes out of scope we need to manually uninitialize this in the destructor

// For normal variables using the heap e.g those created with new also call a destructor of their own?

// You can also call the destructor manually before object is destroyed

class Entity{
    public:
        float X, Y;
        Entity(){
            X = 0.0f;
            Y = 0.0f;
        }
        ~Entity(){

        }
        void print(){
            logn(X << ", " << Y)
        }
};

int main(void){
    Entity e;
    e.~Entity();   // manually calling destructor
}