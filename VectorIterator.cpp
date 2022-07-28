#include <iostream>
#include <vector>

// c++11 needed

int main(void){
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++){
        std::cout <<  *it << std::endl;
    }
    return 0;
}