#include "temp.h"

// The template function does not exist, until we call it in main, otherwise there is no code written for it by compiler
// Each time we call it, a function is written by the compiler catering to the particular call's type

// This is what standard template library does
// Use templates!

// e.g the syntax error is ignored because the function does not exist! (in vs compiler)
// Lol not in gcc! gcc even then detects errors
template <typename T>
void print(T x){
    logn( x )
}

int main(void){
    
    return 0;
}