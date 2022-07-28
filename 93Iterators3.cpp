#include <iostream>
#include <vector>
#include <unordered_map>

// 4. we can also make the long types into using for simplicity

int main(void){
    using TempMap = std::unordered_map<std::string, int>;
    TempMap map;
    map["now try to guess the key hahahaha"] = 5;
    map["oops i forgot my key"] = 2;

    for(TempMap::const_iterator it = map.begin(); it != map.end(); it++)
        std::cout << it->first << " : " << it->second << "\n";

    return 0;
}