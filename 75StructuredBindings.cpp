#include "temp.h"
#include <tuple>

// A new way to return multiple values from functions
// How to deal with tuples, pairs or returning those things

// Cherno likes structs...
// but it changed

// this is a function with return type typle
// This reminds me of the js creating object via constructor funtion...lol
std::tuple<std::string, int> CreatePerson(){
    return {"Billy", 999};
}

int main(void){
    std::tuple<std::string, int> person = CreatePerson();
    // person.name   // now since this is not js... and we did not create an object, but a tuple we cant do this

    std::string& name = std::get<0>(person);
    int& age = std::get<1>(person);
    
    return 0;
}