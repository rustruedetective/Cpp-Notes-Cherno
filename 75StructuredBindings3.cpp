#include "temp.h"
#include <tuple>

// STructs still beat the tie thing as we can acess name and age directly

struct Person{
    std::string name;
    int age;
};

Person CreatePerson(){
    return {"Billy", 999};
}

int main(void){
    Person person = CreatePerson();
    
    logn(person.name);
    logn(person.age);
    
    return 0;
}