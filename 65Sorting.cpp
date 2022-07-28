#include <iostream>   // log macro clashes with algorithm header
#include <vector>
#include <algorithm>   // contains std::sort

// Vector arrays and simple arrays sorting

// std::sort, this can sort over any kind of iterator
// it needs a beginning and an ending iterator and a conditional function
// n(log(n)) is time complexity

int main(void){
    std::vector<int> values = {7,3,9,1,6,4,2,};

    std::sort( values.begin(), values.end() );   // no function pointer given so sorts in ascending order

    for(int i : values)
        std::cout << i << " ";
    std::cout << "\n";

    std::sort( values.begin(), values.end() );   // no function pointer given so sorts in ascending order

    for(int i : values)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}