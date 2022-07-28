#include "temp.h"

// If we dont want anyone to make an object of our class we can put construtor in private, so it would give an error anytime someone tries to create an object

class Entity{
    private:
        Entity(){}   // now no one can create objects
    public:
        static float X, Y;

        static void print(){
            logn(X << ", " << Y)
        }
};

float Entity::X = 0.0f;
float Entity::Y = 0.0f;

int main(void){
    Entity::print();

    // Entity obj;   // error
    
    return 0;
}