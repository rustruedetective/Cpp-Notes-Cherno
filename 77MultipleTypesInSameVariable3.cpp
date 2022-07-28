#include "temp.h"
#include <variant>

int main(void){
    // string is at index 0 and int at 1
    std::variant<std::string, int> data;
    
    // To resolve wrong type calls:-
    // 1.
    data = 2;
    if(data.index() == 0)
        logn(std::get<std::string>(data))
    else
        logn("Wrong type called")

    // 2.
    std::string* ptr = std::get_if<std::string>(&data);   // will return pointer to type or a null pointer
    logn(ptr)

    // 3. put 2 in an if...bcz the value is returned from the assigned variable
    if( std::string* ptr = std::get_if<std::string>(&data)){
        logn(*ptr)
    }

    return 0;
}