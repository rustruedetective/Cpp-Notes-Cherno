#include "temp.h"
#include <tuple>

// we could use a tie thing

std::tuple<std::string, int> CreatePerson(){
    return {"Billy", 999};
}

int main(void){
    std::string name;
    int age;
    std::tie(name, age) = CreatePerson();
    
    logn(name);
    logn(age);

    return 0;
}