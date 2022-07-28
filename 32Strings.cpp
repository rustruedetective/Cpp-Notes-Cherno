#include "temp.h"

// wide string - 2 byte characters

// array set of elements
// string set of characters

// Dont forget the null termination character

// The double quotes make it into a char* and not directly into a string in c++

int main(void){
    // Bad way:-
    // Apparently this should work, no idea why its giving warning
    // char* name = "abc";
    // name[1] = 'x';
    // for(int i = 0; i < 3; i++)
    //     log(name[i])
    // logn("")

    // Good way:-
    // We have const for some reason
    const char* name2 = "abc";  // The double quotes make it into a char* and not directly into a string in c++
    for(int i = 0; i < 3; i++)
        log(name2[i])
        
    return 0;
}