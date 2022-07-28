#include "temp.h"

// What if we want to modify the passed in parameters we would have trouble

int main(void){
    int x = 8;
    auto f = [x](){   // x is passed by value
        // x++;   //we cant do this
        logn(x)
    };
    f();

    // Useless alternative
    auto g = [x](){
        int y = x;
        y++;
        logn(y)
    };
    g();

    // The manly way using mutables
    auto h = [x]() mutable{   // mutable!!!!!
        x++;
        logn(x)
    };
    h();

    logn(x)

    return 0;
}