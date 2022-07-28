#include "temp.h"

// Since player type has entity type too, we can pass in player type where entity type was needed

class Entity{
    public:
        float X, Y;
        Entity(){
            X = Y = 0;
        }
        void Move(float xa, float ya){
            X += xa;
            Y += ya;
        }
};

class Player : public Entity{
    public:
        const char* Name;

        void printName(){
            logn( Name );
        }
};

void function(Entity obj){
    logn( obj.X << ", " << obj.Y )
}

int main(void){
    Player player;
    
    function(player);

    return 0;
}