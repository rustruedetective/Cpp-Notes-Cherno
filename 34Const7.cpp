#include "temp.h"

// What if we want to just touch the variable anyway, without loosing the method's const property

class Entity{
private:
    int x, *y;
    mutable int z;
public:
    int getZ() const{
        z = 2;   //you can still edit this even though the method is constant
        return z;
    }
};

void printEntity(const Entity& e){
    logn(e.getZ())
}

int main(void){
    
    return 0;
}