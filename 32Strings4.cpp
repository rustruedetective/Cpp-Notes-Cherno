#include "temp.h"
#include <string>

// std::string::npos is a variable containing value of no position
// str.find() is a function that finds the starting position of the particular string or character

// pass by value, copy, a bad way, because it costs more memory
// and string copying is very slow
void PrintString(std::string str){
    logn(str)
}

// pass by ref, but bad way if we dont want to modify it
void PrintString2(std::string &str){
    str[0] = 'X';
    logn(str)
}

// now its pass by ref and not modifyable
void PrintString3(const std::string &str){
    logn(str)
}

int main(void){
    std::string str = "Hi There Buddy!";
    bool contains = str.find("dy") != std::string::npos;
    return 0;
}