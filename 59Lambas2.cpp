#include "temp.h"
#include <vector>
#include <functional>

// Capture: here you capture outside variables

// but you cant use function pointer anymore, you need proper function froms stl

// and to change captured variables you need to make the lambda mutable

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func){
    for(int value: values)
        func(value);
}

int main(void){
    std::vector<int> values = {1,2,3,4,5};
    int x = 10;
    int y = 20;

    auto lambda = [=](int value){
        std::cout << "Value: " << value << std::endl;
        std::cout << "and " << x << ", " << y << std::endl;
    };
    ForEach(values, lambda);



    // mutable
    auto lambda2 = [=](int value) mutable {
        x = 1;
        y = 2;
        std::cout << "Value: " << value << std::endl;
        std::cout << "and " << x << ", " << y << std::endl;
    };
    ForEach(values, lambda2);
    return 0;
}