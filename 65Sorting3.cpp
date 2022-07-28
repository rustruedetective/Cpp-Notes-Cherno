#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Note that the a is before b
// So when the sort iterates it takes in a and b together
// a = n, b = n+1
// and swap is applied if our provided function returns (true or false i dont know lol)

int main(void){
    std::vector<int> values = {7,3,9,1,6,4,2,};

    std::sort( values.begin(), values.end(), [](int a, int b){   // the sort requires a function with int a and int b as arguments, and the condition will determine how its sorts
        if(a == 1)
            return false;
        if(b == 1)
            return true;
    
        return a < b;
    });
    for(int i : values)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}