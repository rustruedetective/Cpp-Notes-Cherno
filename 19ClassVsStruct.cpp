#include <iostream>
#define log(x) std::cout << x << std::endl;

// class and struct are only different in terms of the visibility
// class is by default private
// struct is by default public

// why do we need struct? if its the same as class?
// struct acts as a data structure that has variables in it
// and functions that manipulate data

// classes on the other hand have alot more functionality in them
// like interacting with the system for game input
// or creating game window etc
// here functions dont just manipulate the data within the class like in struct but do alot more

// and then inheritance is better with classes

struct a{
    int x = 10;
};

class b{
    public:
    int x = 20;
};

int main(void){
    a obj;
    b obj2;

    log(obj.x);
    log(obj2.x);
    
    return 0;
}