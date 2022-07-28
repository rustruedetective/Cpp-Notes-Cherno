#include "temp.h"

void fun(){
    logn( "Function Called" )
}

void fun(int x){
    logn( "Function Called with value : " << x )
}

int main(void){
    typedef void(*FuncType)(int);

    FuncType x = fun;
    x(2);
    
    return 0;
}