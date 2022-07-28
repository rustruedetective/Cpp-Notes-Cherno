#include "temp.h"

// Default constructor does not initialize any primitive type

// Constructor only gets called when object is created
// When we call static methods of class, no constructor is called as no object is created

class Entity{
    public:
        float X, Y;

        Entity(){
            X = 0.0f;
            Y = 0.0f;
        }

        void print(){
            logn(X << ", " << Y)
        }
};


//Overloading constructors
class Entity2{
    public:
    int a, b;
    Entity2(){}
    Entity2(std::string x){
        logn(x)
    }
    Entity2(int x, int y){
        a=x; b=y;
    }
};

int main(void){
    Entity e;   // Constructor called
    e.print();

    return 0;
}