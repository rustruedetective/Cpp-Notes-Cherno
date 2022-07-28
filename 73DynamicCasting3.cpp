#include "temp.h"

// 1. rtti
// the dynamic cast looks up a rtti - runtime type information
// of all variables
// this does add overhead to performance at runtime
// and rtti can be disabled in compiler... but then dynamic cast will give unpredictable results

// 2. secondly the dynamic cast also takes time when checking if the types match or are different

// so these two things are helpful but slow down performance a little bit

class Entity{
public:
    virtual void PrintName(){}
};

class Player : public Entity{
};

class Enemy : public Entity{
};

int main(void){
    Player *p  = new Player();
    Enemy  *e  = new Enemy();
    Entity *ep = p;
    Entity *ee = e;
    Player *p2 = dynamic_cast<Player*>(ee);

    // like managed languages like java and c# we can now check here as well the current object
    if(p2){
        // do stuff if pointer has some address
    }

    return 0;
}