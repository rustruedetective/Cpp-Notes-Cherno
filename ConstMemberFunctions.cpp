#include "temp.h"

class Entity{
    int x;
public:
    Entity() : x(0) {}
    Entity(int x_in) : x(x_in) {}
    // int get(){ return x; }   // cannot overload with below function as only return type changes dont matter
    const int get(){ return x; }
    const int get() const { return x; }   // whats the difference here?
};


int main(void){
    Entity obj = 30;
    logn( obj.get() )
    return 0;
}