#include <iostream>

//The static function inside the class/struct can only access static members and not non static members because:-

struct Entity{
    static int x, y;
    int x2, y2;

    static void PrintNonStatic(){
        // std::cout << x2 << ", " << y2 << std::endl;   //cannot do this
    }

    static void Print(){
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

//Reason:-

void PrintNonStaticOutside(){   //this is how non static member functions look in reality
    // std::cout << x << ", " << y << std::endl;
}

void PrintOutside(Entity e){   //this is how static member functions look in reality
    std::cout << e.x << ", " << e.y << std::endl;
}

int main(void){
    Entity e;
    e.x2 = 10;
    e.y2 = 20;

    e.PrintNonStatic();
    return 0;
}