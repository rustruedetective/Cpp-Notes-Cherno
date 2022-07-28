#include "temp.h"
#include <tuple>

// Only in c++17

// Struct binding

// lol its like js spread operator...wtf bjarne...stop copying other people

std::tuple<std::string, int> CreatePerson(){
    return {"Billy", 999};
}

int main(void){
    auto[name, age] = CreatePerson();

    logn(name)
    logn(age)

    return 0;
}