#include "temp.h"
#include <vector>

// another form of functions

// When to use it?
// when you want to use a function without defining a function

// Uses Cases:-
// Passing a function to an api so it can use it later

// When you have a function pointer you can use a lambda:-
// like function pointer in definition's parameters and lambda as argument:-
void ForEach(const std::vector<int>& values, void(*func)(int)){
    for(int value: values)
        func(value);
}

// [] these are called captures
// [&] captures everything by ref, [=] captures everything by value...
// capture, captures the variables in outer scope, we can select which ones or use & or = to capture all either by ref or value

int main(void){
    std::vector<int> values = {1,2,3,4,5};

    auto lambda = [](int value){
        std::cout << "Value: " << value << std::endl;
    };

    ForEach(values, lambda);
    return 0;
}