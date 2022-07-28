#include "temp.h"

// Multi lines, the \ escapes the newline character
// e.g \n = newline but \\n = \n
// we escaped the newline character

#define MAIN(x) int main() \
{\
x;\
return 0;\
}

MAIN( logn("How are you buddy?") )