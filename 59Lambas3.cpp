#include <iostream>
#include <vector>
#include <algorithm>

// Use case:-
// Find if function of std library uses a lambda as pass in
// This is just like those javascript functions

// It returns the first element that matches condition

int main(void){
    std::vector<int> values = {1,2,3,4,5};

    auto it = std::find_if( values.begin(), values.end(), [](int value) { return value > 3; } );

    std::cout << *it << std::endl;
    
    return 0;
}