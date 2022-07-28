#include "temp.h"

// The Player is both a Player type and a Entity type

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

int main(void){
    Player player;
    logn( player.X << " " << player.Y)

    player.Move(5, 5);
    logn( player.X << " " << player.Y)

    player.printName();
    return 0;
}