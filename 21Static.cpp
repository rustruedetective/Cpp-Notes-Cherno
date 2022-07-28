#include <iostream>

//static: outside class/struct and inside class/struct
//inside: it will share memory with all other instances
//outside: it will only be linked to the specific translation unit it was declared in, so linker will not check for its declaration's in other code files

//(translation unit: file of code)

//Outside class/struct :-

static int s_var = 5;   //the linker will not look for s_var's declarations in other code files, only limits scope to this file

extern int x_var;   //extern means that though it was declared here, look for some other file's for this things declaration's

static void func(){}



//Summary: if we declare global vars and functions using static, the linker does not combine them in other codes
//         so we have essentially limited scope of that global var and function to the same code file (translation unit)



int main(void){

    return 0;
}