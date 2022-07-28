#include "temp.h"

// So always mark your methods const if they dont modify the data members inside it

class Entity{
private:
    int x, *y;
public:
    int getX() {
        return x;
    }
    int getX() const{
        return x;
    }
    void setX(int inX){
        x = inX;
    }
    const int * const getY() const{
        return y;
    }
};

// if we have overloaded functions, one with const and one without it would call the one with const
void printEntity(const Entity& e){
    logn(e.getX())
}

int main(void){
    
    return 0;
}