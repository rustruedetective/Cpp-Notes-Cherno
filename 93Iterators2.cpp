#include <iostream>
#include <vector>
#include <unordered_map>

// But why do we even use iterators when we can achieve similar results with index operator?
// well you can achieve same results for linear collections such as vectors, std::arrays etc
// for complex structures/collections iterator is used as index means nothing or becomes very complex to use

// e.g the unordered map is a hash table which has keys and values
// so we need to use the keys to iterate over it
// or we would need an iterator to iterate it without the keys

// 1. note we used ::const_iterator instead of simple ::iterator
// but both can be used, use the specification to find why we used this const isntead

// 2. note that we cant use it < map.end()
// we have to use it != map.end() instead

// 3. we access the pairs in map via it->first or it->second

int main(void){
    std::unordered_map<std::string, int> map;
    map["now try to guess the key hahahaha"] = 5;
    map["oops i forgot my key"] = 2;

    for(std::unordered_map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++)
        std::cout << it->first << " : " << it->second << "\n";

    for(std::unordered_map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << (*it).first << " : " << (*it).second << "\n";

    return 0;
}