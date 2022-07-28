#include "temp.h"

// better way to get/return instance
// just make it a static member of get function
// and to make the code cleaner

// and the lifetime of the singleton becomes the lifetime of your program

class Random{
    Random(){}
    float m_randomNo = 0.5;
    float IFloat(){   // Internal Float 
        return m_randomNo;
    }
public:
    //---------------------------
    // this is the core of the singleton:-
    static Random& Get(){
        static Random instance;
        return instance;
    }
    //---------------------------
    static float Float(){
        return Get().IFloat();
    }
    Random(const Random&) = delete;
};



int main(void){
    logn(Random::Float());

    return 0;
}