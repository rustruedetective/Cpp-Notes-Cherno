#include "temp.h"
#include <string>
#include <cstring>

// in c++14 we have something to postfix a string literal with that will make it add to other string literals;

int main(void){
    // wont work
    // "a" + "b";

    //works
    using namespace std::string_literals;

    "a"s + "b";

    std::string s = "a"s + "b";

    std::string s2 = u8"a"s + u8"b";
    std::string s3 = L"a"s + L"b";
    std::string s4 = U"a"s + U"b";
    std::string s5 = u"a"s + u"b";

    return 0;
}