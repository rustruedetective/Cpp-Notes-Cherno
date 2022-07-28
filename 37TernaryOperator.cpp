#include "temp.h"

static int level = 10;
static int speed = 5;

int main(void){
    if( level > 5)
        speed = 10;
    else
        speed = 5;

    // or
    speed = level > 5 ? 10 : 5;



    // this is actually different than ternary operators because this is slower!
    // here first we have declared a temporary string then destroying it immediately/reassignment
    std::string rank;
    if(level > 10)
        rank = "Master";
    else
        rank = "Beginner";

    std::string rank2 = level > 10 ? "Master" : "Beginner";




    // Nested Ternary
    speed = level > 5 ? level > 10 ? 15 : 10 : 5;
    // speed = level > 5 ? (level > 10 ? 15 : 10) : 5;   //what it looks like
    logn(speed)



    // More conditions
    speed = (level > 5 && level < 20) ? 10 : 5;

    return 0;
}