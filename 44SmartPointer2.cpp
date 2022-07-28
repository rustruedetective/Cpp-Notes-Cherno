#include "temp.h"
#include <memory>

// 2 Shared Pointer: it can be shared
// It works by 'reference counting' and other compiler dependant shinanigans
// just like python, reference count increases whenever pointer is copied and whenever some pointer deletes it its ref count decreases

// Remeber these pointers are allocated on the stack so are affected by scope!

class Entity
{
public:
    Entity()
    {
        logn("Made Entity")
    }
    ~Entity()
    {
        logn("Destroyed Entity")
    }

    void fun() {}
};

int main(void)
{

    {
        std::shared_ptr<Entity> entitySharedPtrOutside;
        {
            // Syntax 1: this is a very unefficient way
            // std::shared_ptr<Entity> entitySharedPtr(new Entity());   // it works but dont use this

            // Syntax 2: this is efficient way
            std::shared_ptr<Entity> entitySharedPtr2 = std::make_shared<Entity>();
            logn("Ref count is 1")
            // make_shared works here, lol, bloody compiler

            // why is syntax 2 efficient?
            // when we make shared_ptr it constructs a memory block to store ref count
            // if we use syntax 1, it makes ref count memory block and constructs objects SEPERATELY which is inefficient
            // if we use syntax 2, it will make ref count memory block and construct object TOGETHERE which is fast

            // And ofcourse we can copy them
            std::shared_ptr<Entity> entitySharedPtr3 = entitySharedPtr2;
            logn("Ref count is 2")
            entitySharedPtrOutside = entitySharedPtr3;
            logn("Ref count is 3")
        }
        logn("Inner block dead but shared pointer would not be as it lives in outer block pointer")
        logn("Ref count is 1")
    }
    logn("Outer block dead and now shared pointer would be dead as now its out of scope")
    logn("Ref count is 0")
    return 0;
}