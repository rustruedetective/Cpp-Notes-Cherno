#include "temp.h"

// a shinanigan to remove the get function

// we use IFloat instead of directly passing the m_randomNo because we could use IFloat, it could be modified...and it has access to other members as well

class Random{
    Random(){}
    static Random s_Instance;
    float m_randomNo = 0.5;
    float IFloat(){   // Internal Float 
        return m_randomNo;
    }
public:
    static Random& Get(){
        return s_Instance;
    }
    static float Float(){
        return Get().IFloat();
    }
    Random(const Random&) = delete;
};
Random Random::s_Instance;



int main(void){
    logn(Random::Float());

    return 0;
}