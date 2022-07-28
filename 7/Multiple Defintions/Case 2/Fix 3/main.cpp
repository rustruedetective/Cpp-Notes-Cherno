// same issue here
// the include copies the whole header file so we have 2 defintions
// one in main other in foo

//resolve them the same way as case 1


#include "foo.h"

int main(void){
    foo();
    return 0;
}