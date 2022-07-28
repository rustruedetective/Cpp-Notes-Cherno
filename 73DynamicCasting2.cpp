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

    // parent pointer should not cast type2 to type1
    // these should give null
    Player *p2 = dynamic_cast<Player*>(ee);
    Enemy *e2 = dynamic_cast<Enemy*>(ep);
    logn(p2)
    logn(e2)

    // these should actually cast the parent pointer of type1 to actuall typ1
    Player *p3 = dynamic_cast<Player*>(ep);
    Enemy *e3 = dynamic_cast<Enemy*>(ee);
    logn(p3)
    logn(e3)

    return 0;
}