#include "temp.h"

// the chad c++ way

struct returnerGuy{
    int age;
    std::string name;
};

returnerGuy fun(){
    return {10, "Billy"};   // only in c++11
}

int main(void){
    returnerGuy obj = fun();
    logn( obj.age )
    logn( obj.name )
    
    return 0;
}