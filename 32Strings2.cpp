#include "temp.h"

// Ok so there is a thing called array/stack guards
// its some memory after the character array/string ends. in case we dont have a null character we would go into that array/stack guards

int main(void){
    const char array[6] = {'a', 'b', 'c'};

    // Look we have no terminating null character here
    const char array2[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

    // null termination character
    const char array3[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    const char array4[6] = {'a', 'b', 'c', 'd', 'e', 0};
        
    return 0;
}