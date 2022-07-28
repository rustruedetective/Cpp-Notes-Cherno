#include "temp.h"

// Macros are alot of things
// Preprocessors are just one type of macros
// Here we do some preprocessors

// *Everything starting with # is a preprocessors which edit the code before passing it to the compiler
// E.g find and replace, enable or disable parts of code

// templates get made in compiler stage, here the preprocessors just edit source code's text


// Dont make code like this:-
// This is just for examples
#define RETURN return 0;
#define OPEN_CURLY {
#define CLOSE_CURLY }

int main(void)
OPEN_CURLY
    RETURN
CLOSE_CURLY