#include "temp.h"

// Hee Hee now lets overload it
// With a use case

// so...how do i access Entity's members from scoped pointer?

class Entity{
public:
    void fun(){}
};

// yeah the poiner gets deleted when object goes out of scope
class ScopedPointer{
    Entity* s_ptr;
public:
    ScopedPointer(Entity* ptr_in) : s_ptr(ptr_in) {}

    ~ScopedPointer(){ delete s_ptr; }

    // Method 1:
    Entity* getEP(){ return s_ptr; }

    // Method 2:
    Entity* operator->(){ return s_ptr; }
};

int main(void){
    // Note s_ptr here is an object
    // The Entity object is actually a pointer member of s_ptr

    // so...how do i access Entity's members?
    ScopedPointer s_ptr = new Entity();

    // Method 1:
    s_ptr.getEP()->fun();   // too messy

    // Method 2:
    s_ptr->fun();   // i dont know how? s_ptr returns address to entity object...shouldnt we need to deref that also?

    return 0;
}