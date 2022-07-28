#include "temp.h"

class Entity{
private:
    int x, *y;
public:
    // this method cannot modify any class member
    int getX() const{   // this only works inside a class
        // x = 30;   this wont happen as we have made the method a constant
        return x;
    }
    void setX(int inX){
        x = inX;
    }
    const int * const getY() const{   // unmodifyable data type of an unmodifiable pointer, inside a function that cant modify
        return y;
    }
};

int main(void){
    
    return 0;
}