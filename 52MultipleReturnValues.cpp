#include "temp.h"
#include <array>
#include <vector>

// tuples and pairs are used
// using arrays and std::vector arrays... is ancient and not the best way

// python can return multiple types, but here we are limited to one type return

// Method 1: optimal way
void fun(int& outX, std::string& outY){
    outX = 30;
    outY = "some string";
}
void fun2(int* outX, std::string* outY){   //this is better for two reasons
    // 1. you can explicitly see they are pointer
    // 2. you can pass in null pointer or 0 when you dont want to use this
    *outX = 30;
    *outY = "some string";
}

// Method 2: heap dynamically, problem of not knowing size of returned pointer
std::string * func(){
    std::string str = "some string";
    return new std::string[1] {str};
}
std::string * func2(){
    std::string * str = new std::string[1] { "some string" };
    return str;
}

/*
   The std::array seems to take 2 instead of 1 in size
   otherwise it wont run, even though i only have 1 element
*/

// Method 3: stl array way
std::array<std::string, 2> funct(){
    std::string str = "some string";
    return std::array<std::string, 2> { str };   // need to figure out how to return and put value here
}
std::array<std::string, 2> funct2(){
    std::array<std::string, 2> arr = {"some string"};
    return arr;
}

// Method 4: stl vector way
std::vector<std::string> functi(){
    std::string str = "some string";
    return std::vector<std::string> { str };   // need to figure out how to return and put value here
}
std::vector<std::string> functi2(){
    std::vector<std::string> arr = {"some string"};
    return arr;
}

int main(void){
    // Method 1: optimal way
    int x = 0;
    std::string y = "";
    fun(x, y);
    fun2(nullptr, nullptr);   // -std=c++11

    // Method 2: heap dynamically
    std::string * str = func();
    str = func2();

    // Method 3: stl array way
    std::array<std::string, 2> arr = funct();
    arr = funct2();

    // Method 4: stl vector way
    std::vector<std::string> vec = functi();
    vec = functi2();
    return 0;
}