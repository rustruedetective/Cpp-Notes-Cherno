#include "temp.h"

class Entity{
public:
    void fun(){}
    void fun() const {}   // for const objects
};

class ScopedPointer{
    Entity* s_ptr;
public:
    ScopedPointer(Entity* ptr_in) : s_ptr(ptr_in) {}

    ~ScopedPointer(){ delete s_ptr; }

    Entity* operator->(){ return s_ptr; }
    const Entity* operator->() const { return s_ptr; }   // for const objects
};

int main(void){
    ScopedPointer s_ptr = new Entity();
    s_ptr->fun();

    const ScopedPointer s_ptr2 = new Entity();
    s_ptr2->fun();

    return 0;
}