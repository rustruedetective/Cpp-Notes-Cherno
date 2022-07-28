#include "temp.h"

// returning an rvalue
// the temporary returned value is assigned to others but it iself cannot be assigned
int GetValue(){
    return 10;
}

int main(void){
    int i = GetValue();
    int a = i;

    // rvalues cannot be assigned
    // GetValue() = 2;

    return 0;
}