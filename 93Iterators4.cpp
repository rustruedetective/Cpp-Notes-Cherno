#include <iostream>
#include <vector>
#include <unordered_map>

// lets improve this
// 1. by using the shorter loop
// note the shorter loop does not need dereferencing, it just takes the iterator object directly

// 2. and ofcourse structured bindings c++17
// -std=c++17 needed

int main(void){
    using TempMap = std::unordered_map<std::string, int>;
    TempMap map;
    map["now try to guess the key hahahaha"] = 5;
    map["oops i forgot my key"] = 2;

    // 1.
    for(auto pair : map)
        std::cout << pair.first << " : " << pair.second << "\n";
 
    // 2.
    for(auto [key, value] : map)
        std::cout << key << " : " << value << "\n";

    return 0;
}