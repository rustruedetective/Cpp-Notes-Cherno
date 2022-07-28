#include <iostream>
#include <ourlib.h>

// to compile .cpp to library file use 
// gcc -c main.cpp lib.cpp

// 0. (optional) compile binary of our library
// g++ -c ./OurLib/ourlib.cpp   //beware it puts the .o in our current directory instead

// 1. header file path include
// g++ source.cpp -I ./OurLib/
// 2. lib file path include
// g++ source.cpp -I ./OurLib/ -L ./Ourlib/ -l ourlib   // does not work, damn it

// g++ source.cpp ./OurLib/ourlib.o -I ./OurLib/   // works, but then again its normal


int main(void){
    ourlib::fun();
    return 0;
}