#include "temp.h"
#include <string>
#include <cstring>

// in c++11 we can use R prefix and put brackets inside string literal to get as many newlines as possible

int main(void){
    // this is more useful than the below ones
    std::string str = R"(line1
    line2
    line3)";

    // these wont be on newlines
    std::string str2 = "line1"
    "line2"
    "line3";

    // these are on newlines
    std::string str2 = "line1\n"
    "line2\n"
    "line3\n";

    return 0;
}