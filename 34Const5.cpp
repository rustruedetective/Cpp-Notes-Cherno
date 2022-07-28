#include "temp.h"

class Entity{
private:
    int x, *y;
public:
    int getX() {   //if we remove this const
        return x;
    }
    void setX(int inX){
        x = inX;
    }
    const int * const getY() const{
        return y;
    }
};

// then we cant call this function, as this function says that there is no promise of the getX function keeping the data member constant
void printEntity(const Entity& e){
    // logn(e.getX())
}

int main(void){
    
    return 0;
}