#include "temp.h"

// another way to use the singleton
// use this if the functions of the class only need to be used in some scope

class Random{
    Random(){}
    static Random s_Instance;
    float m_randomNo = 0.5;
public:
    static Random& Get(){
        return s_Instance;
    }
    Random(const Random&) = delete;
    float Float(){
        return m_randomNo;   // lol
    }
};
Random Random::s_Instance;



int main(void){
    auto& rand = Random::Get();
    rand.Float();

    return 0;
}