#include <iostream>
#include <vector>

void ForEach(const std::vector<int>& values, void(*func)(int)){
    for(int value: values)
        func(value);
}

int main(void){
    std::vector<int> values = {1,2,3,4,5};
    ForEach(values, [](int value){   // Lambda!!
        std::cout << "Value: " << value << std::endl;
    });
    return 0;
}