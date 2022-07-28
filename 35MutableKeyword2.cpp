#include "temp.h"

// Lambdas
// these lambas are just like js assigning function to a variable
// But ofc they are not the same :(
// these have much more going on under the hood

//in order to pass in parameters, we can use the particular variable in the [] brackets or & (pass by ref)
// or = (pass by value) to pass in everything outside its scope

int main(void){
    int x = 8;
    auto f = [x](){
        logn(x)
    };
    f();

    auto g = [=](){
        logn(x)
    };
    g();

    auto h = [&](){
        logn(x)
    };
    h();

    return 0;
}