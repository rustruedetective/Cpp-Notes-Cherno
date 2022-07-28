#include "temp.h"

// * the order in which you put members in the list should be the same as ur order of decaration
// As compiler ignores the list's precedence and initialization order is same as as declaration order

class Entity{
    std::string a, b, c, d, e;
public:
    Entity() : a("None"), b("None"), c("None"), d("None"), e("None")
    {

    }

    Entity(std::string ai, std::string bi, std::string ci, std::string di, std::string ei) : a(ai), b(bi), c(ci), d(di), e(di)
    {
        
    }
};

int main(void){
    
    return 0;
}