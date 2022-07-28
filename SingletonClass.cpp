#include "temp.h"

// Singleton class!
// A class that can have only 1 instance at a time!

// Note that the get function is static, because we want to get the static instance pointer

class Singleton{
        static Singleton* instancePtr;
    public:
        static Singleton * GetInst(){
            if(!instancePtr)
                instancePtr = new Singleton;
                return instancePtr;
        }
        void function(){
            logn("HI")
        }
};

Singleton * Singleton::instancePtr = 0;

int main(void){
    Singleton::GetInst()->function();
    return 0;
}