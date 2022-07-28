#include <iostream>   // log macro clashes with algorithm header
#include <vector>
#include <algorithm>   // contains std::sort
#include <functional>

// functional has functions that can be provided in the sort function

// or use a lambda

int main(void){
    std::vector<int> values = {7,3,9,1,6,4,2,};

    // functional lib
    std::sort( values.begin(), values.end(), std::greater<int>() );   // shouldnt this have been a function pointer? well the functional lib's function returns some function pointer is my guess
    for(int i : values)
        std::cout << i << " ";
    std::cout << "\n";

    // lambda
    std::sort( values.begin(), values.end(), [](int a, int b){   // the sort requires a function with int a and int b as arguments, and the condition will determine how its sorts
        return a < b;   // the condition
    });
    for(int i : values)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}