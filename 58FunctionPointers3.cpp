#include "temp.h"

void fun(){
    logn( "Function Called" )
}

int main(void){
    // the third method of assigning variable to function
    // via typedefs:-
    typedef void(*FuncType)();

    FuncType x = fun;
    x();
    
    return 0;
}