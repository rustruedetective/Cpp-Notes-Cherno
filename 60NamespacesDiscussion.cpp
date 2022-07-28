#include <iostream>   // i think log clashes with some other library
#include <vector>
#include <functional>
#include <algorithm>

// For:-
// 1. If you use it locally inside functions, you are good to go

void print(){
    using namespace std;
    cout << "Hi I merely print something here." << endl;
}

//Against:-
// 1. If you remove std:: by using using namespace std;
// You will have difficulty checking which thing comes from where
// e.g stl and eastl have same names, how are you going to differentiate here?



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

    auto it = std::find_if( values.begin(), values.end(), [](int value) { return value > 3; } );

    std::cout << *it << std::endl;

    return 0;
}