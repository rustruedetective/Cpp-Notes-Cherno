#include "temp.h"

// other rules
// 1. you can only let an lvalue be a reference to an lvalue and not an rvalue
// 2. but if lvalue reference is const, then it can point to an rvalue
int& GetValue(){
    static int value = 10;
    return value;
}

void SetValue(int& value){

}

int main(void){
    int i = GetValue();
    int a = i;

    // now all of a sudden its an lvalue as we can assign it stuff
    GetValue() = 2;

    // here we call the function using a lvalue
    SetValue(i);   // 1.
    // here we call the function using a rvalue
    // it wont work as we can not take rvalues ref
    // SetValue(10);   // 1.

    // 2. 
    const int& b = 10;   
    /* the compiler itself makes an int, then assigns that int to this ref:-
       int temp = 10;
       const int& b = temp;
    */

    return 0;
}