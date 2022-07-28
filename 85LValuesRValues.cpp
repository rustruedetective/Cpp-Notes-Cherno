#include "temp.h"

// l values => they are values on the left side of the equal to operator (most of the time)
// or located values
// or they can be assigned things

// r values => they are values on the right side of the equal to operator (most of the time)
// but... not all right side values are r values
// they could be result of a function
// or literals
// they are temporary

// but the above definitions are not always true

int main(void){
    // left side - i is lvalue in this case as it is assignable
    // right side - 10 is a rvalue in this case as it is a literal
    int i = 10;

    // left side - a is lvalue as its assignable
    // right side - i is also an lvalue as its still assignable...lol
    // so not always the right side values are rvalues
    int a = i;

    return 0;
}