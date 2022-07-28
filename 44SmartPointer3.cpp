#include "temp.h"
#include <memory>

// 3 Weak pointer: its just like shared pointer but it does not increase the ref count of shared pointer

// its main purpose can be to store info off all alive pointers, but dont increase their ref counts as you only want to make your own list, not alter their ref counts

// Remeber these pointers are allocated on the stack so are affected by scope!

// Where to use them? they need to be used all the time!
// Actually not all the time, but in cases where you want to allocate it like a heap memory but want it to clean itself of be bound to the scope

// Use precedence:-
// Unique pointer (lower overhead) > Shared pointer (only to share)

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
        std::weak_ptr<Entity> entityWeakPtr;
        {
            std::shared_ptr<Entity> entitySharedPtr = std::make_shared<Entity>();
            entityWeakPtr = entitySharedPtr; // ref count of entitySharedPtr not increased
            // but weak ptr does actually get a copied address of shared ptr
        }
        logn("The shared pointer is dead, the weak pointer did not increase its ref count to keep it alive")
    }

    return 0;
}