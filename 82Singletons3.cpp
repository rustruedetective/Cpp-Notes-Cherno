#include "temp.h"

// lets make it practical
// by random no. generator example

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
    Random::Get().Float();

    return 0;
}