#include "temp.h"
#include <variant>

int main(void){

    std::variant<std::string, int> data;
    
    // trying to access data type that was not assigned
    // the get will throw a bad variant exception
    data = 2;
    logn(std::get<std::string>(data))


    return 0;
}