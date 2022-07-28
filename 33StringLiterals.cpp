#include "temp.h"
#include <string>
#include <cstring>   //this is where strlen is or also can use <string.h>

// string literals are anything in double quotes in cpp

// strlen is a c function for determining length of a char array

// String literals are stored in a read only area of memory****
// Some compilers lets you modify them
// But underneath the hood hey make a new char array and modify that instead

int main(void){
    "this is a string literal";

    // null character stuff
    const char str[21] = "this\0 is broken here";
    logn( strlen(str) )   // we only get 4 as the null character breaks it

    // String literals are stored in a read only area of memory, you cannot re assign values to them
    char str2[4] = "abc";
    logn( str2 )
    // str[2] = 'd';
    // logn( str2 )

    // Since string literals are read only, you cannot even assign pointers to this
    // char * ptr = "hi im billy";
    const char * ptr = "hi im billy";   // unless you specify you wont be changing anything via const

    char *ptr2 = (char*) "hi im billy";   // however if you cast it into a pointer, then ofc you can assign

    return 0;
}