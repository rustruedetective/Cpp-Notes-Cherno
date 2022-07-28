#include "temp.h"

class Entity{
    public:
        float X, Y;

        void Init(){
            X = 0.0f;
            Y = 0.0f;
        }

        void print(){
            logn(X << ", " << Y)
        }
};

int main(void){
    Entity e;
    // logn(e.X)   // If only one is called still we have garbage values
    // logn(e.X << ", " << e.Y)   // This will intitialize them to zero if all are called
    e.print();   //garbage values

    //Other way is init function
    Entity e2;
    e2.Init();
    e2.print();
    return 0;
}