#include "temp.h"

// We can replace the hectic code with simple static code

class Singleton{
    public:
        static Singleton & GetInst(){
            static Singleton localInstance;
            return localInstance;
        }
        void function(){
            logn("HI")
        }
};

int main(void){
    Singleton::GetInst().function();
    return 0;
}