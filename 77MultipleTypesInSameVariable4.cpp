#include "temp.h"
#include <variant>

// Refactoring previous episode's code

enum class ErrorCode{
    None = 0, NotFound = 1, NoAccess = 2
};

// here the int is error code for getting more info on what happened
std::variant<std::string, int> ReadFileAsString(){
    ErrorCode fileError = NotFound;
    return {};   // or "return fileError;"
}

int main(void){

    return 0;
}